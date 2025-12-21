# -*- coding: utf-8 -*-

from ninja import NinjaAPI

apis = NinjaAPI()
apis.add_router('books/', 'book_mgr.routes.books.router')
