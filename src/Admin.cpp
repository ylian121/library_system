#include "Admin.hpp"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void Admin::addBooks(const string& bookName){
    library.addBook(Book(bookName));
}

void Admin::removeBook(const string& bookName){
    library.removeBook(Book(bookName));
}

void Admin::addGenre(const string& bookGenre){
    library.addGenre(Book(bookGenre));
}

void Admin::removeGenre(const string& bookGenre){
    library.removeGenre(Book(bookGenre));
}
