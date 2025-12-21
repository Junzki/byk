# -*- coding: utf-8 -*-
import typing as ty  # noqa: F401

from django.db.models import Q
from ninja import Router
from ninja.responses import codes_4xx
from byk.schemas import ErrorMessageSchema, ERROR_OBJECT_NOT_FOUND
from book_mgr.schemas import BookSchema
from book_mgr.models import Book

router = Router()


@router.get("/", response={
    200: ty.List[BookSchema],
})
def list_books(request):
    """
    Retrieve a list of all books in the system.
    """

    books = Book.objects.select_related('location')
    return list(books)


@router.get("/{book_id}/", response={
    200: BookSchema,
    codes_4xx: ErrorMessageSchema
})
def retrieve_book(request, book_id: int | str):
    """
    Retrieve details of a specific book by its ID.
    """
    try:
        book = Book.objects.select_related('location') \
                   .filter(Q(id=book_id) | Q(isbn_number=book_id)) \
                   .get()
        return book
    except Book.DoesNotExist:
        return 404, {"message": "Book not found", "error_code": ERROR_OBJECT_NOT_FOUND}
