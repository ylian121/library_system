#pragma once

#include <string>

using std::string;

class Person{
 protected:
    string username;
    string password;
    string name;
 public:
    Person(string user, string pass): username(user), password(pass), name(""){}
    string getName(){
        return name;
    }
    void setName(string name){
        name = name;
    }

};