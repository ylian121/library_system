#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::endl;



void registerFirstTime(bool isUser) {
    
}

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
    }
    else {
        //sign in function
    }
}
