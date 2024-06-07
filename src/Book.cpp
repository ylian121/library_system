
#include "../header/Book.hpp"

#include <stdexcept>

using std::runtime_error;

bool Book::containsGenre(const string& genre) const{
    for(string currGenre:genres){
        if(genre == currGenre){
            return true;
        }
    }
    return false;
}

void Book::addGenre(const string& genre){
    if(!(this->containsGenre(genre)))
    {
        this->genres.push_back(genre);
    }
}

void Book::removeGenre(const string& genre){
    if(this->containsGenre(genre)){
        string currGenre;
        bool contains= true;
        for(unsigned i = 0; i+1<genres.size() && contains==true; ++i){
            currGenre = genres.at(i);
            if (currGenre==genre)
            {
                for (unsigned j = i; j+1<genres.size(); j++)
                {
                    genres.at(j) = genres.at(j+1);
                }
                contains = false;
            }
        }
        genres.pop_back();
    }
}
void Book::checkOut(){
    if(!checkedOut){
        checkedOut=true;
    }
    else{
        throw runtime_error("trying to checkout a book that has already been checked out");
    }
}
void Book::checkIn(){
    if(checkedOut){
        checkedOut=false;
    }
    else{
        throw runtime_error("trying to check in a book that has not yet been checked out");
    }
}

