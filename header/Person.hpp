#pragma once

#include <string>

using std::string;

class Person{
 protected:
    string username;
    string password;
    string name;
 public:
    Person(){}
    Person(const string& user, const string& pass): username(user), password(pass), name(""){}
    string getName(){
        return name;
    }
    void setName(const string& name){
        this->name = name;
    }

};