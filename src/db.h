

#ifndef BYK_DB_H
#define BYK_DB_H

#include <iostream>
#include <string>
#include <sqlite3.h>

namespace byk {

    const char* default_database = "byk.db";

    class db {

    public:
        ~db() {
            if (nullptr != db_) {
                sqlite3_close(db_);
            }
        };

        auto get_conn() -> sqlite3* {
            if (nullptr != this->db_)
                return db_;

            if (SQLITE_OK != sqlite3_open_v2(byk::default_database, &this->db_, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr)) {
                std::cout << __FILE__ << ": " << __LINE__ << " cannot open file: " << default_database << std::endl;
                exit(EXIT_FAILURE);
            }

            return db_;
        }

        static auto get_instance() {
            static db inner_;
            inner_.get_conn();
            inner_.create_tables();
            return inner_;
        }

        void create_tables();


    protected:
        sqlite3* db_;

    private:
        db() = default;

    };
}


#endif //BYK_DB_H
