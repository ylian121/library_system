#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::endl;


void checkSameUserName(string &inputUserName) {
    string userName;
    std::ifstream inFS;
    inFS.open("username.txt");

    //check if file can be open
    if(!(inFS.is_open())) {
        throw std::runtime_error("couldn't open username.txt");

    }

    //read through file untill a match is found
    while(inFS >> userName) {
        //if there is a match re enter userName and call function again
        if(userName == inputUserName) {
            cout << "this user name has been taken. Please enter another." << endl;
            cin >> inputUserName;
            checkSameUserName(inputUserName);
        }
    }

    inFS.close();

    std::ofstream outFS;
    outFS.open("username.txt", std::ios::app);

    //check if userName file can be open
    if(!(outFS.is_open())) {
        throw std::runtime_error("couldn't open username.txt");
    }

    outFS << inputUserName << endl;
    outFS.close();
}

void passwordChecker(string &password) {
    if(!isalpha(password[0])) {
        cout << "Password must start with an uppercase letter. Please try again" << endl;
        cin >> password;
        passwordChecker(password);
    }
    else if(!isupper(password[0])) {
        cout << "First letter is not uppercase. Please try again" << endl;
        cin >> password;
        passwordChecker(password);
    }

    bool digitPresent = false;
    for(int i = 1; i < password.length(); ++i) {
        if (isdigit(password[i])) {
            digitPresent = true;
        }
    }

    if (digitPresent == false) {
        cout << "password must have a number in it" << endl;
        cin >> password;
        passwordChecker(password);
    }
}

void registerFirstTime(bool isUser, const string &fullName, string &passWord, string &inputUserName) {
    //first ask for name, password, and username
    //create txt file usernames, store username
    //when we get input, we read username.txt file and see if there is any matches
    //make a folder call user and admin
    //once we see there is no matches, create a new txt file called <username>.txt
    //each person's txt file is going to contain 3 things, name, password, and username
    //send those 3 things into that particular file

    //variable declaration
    string userFilePath = "users/";
    string adminFilePath = "admins/";


    //check if pass word is the same before creating txt files
    checkSameUserName(inputUserName);

    passwordChecker(passWord);


    //if the person is a user, go through the user filePath
    if(isUser == true) {
        userFilePath = userFilePath + inputUserName + ".txt";
        std::ofstream userOut(userFilePath, std::ios::app);
        
        //check if file can be open
        if(!(userOut.is_open())) {
            throw std::runtime_error("couldn't open <userName>.txt");
        }


        userOut << inputUserName << endl;
        userOut << passWord << endl;
        userOut << fullName << endl;
        userOut.close();
    }
    //if the person is an admin, go through admin filePath
    else {
        adminFilePath = adminFilePath + inputUserName + ".txt";
        std::ofstream adminOut(adminFilePath, std::ios::app);
        if(!(adminOut.is_open())) {
            throw std::runtime_error("couldn't open <userName>.txt");
        }

        adminOut << inputUserName << endl;
        adminOut << passWord << endl;
        adminOut << fullName << endl;
        adminOut.close();
    }
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
    string fullName;
    string inputUserName;
    string passWord;

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

    cout << "please enter your name" << endl;
    cin >> fullName;
    
   cout << "please enter your password. Password must start with an upper case letter and has a number." << endl;
    cin >> passWord;

    cout << "please enter a userName" << endl;
    cin >> inputUserName;

    if(signinFirstTime == "yes") {
        registerFirstTime(isUser, fullName, passWord, inputUserName);
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
