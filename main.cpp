#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "customer.h"
using namespace std;

void newAccount(vector<Customer>& customerList);
void deleteAccount(Customer& current, vector<Customer>& customerList);
void manageAccount(vector<Customer>& customerList, int option);

void addBalance(Customer& current);
void withdraw(Customer& current);

bool inputValidation(int& target, int low, int high);
bool passwordValid(string& password);

int main(){

    bool isActive{true};

    //initializing customers list as a vector
    vector<Customer> customerList;

    do{
        int action{};
        do{
            cout << "\nWelcome to my Bank !!!\n";
            cout << "How can I help you?\n";
            cout << "I want to open a new account(1)\n";
            cout << "I want to delete my account(2)\n";
            cout << "I want to check my account(3)\n";
            cout << "I want deposit some money(4)\n";
            cout << "I want to withdraw some money(5)\n";
            cout << "Quit(6)\n";

            cin >> action;
        //input validation
        }while(inputValidation(action, 1, 6) == true);

        switch(action){
            case 1:
                newAccount(customerList);
                break;
            case 2:
                manageAccount(customerList, 0);
                break;
            case 3:
                manageAccount(customerList, 1);
                break;
            case 4:
                manageAccount(customerList, 2);
                break;
            case 5:
                manageAccount(customerList, 3);
                break;
            case 6:
                isActive = false;
                break;
        }


    }while(isActive);

}


void newAccount(vector<Customer>& customerList){
    Customer newCustomer;
    string fname, lname;
    int age, correct;
    string password;

    //getting basic information and storing them into a Customer class
    do{
        cout << "\nWhat is your first name? \n";
        cin >> fname;
        newCustomer.setFname(fname);

        cout << "\nWhat is your last name? \n";
        cin >> lname;
        newCustomer.setLname(lname);

        do{
            cout << "\nHow old are you? \n";
            cin >> age;
        }while(inputValidation(age, 18, 100) == true);

        newCustomer.setAge(age);

        cout << "Here are your information: \n";
        newCustomer.printInformation(0);

        do{
            cout << "Is everything correct? (yes(1), no(2), quit(3)) \n";
            cin >> correct;
        }while(inputValidation(correct, 1, 3) == true);

        if(correct == 3){
            break;
        }
    }while(correct == 2);

    //generating a random card number between 100 and 500
    srand(time(nullptr));
    int cardNum = rand() % 401 + 100;

    cout << "\nHere is your card number: " << cardNum << "\n";
    newCustomer.setCardNumber(cardNum);

    newCustomer.setBalance(0);
    cout << "And your current balance is: " << newCustomer.getBalance() << "€" << endl;

    //seperate function to check if a password is valid
    do{
        cout << "Set your password:\n";
        cin >> password;
    }while(passwordValid(password) == false);

    newCustomer.setPassword(password);

    //finally pushing it into the vector
    customerList.push_back(newCustomer);
}

//function to delete an accoutn
void deleteAccount(Customer& current, vector<Customer>& customerList){

    int choice;
    do{
        cout << "Are you sure you want to delete your account?\n";
        cout << "Yes (1)\n";
        cout << "No (2)\n";
        cin >> choice;
    }while(inputValidation(choice, 1, 2) == true);

    bool found;

    //going over the customerList and deleting it
    if(choice == 1){
        for(auto it = customerList.begin(); it != customerList.end(); ++it) {
            if(it->getCardNumber() == current.getCardNumber()) {
                customerList.erase(it);
                cout << "Account deleted successfully.\n";
                return;
            }
        }
    }
}


//in manageAccount we can:
//Delete an account
//Print all information of a Customer
//Adding balance
//Withdrawing balance
void manageAccount(vector<Customer>& customerList, int option){

    int cardNumber;
    string password, problem;
    bool cardFound{true};
    bool correctPassword{true};

    do{
        cout << "What is you card number?\n";
        cin >> cardNumber;
    }while(inputValidation(cardNumber, 100, 500) == true);

    for(auto& elem : customerList){
        if(elem.getCardNumber() == cardNumber){
            cout << "Enter your password:\n";
            cin >> password;
            if(elem.getPassword() == password){
                switch(option){
                    case 0:
                        deleteAccount(elem, customerList);
                        break;
                    case 1:
                        cout << "\nHere are your details:\n";
                        elem.printInformation(1);
                        break;
                    case 2:
                        addBalance(elem);
                        break;
                    case 3:
                        withdraw(elem);
                        break;
                }
                break;
            }
            else{
                correctPassword = false;
                break;
            }
        }
        else{
            cardFound = false;
        }

    }
    if(!cardFound){
        cout << "Your card was not found.\n";
    }
    if(!correctPassword){
        cout << "Incorrect password.\n";
    }

}

//function to add balance
void addBalance(Customer& current){

    int amount;
    do{
        cout << "\nHow much do you want to add?\n";
        cin >> amount;
    }while(inputValidation(amount, 1, 1000) == true);


    current.addBalance(amount);

    cout << "Your new balance is: " << current.getBalance() << "€ " << endl;
}

//function to withdraw balance
void withdraw(Customer& current){
    int amount, currentBalance = current.getBalance();
    do{
        cout << "\nHow much do you want to withdraw?\n";
        cin >> amount;
    }while(inputValidation(amount, 1, 1000) == true);


    if(currentBalance < amount){
        cout << "Sorry, you only have this amount in your account: " << currentBalance << ". \n";
    }
    else{
        current.substractBalance(amount);
        cout << "Your new balance is: " << current.getBalance() << "€ " << endl;
    }

}

//function to check if password is valid
bool passwordValid(string& password){

    while(true){

        //checking if password has atleast 1 numberic character
        bool hasDigit{};

        for(int i = 0; i < password.length(); i++){
            if(isdigit(password[i]) == true){
                hasDigit = true;
                break;
            }
        }

        //checking if password is atleast 5 characters long
        if(password.length() < 5){
            cout << "The password must be at least 5 characters long.\n";
        }
        else if(hasDigit == false){
            cout << "The password must contain at least one digit.\n";
        }
        else{
            return true;
        }
        cin.clear();
        cin.ignore(80, '\n');
        cin >> password;
    }
}

//input validation used accross the program
bool inputValidation(int& target, int low, int high) {
    while (true) {
        if (target >= low && target <= high) {
            return false;
        }
        else {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Correct input should be in between " << low << " and " << high << ". \n";
            cin >> target;
        }
    }
}
