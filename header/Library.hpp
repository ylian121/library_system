#include "Book.hpp"

class Library {

 public:
    Book& findBook(const string& bookname);
    void checkOut(Book&);
    void checkIn(Book&);
};