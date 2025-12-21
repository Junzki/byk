# -*- coding: utf-8 -*-
import typing as ty  # noqa: F401

from ninja import ModelSchema
from .models import Book, BookStorage

class BookStorageSchema(ModelSchema):

    class Meta:
        model = BookStorage
        fields = "__all__"


class BookSchema(ModelSchema):
    location: BookStorageSchema = None

    class Meta:
        model = Book
        fields = "__all__"
