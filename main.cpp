#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::endl;



void registerFirstTime(bool isUser) {
    //first ask for name, password, and username
    //create txt file usernames, store username
    //when we get input, we read username.txt file and see if there is any matches
    //make a folder call user and admin
    //once we see there is no matches, create a new txt file called <username>.txt
    //each person's txt file is going to contain 3 things, name, password, and username
    //send those 3 things into that particular file
    
}

/*void signin(bool isUser) {
    //ask username, password
    //first check if username is actually there in the txt.file
    //if not input them to type again
    //then check <username>.txt file and see if password == input(password is 2nd line)
    //if not equal try again

}
*/
int main() {
    //Make library object

    char start;
    bool isUser = false;
    string userOrAdmin;
    string signinFirstTime;

    cout << "Press s to sign in" << endl;

    do {
        std::cin >> start;

    } while(start != 's');

    cout << "Are you a user or admin" << endl;
    
    if(not(cin >> userOrAdmin)) {
        throw std::runtime_error("could not read input");
    }
    
    if(userOrAdmin == "user") {
        isUser = true;
    }

    cout << "Are you signing in for the first time" << endl;
    if(not(cin >> signinFirstTime)) {
        throw std::runtime_error("could not read input");
    }

    if(signinFirstTime == "yes") {
        registerFirstTime(isUser);
        //create user or admin object
    }
    else {
        //sign in function
        //create user or admin object
        //login()
    }

    /*if(isUser == true) {
        //create user object
        //print usermenu...
    }*/
}
