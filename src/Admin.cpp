#include "../header/Admin.hpp"
#include <iostream>
#include <string.h>
#include "../header/User.hpp"
#include "../header/Book.hpp"
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cout;
using std::endl;

//admin have access to changes in the library
//adding/removing books will be from book/library class

/*void Admin::addBooks(const string& bookName){
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

void Admin::logIn(){

    ifstream inStream;
    string fileName = "../data/";
    fileName += username;
    inStream.open(fileName);
    string junk;
    string bookName;
    inStream >> junk;
    getline(inStream, bookName);
    while(!inStream.bad()){
        booksRead.push_back(myLibrary.findBook(bookName));
        getline(inStream, bookName);
    }
}

void Admin::logOut(){

    ofstream outStream;
    string fileName = "../data/";
    fileName += username;
    outStream.open(fileName);
    outStream << username << " " << password << " " << name << endl;
    for(Book currBook: booksRead){
        outStream << currBook.getName() << endl;
    }

}*/

