//
// Created by barca on 2/01/2020.
//

#include "account.h"
#include <string>
#include <iostream>
using namespace std;
using std::experimental::optional;
using std::experimental::nullopt;

Account::Account() {
    //setName("", "", "", "");
    f_person = Person();
    setBalance(0);
    setId(rand() % 1000 + 1);
}

Account::Account(string p_firstName, string p_lastName, string p_middleName, string p_prefix, string p_birthday) {
    f_person = Person(p_firstName, p_lastName, p_middleName, p_prefix, p_birthday);
    setBalance(0);
    setId(rand() % 1000 + 1);
}

double Account::getBalance() const {
    return f_balance;
};

void Account::setBalance(double p_balance) {
    f_balance = p_balance;
};

string Account::getPersonName() {
    return f_person.getName();
};

string Account::getPersonBirthday() {
    return f_person.getBirthday();
}

/*
void BankSystem::setName(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix) {
    //change this to set the different parts of the name. I think setting all four parts of the name in just this
    //setter will be just fine. Just have to add more params as well to incorporate those other details
    f_firstName = p_firstName;
    f_lastName = p_lastName;
    if(p_middleName == "n") {
        f_middleName = nullopt;
    }else{
        f_middleName = p_middleName;
    }
    if(p_prefix == "n") {
        f_prefix = nullopt;
    }else{
        f_prefix = p_prefix;
    }
};
 */

int Account::getId() const {
    return f_userId;
};

void Account::setId(int p_id) {
    f_userId = p_id;
};

void Account::printAccountDetails() {
    cout << "Name: " << this->getPersonName() << endl;
    cout << "Birthday: " << this->getPersonBirthday() << endl;
    cout << "ID: " << this->getId() << endl;
    cout << "Balance: " << this->getBalance() << "\n" << endl;
};

bool Account::creditAccount(double amount) {
    if (amount > 0 and amount <= 5000){
        this->setBalance(this->getBalance()+amount);
        return true;
    } else
        return false;
};

bool Account::debitAccount(double amount) {
    if (amount > 0 and this->getBalance() > amount){
        this->setBalance(this->getBalance() - amount);
        return true;
    } else
        return false;
};


bool Account::changeName(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix) {
    f_person.changeName(p_firstName, p_lastName, p_middleName, p_prefix);
    return true;
}