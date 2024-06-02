#include "../header/User.hpp"
#include "../header/Book.hpp"

#include <fstream>
#include <iostream>

using std::endl;
using std::cout;
using std::ofstream;
using std::ifstream;

void User::checkOut(const string& bookName)
{
    if (booksOut.size()== 3){
        throw std::runtime_error("you have 3 books checked out");
    }
    myLibrary->checkout(myLibrary->findBook(bookName));
    booksOut.push_back(myLibrary->findBook(bookName));
    booksRead.push_back(myLibrary->findBook(bookName));
}

void User::checkIn(const string& bookName)
{
    myLibrary->checkin(myLibrary->findBook(bookName));
    int position = -1;
    for(int i = 0; i<booksOut.size(); ++i){
        if(booksOut.at(i).getName() == bookName){
            position = i;
        }
    }
    if(position>=0){
        booksOut.at(position) = booksOut.at(booksOut.size()-1);
        booksOut.pop_back();
    }
}

void User::recommendBooks()
{
}

void User::logIn()
{
    ifstream inStream;
    string fileName = "../data/";
    fileName += username;
    inStream.open(fileName);
    string junk;
    string bookName;
    inStream >> junk;
    getline(inStream, bookName);
    while(!inStream.bad()){
        booksRead.push_back(myLibrary->findBook(bookName));
        getline(inStream, bookName);
    }
}

void User::logOut()
{
    if(booksOut.size()>0){
        throw std::runtime_error("books are still checked out");
    }
    ofstream outStream;
    string fileName = "../data/";
    fileName += username;
    outStream.open(fileName);
    outStream << username << " " << password << " " << name << endl;
    for(Book currBook: booksRead){
        outStream << currBook.getName() << endl;
    }

}

void User::readHistory() {

    for (unsigned int i = 0; i < booksRead.size(); ++i) {

        cout << (i+1) << ": " << booksRead.at(i).getName() << endl;

    }

    cout << "-----END OF BOOKS READ-----" << endl;

}