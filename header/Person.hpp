#pragma once

#include <string>
#include "Library.hpp"
using std::string;

class Person{
 protected:
    string username;
    string password;
    string name;
    Library &myLibrary;
 public:
    Person() : username("default"), password("Default1"), myLibrary(myLibrary){}
    Person(string user, string pass, Library &library): username(user), password(pass), myLibrary(library){}
    string getName(){
        return name;
    }
    void setName(string name){
        name = name;
    }

};