#include "../header/Book.hpp"
#include <iostream>
#include <string.h>
#include "../header/Library.hpp"

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
            return;
        }
    }

    cout << "book does not exist in library" << endl;
    cout << "check spelling and try again" << endl;
    return;

}

//use checkout and checkin from book class
void Library::checkout(Book* book){


    if(!foundBook(book->getName())){

        cout << "book not found" << endl;
        cout << "nothing to check out" << endl;
        return;
    }

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == getBookName(book)){
            //book.checkin();
            booksCheckedOut.push_back(bookList[i]);
            return;
        }
    }

    cout << "failure to check out book" << endl;
    return;

}

//use checkout and checkin from book class
void Library::checkin(Book* book){


    if(!(foundBook(book->getName()))){

        cout << "book not found" << endl;
        cout << "nothing to check out" << endl;
        return;
    }

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(booksCheckedOut[i]) == getBookName(book)){
            //book.checkin();
            booksCheckedOut.erase(booksCheckedOut.begin()+i);
            return;
        }
    }

    cout << "failure to check in book" << endl;
    return;

}


bool Library::foundBook(const string& bookName){

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == bookName){
            return true;
        }
    }

    cout << "book not found in library" << endl;
    cout << "check spelling and try again" << endl;
    return false;

}


Book* Library::getBook(const string& bookName){

    for(int i = 0; i < bookList.size(); ++i){
        if(getBookName(bookList[i]) == bookName){
            return true;
        }
    }

    cout << "book not found in library" << endl;
    cout << "check spelling and try again" << endl;
    return false;

}

book Library::getBook(const string& bookName) {
    
    for(int i = 0; i < bookList.size(); ++i){
        if(getBookName(bookList[i]) == bookName){
            return bookList[i];
        }
    }

    throw std::runtime_error(bookName + " not found"); //FIXME: handle book not found edge case

}


string Library::getBookName(Book* book){
    return book->getName();
}