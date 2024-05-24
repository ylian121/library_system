#pragma once

#include <string>
#include <vector>
#include "Book.hpp"
#include "Library.hpp"
#include "Person.hpp"

using std::string;
using std::vector;

class Admin : public Person{
 private:
    //vector<string> book;
    //vector<string> genre;
    //connects to the library class to manage and edit the library
    //to add and remove books and genres
    //library not written yet, won't work
    Library& library;

 public:
    Admin(string user, string pass, Library& libraryAccess) : Person(user, pass), library(libraryAccess){}
    void addBooks(const string& bookName);
    void removeBook(const string& bookName);
    void addGenre(const string& bookGenre);
    void removeGenre(const string& bookGenre);
    void logIn();
    void logOut();
};