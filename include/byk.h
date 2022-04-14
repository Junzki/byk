#pragma once


#ifndef BYK_H
#define BYK_H

#include <iostream>
#include <string>
#include <map>

namespace byk {

    class book {
    public:
        int id;
        std::string title;
        std::string author;
        std::string isbn;
    };



    book* find_book(const std::string&, const std::string&);

    typedef book* (*finder)(const std::string&);
    inline book* find_book_by_title(const std::string& t) {
        return find_book("title", t);
    }
    inline book* find_book_by_isbn(const std::string& i) {
        return find_book("isbn", i);
    }
}


#endif // BYK_H
