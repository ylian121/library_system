#include "book.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


Library::Library(){}

//just push to the back
void Library::addBook(const Book& book){
    bookList.push_back(book);
}

//need to find book first and then remove
void Library::remove(const Book& book){
    for(int i=0; i<bookList.size(); ++i){
        //remove all the books from the library
        while(getBookName(bookList[i]) == getBookName(book)){
            bookList.erase(bookList.begin()+i);
        }
    }
}

//use checkout and checkin from book class
void Library::checkout(const Book& book){
    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == getBookName(book)){
            book.checkout();
        }
    }
}

//use checkout and checkin from book class
void Library::checkin(const Book& book){
    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == getBookName(book)){
            book.checkin();
        }
    }
}

Book Library::findBook(const string& bookName){
    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == bookName){
            return bookList[i];
        }
    }
}

string Library::getBookName(const Book& book){
    return book.getBookName();
}