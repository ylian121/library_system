#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Book{
private:
    string name;
    bool checkedOut;
    vector<string> genres;
public:
    Book(const string& name): name(name), checkedOut(false){}
    const string& getName() const
    {
        return this->name;
    }
    bool containsGenre(const string& genre) const;
    void addGenre(const string& genre);
    void removeGenre(const string& genre);
    void checkOut();
    void checkIn();
};