#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

#include "header/Admin.hpp"
#include "header/Library.hpp"
#include "header/User.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::runtime_error;


void checkSameUserName(string &inputUserName) {
    string userName;
    ifstream inFS;
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

bool checkExistingUserName(const string &inputUserName) {

    ifstream inFS("username.txt");
    string username;

    if (!(inFS.is_open())) {

        throw std::runtime_error("couldn't open username.txt");

    }

    while(getline(inFS, username)) {

        if (inputUserName == username) {

            inFS.close();
            return true;

        }

    }

    inFS.close();
    return false;

}

void signin(const bool &isUser, string &inputUserName, string &passWord, string &fullName) {
    
    cout << "Please enter your username: ";
    cin >> inputUserName;
    cout << endl;

    if (!(checkExistingUserName(inputUserName))) {

        //FIXME: handle case properly when username does not exist
        throw std::runtime_error(inputUserName + "does not exist");

    }
    
    ifstream inFS;
    string filename = "users/" + inputUserName + ".txt";

    inFS.open(filename);

    if (!(inFS.is_open())) {

        throw std::runtime_error("couldn't open " + filename);
    
    }

    string burnLine = "";

    getline(inFS, burnLine);
    getline(inFS, passWord);
    getline(inFS, fullName);

    string passWordIn;
    cout << "Please enter your password: ";
    cin >> passWordIn;
    cout << endl;

    inFS.close();

    if (passWordIn == passWord) {

        cout << "Welcome back " << fullName << "!" << endl;
        cout << endl;
        return;

    }
    else {

        throw std::runtime_error("invalid password");

    }

}

void printGenre(const string &genre) {
    
    ifstream inFS;

    inFS.open("books.txt");
    if(!(inFS.is_open())) {
        throw std::runtime_error("couldn't open books.txt");
    }

    string bookLine;
    unsigned int i = 0;
    bool genreFound = false;

    while (getline(inFS, bookLine)) {
        if (inFS.bad()){

            inFS.close();
            throw std::runtime_error("error reading from books.txt");

        }

        if (bookLine.find(genre) != std::string::npos) {

            genreFound = true;
            ++i;

            cout << i << ". " << bookLine << endl;

        }

    }

    if (!genreFound) {

        throw std::runtime_error("no genres could be found");

    }

    inFS.close();

}

void editLibrary(Book genreEdit, Admin* currAdmin) {
    char userInput;
    cout << "press a to add books" << endl;
    cout << "press r to remove books" << endl;
    cout << "press e to add genres" << endl;
    cout << "press k to remove genres" << endl;
    cout << "press l to go to back to memu" << endl;
    cout << "press q to quit" << endl;

    cin >> userInput;

    if(not(cin >> userInput)) {
        throw std::runtime_error("couldn't get input");
    }

    while(true){
        if(userInput == 'a'){
            //add book
            //create a new book
            string bookName;
            getline(cin, bookName);
            if (!getline(cin, bookName)) {
                throw runtime_error("Couldn't get input.");
            }
            currAdmin->addBook(bookName);
            return;
        }
        else if (userInput == 'r'){
            //remove
            //create book to remove
            string bookName;
            getline(cin, bookName);
            if (!getline(cin, bookName)) {
                throw runtime_error("Couldn't get input.");
            }
            currAdmin->removeBook(bookName);
            return;
        }
        else if (userInput == 'e'){
            //add genre
            string genreName;
            getline(cin, genreName);
            if (!getline(cin, genreName)) {
                throw runtime_error("Couldn't get input.");
            }
            //needFixHere
            genreEdit.addGenre(genreName);
            return;
        }
        else if (userInput == 'k'){
            //remove genre
            string genreName;
            getline(cin, genreName);
            if (!getline(cin, genreName)) {
                throw runtime_error("Couldn't get input.");
            }
            //needFixHere
            genreEdit.removeGenre(genreName);
            return;
        }
        else if (userInput == 'l'){
            //go to menu
            printAdminMenu(currAdmin);
            return;
        }
        else if (userInput == 'q'){
            //quit
            return;
        }
        else{
            cout << "not a valid input option, please try again" << endl;
        }
    }

}

void printLibrary(User* currUser) {

    ifstream inFS;

    inFS.open("books.txt");
    if(!(inFS.is_open())) {
        throw std::runtime_error("couldn't open books.txt");
    }

    cout << "Here is the list of our books available:" << endl;
    string book;
    while(getline(inFS, book)) {
        cout << book << endl;
        cout << endl;
    }
    inFS.close();

    cout << "press g if you want to filter by genre" << endl;
    cout << "press r to return" << endl;

    char input;
    if(not(cin >> input)) {
        throw std::runtime_error("couldn't get input");
    }
    if (input == 'g') {

        string genre;
        cout << "Enter genre: ";
        cin >> genre;
        cout << endl;

        printGenre(genre);
    }
    if (input == 'r') {
            
        return;
        
    }

}

void borrowBook(User* currUser) {

    string bookName;
    cout << "Enter the book name: ";
    cin >> bookName;
    cout << endl;
    currUser->checkOut(bookName);

    cout << bookName << " successfully checked out." << endl;

}

void printUserMenu(User* currUser){
    char userInput;
    cout << "Welcome " << currUser->getName() << endl;

    while(true) {

        cout << "Press h to see history" << endl;
        cout << "Press b to see all books" << endl;
        cout << "Press c to check out a book" << endl;
        // cout << "Press q to log out" << endl;  FIXME: find out when to offer user to log out
        cin >> userInput;

        //if user picks b call function to show all books
        cout << endl;

        if(not(cin >> userInput)) {
            throw std::runtime_error("couldn't get input");
        }

        if(userInput == 'b') {
            printLibrary(currUser);
            return;
        }
        else if(userInput == 'h') {
            cout << currUser->readHistory();
            return;
        }
        else if(userInput == 'c') {
            borrowBook(currUser);
            return;
        }
        else{
            cout << "not a valid input option, please try again" << endl;
        }

    }

}


void printAdminMenu(Admin* currAdmin){
    char adminChoice;
    cout << "Welcome " << currAdmin->getName() << endl;
    cout << "Would you like to edit our collection" << endl;
    cout << "Type y or n" << endl;
    cin >> adminChoice;
    cout << endl;

    if(not(cin >> adminChoice)) {
        throw std::runtime_error("couldn't get input");
    }
    
    while(true){
        if(adminChoice == 'y') {
            editLibrary(genreEdit, currAdmin);
            return;
        }
        else if(adminChoice == 'n'){
            cout << "admin doesn't want to edit collection" << endl;
            return;
        }
        else{
            cout << "not a valid input option, please try again" << endl;
        }
    }
}


int main() {
    Library* newLibrary = new Library();
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


    if(signinFirstTime == "yes") {

        cout << "please enter your name" << endl;
        cin >> fullName;
        cout << endl;
        
        cout << "please enter your password" << endl;
        cin >> passWord;
        cout << endl;

        cout << "please enter a userName" << endl;
        cin >> inputUserName;
        cout << endl;

        registerFirstTime(isUser, fullName, passWord, inputUserName);
        //create user or admin object
    }
    else {
        
        signin(isUser, inputUserName, passWord, fullName);

    }

    //login process:
    if (isUser) {
        User* currUser = new User(inputUserName, passWord, newLibrary);
        currUser->setName(fullName);

        currUser->logIn();

        printUserMenu(currUser);
    }
    else if (!isUser) {
        Admin* currAdmin = new Admin(inputUserName, passWord, newLibrary);
        currAdmin->setName(fullName);

        printAdminMenu(currAdmin);
    }

}
