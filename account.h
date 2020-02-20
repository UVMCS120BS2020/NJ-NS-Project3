//
// Created by barca on 2/01/2020.
//

#ifndef NJ_PROJECT2_BANKSYSTEM_H
#define NJ_PROJECT2_BANKSYSTEM_H

#include <string>
#include <vector>
#include <experimental/optional>
#include "person.h"

typedef std::experimental::optional<std::string> OPT_string;

class Account{
private:
    //std::string f_firstName;   //changed this up to more easily incorporate a middle name
    //std::string f_lastName;    //same as above
    //OPT_string f_middleName;   //included this middle name as an optional because we not everyone has one
    //OPT_string f_prefix;       //included this prefix (Mr., Mrs., Ms., etc.) as an optional because we don't always have one
    Person f_person;
    int f_userId;
    double f_balance;
    int f_nameChanges = 0;
    int MAXNAMECHANGES = 4; //in reality this means they can only change the name 3 times because we will increment name change on the first change when they enter their name upon creation

    //Requires: The balance that should be set to be the new balance
    //Modifies: The balance field of the account
    //Effects: Updates balance of account
    void setBalance(double p_balance);


    //Requires: The string to be set as the name on the account
    //Modifies: The name on the account
    //Effects: Changes the name on the account
    //void setName(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix);

    //Requires: ID number to be set as accounts ID
    //Modifies: Accounts ID number
    //Effects: updates the accounts ID number
    void setId(int p_id);

    //Requires: A pointer to a transaction
    //Modifies:
    //Effects:
    //bool addTransaction(BankSystem *p_transaction);

public:
    //Requires: nothing, is a constructor
    //Modifies: balance of the newly created account so that we are sure it starts at 0
    //Effects: creates BankSystem instance
    Account();

    Account(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix, std::string p_birthday);

    //Requires: Nothing
    //Modifies: Nothing
    //Effects: Returns name of account holder
    std::string getPersonName();

    //Requires: Nothing
    //Modifies: Nothing
    //Effects: Returns Birthday of account holder
    std::string getPersonBirthday();

    //Requires: nothing
    //Modifies: nothing
    //Effects: returns the balance of the account
    double getBalance() const ;

    //Requires: Nothing
    //Modifies: Nothing
    //Effects: Returns ID number on account
    int getId() const;

    //Requires: Nothing
    //Modifies: Nothing
    //Effects: Prints the account details including name, id number and current balance
    void printAccountDetails();

    //Requires: An amount that the system is trying to add to the users account balance
    // Modifies: Potentially modifies the account balance if the checks on the amount and current balance are true
    //Effects: Adds deposit to account and returns with a boolean value indicative of if that credit was successful or not
    bool creditAccount(double p_amount);

    //Requires: An amount that the system is trying to take away from the users account balance, such as a purchase or withdrawal
    //Modifies: Potentially the account balance if there is enough money in the account to cover the purchase or withdrawal
    //Effects: Changes account balance and returns with a boolean value to indicate whether or not the debit was successful or not
    bool debitAccount(double p_amount);

    //Requires: A name that the account's name should be changed to
    //Modifies: If the accounts name has been changed less than 3 times they will be able to change it again
    //Effects: If the name has been changed more than three times it can not be changed again
    bool changeName(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix);

};


#endif //NJ_PROJECT2_BANKSYSTEM_H
