#pragma once

#include "Person.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

class User: public Person{
 private:
    vector<Book> booksRead;
    vector<Book> booksOut;

 public:
    User(const string& user,const string& pass){
        this->username = user;
        this->password = pass;
        this->name = "";
    }
    void checkOut(const string& bookName);
    void checkIn(const string& bookName);
    void recommendBooks();
    void logIn();
    void logOut();

};
