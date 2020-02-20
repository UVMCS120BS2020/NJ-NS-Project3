//
// Created by barca on 2/01/2020.
//

#include "account.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//Requires: Nothing
//Modifies: Nothing, but will get user input from the choice of options within the system of banking and return the choice
//Effects: Gives options of functionality to user and returns the character denoting their choice
char displayOptions(){
    char choice;
    cout << "Press n to create an account, c to see account details, a to deposit money, t to start a transfer or x to exit program: ";
    cin >> choice;
    return choice;
};

//Requires: a copy of the accountRecord and the desired account id to be found
//Modifies: nothing
//Effects: Returns the index of the desired account within the account record so that the original record can be indexed for getting/setting method operations in the main function
int getAccountIndex(vector<shared_ptr<Account>> p_accountRecord, int id){
    for(unsigned int i = p_accountRecord.size() - 1; i > 0; --i){
        if(p_accountRecord[i] != NULL and p_accountRecord[i]->getId() == id) //changed .getId to -> getId
            return (int)i;
    }
    return -1;
}

//Requires: Requires two BankSystem "accounts", one source account for money leaving account and one target account
//for adding the money too. Also requires an amount of money to be transferred (it is a double)
//Modifies: The two account balances of each account entered as parameters
//Effects: If the source account has sufficient funds, the money will be debited from that account and credited to the
//target account and return code 0 will be returned to main. If insufficient funds, return code 1 will be returned.
int fundsTransfer(Account& source, Account& target, double amount){
    if(amount > 0 and source.getBalance() > amount){
        source.debitAccount(amount);
        target.creditAccount(amount);
        return 0;
    }
    return 1;
}

int main() {
    //create unique pointers for all of the created BankSystem accounts and store those pointers in the vector.
    //This means that less "stuff" will be in the stack memory, because we are storing pointers in the stack mem.
    //rather than the whole account information.
    vector<shared_ptr<Account>> accountRecord;  //Changed type on this vector to reflect the storing of pointers rather than
                                                   //whole objects. Make sure to check on the red squigglies below because of this change
    accountRecord.resize(10);
    char choice;
    bool exitCall;

    while (!exitCall){
        choice = displayOptions();
        if (choice == 'n') {
            //auto newAccount = make_shared<Account>(); //create this as a pointer
            //Here, create inputs for first name, prefix (optional), middle initial (optional) and last name
            //going to need new temp variables to store those
            string prefixTemp;
            string firstNameTemp;
            string middleNameTemp;
            string lastNameTemp;
            string birthdayTemp;
            cout << "Enter first name on account: ";
            cin >> firstNameTemp;
            cout << "Enter last name on account: ";
            cin >> lastNameTemp;
            cout << "Enter your middle name (press enter if no middle name): ";
            cin >> middleNameTemp;
            cout << "Enter your prefix (Mr. Mrs. etc. Enter n if no prefix): ";
            cin >> prefixTemp;
            cout << "Enter your birthday (xx/xx/xx): ";
            cin >> birthdayTemp;
            //newAccount->changeName(firstNameTemp, lastNameTemp, middleNameTemp, prefixTemp); //fixed this to have the proper params
            auto newAccount = make_shared<Account>(firstNameTemp, lastNameTemp, middleNameTemp, prefixTemp, birthdayTemp);
            accountRecord.push_back(newAccount);
            cout << "This is your account information! Please record it for your records\n" << endl;
            newAccount->printAccountDetails(); //changed this . to an arrow becuase it is a pointer now

        } else if(choice == 'c'){
            int idTemp;
            int targetIndex;
            cout << "Please enter your account ID number: ";
            cin >> idTemp;
            targetIndex = getAccountIndex(accountRecord, idTemp);
            if (targetIndex >= 0)
                accountRecord[targetIndex]->printAccountDetails(); //changed printAccountDetails to ->printAccountDetails
            else
                cout << "Your account could not be found \n" << endl;

        }else if(choice == 'a'){
            int idTemp;
            int targetIndex;
            double creditAmount;
            cout << "Please enter your account ID number: ";
            cin >> idTemp;
            targetIndex = getAccountIndex(accountRecord, idTemp);
            if (targetIndex >= 0) {
                cout << "Enter the amount to be added: ";
                cin >> creditAmount;
                bool success = accountRecord[targetIndex]->creditAccount(creditAmount);
                if (success)
                    cout << "$" << creditAmount << " has been added to the account!\n" << endl;
                else
                    cout << "We are sorry, there was a problem. Please try again.\n" << endl;
            } else{
                cout << "Your account could not be found" << endl;
            }

        }else if(choice == 't'){ //Created this new else if statement to reflect the new option to transfer money
            int sourceAccount;
            int targetAccount;
            int sourceIndex;
            int targetIndex;
            double transferAmount = 0;

            do {
                cout << "Account ID to transfer money FROM: ";
                cin >> sourceAccount;
                sourceIndex = getAccountIndex(accountRecord, sourceAccount);
                if(sourceIndex < 0)
                    cout << "Account does not exist" << endl;
            } while(sourceIndex < 0);

            do {
                cout << "Account ID to transfer money TO: ";
                cin >> targetAccount;
                targetIndex = getAccountIndex(accountRecord, targetAccount);
                if(targetIndex < 0)
                    cout << "Account does not exist" << endl;
            } while(targetIndex < 0);

            while(transferAmount <= 0) {
                cout << "Amount to be transferred: ";
                cin >> transferAmount;
                if(transferAmount < 0)
                    cout << "Amount must be greater than 0" << endl;
            }
            int transferResponse;
            transferResponse = fundsTransfer(*accountRecord[sourceIndex], *accountRecord[targetIndex], transferAmount);
            if(transferResponse != 1){
                cout << "Success! Your Transfer of $" << transferAmount << " from account " << sourceAccount << " to " << targetAccount << " is completed" << endl;
            } else
                cout << "Transfer could not be completed. Insufficient funds or account not found." << endl;
        }
        else if(choice == 'x')
            exitCall = true;

    }
};