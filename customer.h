#pragma once
#include <iostream>

class Customer{
public:

    Customer();

    void printInformation(int option);

    void setFname(std::string newFname);
    std::string getFname() const;

    void setLname(std::string newLname);
    std::string getLname() const;

    void setAge(int newAge);
    int getAge() const;

    void setCardNumber(int newCardNum);
    int getCardNumber() const;

    void addBalance(int newBalance);
    void substractBalance(int newBalance);

    void setBalance(int newBalance);
    int getBalance() const;

    void setPassword(std::string newPassword);
    std::string getPassword() const;

private:
    std::string fname;
    std::string lname;
    std::string password;
    int age;
    int cardNumber;
    int balance;
};