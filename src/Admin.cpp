#include "../header/Admin.hpp"
#include <iostream>
#include <string.h>
#include "../header/User.hpp"
#include "../header/Book.hpp"
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

//admin have access to changes in the library
//adding/removing books will be from book/library class

void Admin::addBook(const string& bookName){
    Book* newBook = new Book(bookName);
    myLibrary->addBook(newBook);

    string genreIn;
    while(true) {

        cout << "Please enter the book's genre(s), one at a time (enter quit when finished): ";
        cin >> genreIn;
        cout << endl;

        if (genreIn == "quit") {

            break;
            

        }

        newBook->addGenre(genreIn);

    }

}

void Admin::removeBook(const string& bookName){
    Book* removedBook = myLibrary->getBook(bookName);
    myLibrary->remove(removedBook);
}

void Admin::addGenre(const string& bookGenre, const string& bookName){
    Book* currentBook = myLibrary->getBook(bookName);
    currentBook->addGenre(bookGenre);
}

void Admin::removeGenre(const string& bookGenre, const string& bookName){
    Book* currentBook = myLibrary->getBook(bookName);
    currentBook->removeGenre(bookGenre);
}

/*void Admin::logIn(){

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

