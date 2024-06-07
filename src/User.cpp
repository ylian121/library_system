#include "../header/User.hpp"
#include "../header/Book.hpp"

#include "../header/Library.hpp"



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
    myLibrary->checkout(myLibrary->getBook(bookName));
    booksOut.push_back(myLibrary->getBook(bookName));
    booksRead.push_back(myLibrary->getBook(bookName));
}

/*void User::checkIn(const string& bookName)
{
    myLibrary->checkin(myLibrary->getBook(bookName));
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
}*/

void User::recommendBooks()
{
}

void User::logIn()
{
    ifstream inStream;
    string fileName = "../users/";
    fileName = fileName + username + ".txt";
    inStream.open(fileName);

    if(!(inStream.is_open())) {
        throw std::runtime_error("couldn't open user file");
    }

    string junk;
    string bookName;
    
    getline(inStream, junk); //username
    getline(inStream, junk); //password
    getline(inStream, junk); //name

    getline(inStream, bookName); //FIXME: getline obtains whole line and not just book name 
    while(!inStream.bad() && !inStream.eof()){
        booksRead.push_back(myLibrary->getBook(bookName));
        getline(inStream, bookName);
    }
}

void User::logOut()
{
    if(booksOut.size()>0){
        throw std::runtime_error("books are still checked out");
    }
    ofstream outStream;
    string fileName = "../users/";
    fileName = fileName + username + ".txt";
    outStream.open(fileName);
    //outStream << username << " " << password << " " << name << endl; FIXME: find what this is doing?
    for(Book* currBook: booksRead){
        outStream << currBook->getName() << endl;
    }

}

void User::readHistory() {

    for (unsigned int i = 0; i < booksRead.size(); ++i) {

        cout << (i+1) << ": " << booksRead.at(i)->getName() << endl;

    }

    cout << "-----END OF BOOKS READ-----" << endl;

}