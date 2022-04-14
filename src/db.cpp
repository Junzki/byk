

#include "byk.h"
#include "db.h"
#include "sql.h"


const char* book_table = "books";
const char* create_books =
    "CREATE TABLE IF NOT EXISTS books ( \
        id INTEGER PRIMARY KEY AUTOINCREMENT, \
        title VARCHAR(255) NOT NULL DEFAULT '',\
        author VARCHAR(255) NOT NULL DEFAULT '',\
        isbn VARCHAR(255) NULL DEFAULT NULL\
    )";


void
byk::db::create_tables() {
    char* err = nullptr;
    sqlite3_exec(this->get_conn(), create_books, nullptr, nullptr, &err);
    sqlite3_free(err);
}

std::string build_query(const std::string& column_name, const std::string& value) {
    sql::SelectModel s;
    s.select("id, title, author, isbn")
     .from(book_table)
     .where(sql::column(column_name) == value)
     .limit(1);
    return s.str();
}

byk::book*
byk::find_book(const std::string& needle, const std::string& value) {
    const auto query = build_query(needle, value);

    std::vector<byk::book*> results;

    char* errors;
    auto callback = [](void* results, int argc, char** argv, char** columns){
        auto r = (std::vector<byk::book*> *)results;

        auto* b = new byk::book{};
        b->id = atoi(argv[0]);
        b->title = std::string(argv[1]);
        b->author = std::string(argv[2]);
        b->isbn = std::string(argv[3] == nullptr ? argv[3] : "");

        r->push_back(b);
        return 0;
    };

    sqlite3_exec(byk::db::get_instance().get_conn(), query.c_str(), callback, (void *)&results, &errors);
    sqlite3_free(errors);

    if (results.empty()) {
        return nullptr;
    }

    return results[0];
}

void create_book(byk::book& b) {
    sql::InsertModel i;
    sql::Param title = ":title";
    sql::Param author = ":author";
    sql::Param isbn = ":isbn";
}
