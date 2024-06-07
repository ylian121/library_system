#include "../header/Book.hpp"
#include "../header/Library.hpp"

#include "gtest/gtest.h"

TEST(libraryTests, addBookTest){
    string anyName = "some name";
    Book myBook(anyName);
    Library lib;
    EXPECT_NO_THROW(lib.addBook(&myBook));
    EXPECT_FALSE(myBook.isCheckedOut());
}


TEST(libraryTests, remBookTest){
    string anyName = "some name";
    Book myBook(anyName);
    Library lib;
    lib.addBook(&myBook);
    EXPECT_NO_THROW(lib.remove(&myBook));
}

TEST(libraryTests, removeRemovedBookTest){
    string anyName = "some name";
    Book myBook(anyName);
    Library lib;
    lib.addBook(&myBook);
    lib.remove(&myBook);
    EXPECT_DEATH(lib.remove(&myBook), "Trying to remove a book that is not in the library");
}

TEST(libraryTests, checkOutTest){
    string anyName = "some name";
    Book myBook(anyName);
    Library lib;
    lib.addBook(&myBook);
    lib.checkout(&myBook);
    EXPECT_TRUE(myBook.isCheckedOut());
}


TEST(libraryTests, checkInTest){
    string anyName = "some name";
    Book myBook(anyName);
    Library lib;
    lib.addBook(&myBook);
    lib.checkout(&myBook);
    lib.checkin(&myBook);
    EXPECT_FALSE(myBook.isCheckedOut());
}

TEST(libraryTests, checkInTest){
    string anyName = "some name";
    Book myBook(anyName);
    Library lib;
    lib.addBook(&myBook);
    lib.checkout(&myBook);
    lib.checkin(&myBook);
    EXPECT_FALSE(myBook.isCheckedOut());
}

TEST(libraryTests, getBookTest){
    string anyName = "some name";
    Book myBook(anyName);
    Library lib;
    lib.addBook(&myBook);
    EXPECT_EQ(lib.getBook(anyName), &myBook);
}

