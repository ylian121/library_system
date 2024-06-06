#include "../header/Book.hpp"

#include <gtest/gtest.h>

TEST(bookTests, getNameTest){
    string name = "This is the name";
    Book myBook(name);
    EXPECT_EQ(myBook.getName(), name);
}

TEST(bookTests, isCheckOutTest){
    string name = "This is the name";
    Book myBook(name);
    EXPECT_FALSE(myBook.isCheckedOut());
}

TEST(bookTests, checkOutTest){
    string name = "This is the name";
    Book myBook(name);
    myBook.checkOut();
    EXPECT_TRUE(myBook.isCheckedOut());
}

TEST(bookTests, checkOutAgainTest){
    string name = "This is the name";
    Book myBook(name);
    myBook.checkOut();
    EXPECT_DEATH(myBook.checkOut(), "trying to checkout a book that has already been checked out");
}

TEST(bookTests, isCheckInTest){
    string name = "This is the name";
    Book myBook(name);
    myBook.checkOut();
    myBook.checkIn();
    EXPECT_FALSE(myBook.isCheckedOut());
}

TEST(bookTests, checkInAgainTest){
    string name = "This is the name";
    Book myBook(name);
    myBook.checkOut();
    myBook.checkIn();
    EXPECT_DEATH(myBook.checkIn(), "trying to check in a book that has not yet been checked out");
}

TEST(bookTests, noGenres){
    string name = "This is the name";
    Book myBook(name);
    EXPECT_FALSE(myBook.containsGenre("any genre"));
}

TEST(bookTests, addGenre){
    string name = "This is the name";
    Book myBook(name);
    myBook.addGenre("any genre");
    EXPECT_TRUE(myBook.containsGenre("any genre"));
}

TEST(bookTests, addGenreFalse){
    string name = "This is the name";
    Book myBook(name);
    myBook.addGenre("any genre");
    EXPECT_FALSE(myBook.containsGenre("not any genre"));
}

TEST(bookTests, addGenreMultiple){
    string name = "This is the name";
    Book myBook(name);
    myBook.addGenre("any genre");
    myBook.addGenre("also this genre");
    EXPECT_TRUE(myBook.containsGenre("any genre"));
    EXPECT_TRUE(myBook.containsGenre("also this genre"));
}

TEST(bookTests, remGenre){
    string name = "This is the name";
    Book myBook(name);
    myBook.addGenre("any genre");
    myBook.removeGenre("any genre");
    EXPECT_FALSE(myBook.containsGenre("any genre"));
}

TEST(bookTests, remGenreMultiple){
    string name = "This is the name";
    Book myBook(name);
    myBook.addGenre("any genre");
    myBook.addGenre("also this genre");
    myBook.removeGenre("any genre");
    EXPECT_FALSE(myBook.containsGenre("any genre"));
    myBook.removeGenre("also this genre");
    EXPECT_FALSE(myBook.containsGenre("also this genre"));
}

