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
    vector<string> book;
    //connects to the library class to manage and edit the library
    //to add and remove books and genres
    //library not written yet, won't work
    Library* myLibrary;

 public:
    Admin(string user, string pass, Library* libraryAccess) : myLibrary(libraryAccess){}
    void addBook(const string& bookName);
    void removeBook(const string& bookName);
    void addGenre(const string& bookGenre, const string& bookName);
    void removeGenre(const string& bookGenre, const string& bookName);
};