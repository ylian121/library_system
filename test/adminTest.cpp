#include "../header/Book.hpp"
#include "../header/Library.hpp"
#include "../header/Admin.hpp"

#include "gtest/gtest.h"

TEST(AdminTests, constructor){
    Library myLib;
    string username = "Pmiller";
    string password = "red";
    EXPECT_NO_THROW(Admin myAdmin(username, password, &myLib));
}

TEST(AdminTests, AddingBooks){
    Library myLib;
    string username = "Pmiller";
    string password = "red";
    string name = "Pat";
    Admin myAdmin(username, password, &myLib);
    myAdmin.setName(name);
    string bookName = "someName";
    myAdmin.addBook(bookName);
    EXPECT_EQ(myLib.getBook(bookName)->getName(), bookName);
}

TEST(AdminTests, RemmingBooks){
    Library myLib;
    string username = "Pmiller";
    string password = "red";
    string name = "Pat";
    Admin myAdmin(username, password, &myLib);
    myAdmin.setName(name);
    string bookName = "someName";
    myAdmin.addBook(bookName);
    EXPECT_NO_THROW(myAdmin.removeBook(bookName));
    EXPECT_DEATH(myLib.getBook(bookName), "book not found in library");
}

TEST(AdminTests, addingGenre){
    Library myLib;
    string username = "Pmiller";
    string password = "red";
    string name = "Pat";
    Admin myAdmin(username, password, &myLib);
    myAdmin.setName(name);
    string bookName = "someName";
    string genre = "this Genre";
    myAdmin.addBook(bookName);
    myAdmin.addGenre(genre, bookName);
    EXPECT_TRUE(myLib.getBook(bookName)->containsGenre(genre));
}

TEST(AdminTests, remmingGenre){
    Library myLib;
    string username = "Pmiller";
    string password = "red";
    string name = "Pat";
    Admin myAdmin(username, password, &myLib);
    myAdmin.setName(name);
    string bookName = "someName";
    string genre = "this Genre";
    myAdmin.addBook(bookName);
    myAdmin.addGenre(genre, bookName);
    myAdmin.removeGenre(genre, bookName);
    EXPECT_FALSE(myLib.getBook(bookName)->containsGenre(genre));
}