#include "customer.h"
#include <iostream>
#include <string>

Customer::Customer()
{
}

void Customer::printInformation(int option)
//case 0 = only print name and age
//case 1 = print name, age, card and balance
{
    std::cout << "\nCustomer Details: \n";
    switch(option){
        case 0:
            std::cout << "First name: " << this->getFname() << std::endl;
            std::cout << "Last name: " << this->getLname() << std::endl;
            std::cout << "Age: " << this->getAge() << std::endl;
            break;
        case 1:
            std::cout << "First name: " << this->getFname() << std::endl;
            std::cout << "Last name: " << this->getLname() << std::endl;
            std::cout << "Age: " << this->getAge() << std::endl;
            std::cout << "Card number: " << this->getCardNumber() << std::endl;
            std::cout << "Balance: " << this->getBalance() << "€" << std::endl;
            break;
    }

}

void Customer::setFname(std::string newFname)
{
    fname = newFname;
}

std::string Customer::getFname() const
{
    return fname;
}

void Customer::setLname(std::string newLname)
{
    lname = newLname;
}

std::string Customer::getLname() const
{
    return lname;
}

void Customer::setAge(int newAge)
{
    age = newAge;
}

int Customer::getAge() const
{
    return age;
}

void Customer::setCardNumber(int newCardNum)
{
    cardNumber = newCardNum;
}

int Customer::getCardNumber() const
{
    return cardNumber;
}

void Customer::addBalance(int newBalance)
{
    balance += newBalance;
}

void Customer::substractBalance(int newBalance)
{
    balance -= newBalance;
}

void Customer::setBalance(int newBalance)
{
    balance = newBalance;
}

int Customer::getBalance() const
{
    return balance;
}

void Customer::setPassword(std::string newPassword)
{
    password = newPassword;
}

std::string Customer::getPassword() const
{
    return password;
}
