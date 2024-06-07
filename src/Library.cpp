#include "../header/Book.hpp"
#include <iostream>
#include <string.h>
#include <stdexcept>
#include "../header/Library.hpp"

#include <cassert>

using std::cout;
using std::endl;


Library::Library(){}

//just push to the back
void Library::addBook(Book* book){
    bookList.push_back(book);
}

//need to find book first and then remove
void Library::remove(Book *book){

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == getBookName(book)){
            delete bookList[i];
            for(unsigned j = i+1; j<bookList.size(); ++j){ // need to actually remove the book from the library otherwise there will be a dangleing pointer in the vector
                bookList.at(j-1) = bookList.at(j);
            }
            bookList.pop_back();
            return;
        }
    }
    throw std::runtime_error("Trying to remove a book that is not in the library");

}

//use checkout and checkin from book class
void Library::checkout(Book* book){


    assert(foundBook(book->getName()));

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == getBookName(book)){
            bookList[i]->checkOut();
            booksCheckedOut.push_back(bookList[i]);
            return;
        }
    }

    cout << "failure to check out book" << endl;
    return;

}

//use checkout and checkin from book class
void Library::checkin(Book* book){


    assert(foundBook(book->getName()));

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(booksCheckedOut[i]) == getBookName(book)){
            booksCheckedOut[i]->checkIn();
            booksCheckedOut.erase(booksCheckedOut.begin()+i);
            return;
        }
    }

    cout << "failure to check in book" << endl;
    return;

}


Book* Library::getBook(const string& bookName){

    for(int i = 0; i < bookList.size(); ++i){
        if(getBookName(bookList[i]) == bookName){
            return bookList[i];
        }
    }

    throw std::runtime_error("book not found in library"); //FIXME: implement better handling for edge case

}


bool Library::foundBook(const string& bookName) const{

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == bookName){
            return true;
        }
    }
    return false;

}


string Library::getBookName(Book* book) const{
    return book->getName();
}