
#pragma once

#include <string>
#include<vector>
#include "Book.hpp"
#include "Library.hpp"
#include "Person.hpp"

using std::string;
using std::vector;

class Library{
 private:
    vector<Book> bookList;
    vector<Book> booksCheckedOut;

 public:
    Library();
    void addBook(const Book& book);
    void remove(const Book& book);
    void checkout(const Book& book);
    void checkin(const Book& book);
    Book findBook(const string& bookName);

private:
    //helper function to help find book
    //use from the book class to find the name
    string getBookName(const Book& book);
};