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
        if(getBookName(bookList[i]) == getBookName(book)){
            bookList.erase(bookList.begin()+i);
            return;
        }
    }

    cout << "book does not exist in library" << endl;
    cout << "check spelling and try again" << endl;
    return;

}

//use checkout and checkin from book class
void Library::checkout(const Book& book){

    if(!findBook(book)){
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
void Library::checkin(const Book& book){

    if(!findBook(book)){
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

Book Library::findBook(const string& bookName){

    for(int i=0; i<bookList.size(); ++i){
        if(getBookName(bookList[i]) == bookName){
            return bookList[i];
        }
    }

    cout << "book not found in library" << endl;
    cout << "check spelling and try again" << endl;
    return;

}

string Library::getBookName(const Book& book){
    return book.getBookName();
}