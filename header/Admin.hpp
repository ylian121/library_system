#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Person.hpp"
#include "library.h"

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
    Admin(string, string);
    void addBooks(book, library);
    void removeBook(book, library);
    void addGenre(book, string);
    void removeGenre(book, string);
};