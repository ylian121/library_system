#pragma once

#include <string>
#include<vector>
#include "book.h"

using std::string;
using std::vector;

class Library{
 private:
    vector<Book> book;
    vector<string> genre;
    
 public:
    Library();
    void addBook(Book);
    void remove(Book);
    void checkout(Book);
    void checkin(Book);
    Book findBook();

};