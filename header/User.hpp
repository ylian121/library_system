#pragma once

#include "Book.hpp"
#include "Library.hpp"
#include "Person.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

class User: public Person{
 private:
    vector<Book*> booksRead;
    vector<Book*> booksOut;
    Library* myLibrary;

 public:
    User(const string& user, const string& pass, Library* library): myLibrary(library){
        this->username = user;
        this->password = pass;
        this->name = "";
        booksOut = vector<Book*>(3);
        booksRead;
    }
    void checkOut(const string& bookName);
    void checkIn(const string& bookName);
    void recommendBooks();
    string readHistory(); //uses vector booksRead to iterate through all data stored in vector and print each book
    void logIn();
    void logOut();

};