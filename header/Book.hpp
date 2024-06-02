#pragma once

#include <string>
#include <vector>

using std::string;

class Book{
private:
    string name;
    string genre; //may need to be adjusted in the future to include multiple genres for 1 book
    bool checkedOut;

public:

    Book(): name("NO NAME"), genre("NO GENRE"), checkedOut(false) {}

    Book(const string &nameIn, const string& genreIn): name(nameIn), genre(genreIn), checkedOut(false) {}

    const string& getName() const
    {
        return this->name;
    }

    const string& getGenre() const
    {
        return this->genre;
    }

    //need to add more functions (add genre, etc)
};