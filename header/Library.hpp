#pragma once

#include <string>
#include <vector>
#include "Book.hpp"
#include "Library.hpp"
#include "Person.hpp"

using std::string;
using std::vector;

class Library{
 private:
    vector<Book*> bookList;
    vector<Book*> booksCheckedOut;

 public:
    Library();
    ~Library();
    void addBook(Book* book);
    void remove(Book* book);
    void checkout(Book* book);
    void checkin(Book* book);
    Book* getBook(const string& bookName);
    bool foundBook(const string& bookName);
private:
    //helper function to help find book
    //use from the book class to find the name
    string getBookName(Book* book);

};