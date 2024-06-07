#include "../header/Book.hpp"
#include "../header/Library.hpp"
#include "../header/User.hpp"

#include "gtest/gtest.h"

TEST(UserTests, createUser){
    string username = "username";
    string password = "password";
    string name = "name";
    Library myLib;
    EXPECT_NO_THROW(User myUser(username, password, &myLib));
}

TEST(UserTests, logInTest){
    string username = "JNeutron";
    string password = "Jdog8";
    string name = "Jimmy";
    Library myLib;
    User myUser(username, password, &myLib);
    myUser.setName(name);
    EXPECT_NO_THROW(myUser.logIn());
}

TEST(UserTests, badUsername){
    string username = "JNeutrom";
    string password = "Jdog8";
    string name = "Jimmy";
    Library myLib;
    User myUser(username, password, &myLib);
    myUser.setName(name);
    EXPECT_DEATH(myUser.logIn(), "couldn't open user file");
}

TEST(UserTests, logOut){
    string username = "JNeutron";
    string password = "Jdog8";
    string name = "Jimmy";
    Library myLib;
    User myUser(username, password, &myLib);
    myUser.setName(name);
    myUser.logIn();
    EXPECT_NO_THROW(myUser.logOut());
}

TEST(UserTests, checkOutNIn){
    string username = "hshah";
    string password = "myp4s5w0r&d";
    string name = "Haard";
    Book oneBook("Name of The Book");
    Library myLib;
    myLib.addBook(&oneBook);
    User myUser(username, password, &myLib);
    myUser.setName(name);
    myUser.logIn();
    EXPECT_NO_THROW(myUser.checkOut(oneBook.getName()));
    EXPECT_TRUE(oneBook.isCheckedOut());
    EXPECT_NO_THROW(myUser.checkIn(oneBook.getName()));
    myUser.logOut();
}

TEST(UserTests, readHistory){
    string username = "hshah";
    string password = "myp4s5w0r&d";
    string name = "Haard";
    Book oneBook("Name of The Book");
    Library myLib;
    myLib.addBook(&oneBook);
    User myUser(username, password, &myLib);
    myUser.setName(name);
    myUser.logIn();
    EXPECT_EQ(myUser.readHistory(), "1: Name of The Book\n-----END OF BOOKS READ-----\n");
    myUser.logOut();
}