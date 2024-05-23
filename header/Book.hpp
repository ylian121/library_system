#pragma once

#include <string>

using std::string;

class Book{
private:
    string name;
public:
    const string& getName() const
    {
        return this->name;
    }
};