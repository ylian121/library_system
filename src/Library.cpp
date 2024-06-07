#include "../header/Book.hpp"
#include "../header/Library.hpp"

#include <iostream>
#include <fstream>
#include <string.h>
#inlude <stdexcept>

using std::cout;
using std::endl;


Library::Library(){

    loadBooksFromFile("books.txt");

}

void Library::loadBooksFromFile(const string& filename) {

    std::ifstream inFS(filename);

    if (!(inFS.is_open())) {

        throw std::runtime_error("Unable to open file: " + filename);

        string lineIn;
        while (std::getline(inFS, lineIn)) {

            std::istringstream stream(line);
            string bookTitle;
            string by;
            string author;
            string genres;

            std::getline(stream, bookTitle, ' ');
            std::getline(stream, by, ' ');
            std::getline(stream, author, ' ');
            std::getline(stream, genres, ' ');

            Book* currBook = new Book(bookTitle);

            std::istringstream genresStream(genres);
            string genre;

            while (std::getline(genresStream, genre, ',')) {

                currBook->addGenre(genre);

            }

            addBook(currBook);
        }

        inFS.close();
    }
}

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
            return bookList[i];
        }
    }

    throw std::runtime_error("book not found in library"); //FIXME: implement better handling for edge case

}

string Library::getBookName(Book* book){
    return book->getName();
}