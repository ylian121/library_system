#pragma once

#include <string>
#include "Library.hpp"
using std::string;

class Person{
 protected:
    string username;
    string password;
    string name;
 public:
    Person() : username("default"), password("Default1"){}
    Person(string user, string pass): username(user), password(pass){}
    string getName(){
        return name;
    }
    void setName(string name){
        name = name;
    }

};