# -*- coding: utf-8 -*-
import typing as ty  # noqa: F401

import logging

from django.db import transaction
from byk.task_broker import broker
from book_mgr.models import Book, Tag

LOG = logging.getLogger("book_mgr")

@broker.subscriber("book_mgr.fetch_books")
def fetch_books_task(pk: int) -> None:
    from book_mgr.providers.book_meta import BookMetaProvider

    ins = Book.objects.get(pk=pk)

    provider = BookMetaProvider()
    book_meta = provider.find_book_by_isbn(ins.isbn_number)
    if not book_meta:
        return

    tags = list()

    with transaction.atomic():
        for tag_name in book_meta.tags:
            tag_, _ = Tag.objects.get_or_create(name=tag_name)
            tags.append(tag_)

        ins.title = book_meta.title
        ins.author = ', '.join(book_meta.authors)
        ins.published_date = book_meta.published_date or ins.published_date
        ins.comments = book_meta.description or ins.comments
        ins.save()
        ins.tags.add(*tags)

    LOG.info("Fetched and updated book metadata for Book ID: %s", pk)
