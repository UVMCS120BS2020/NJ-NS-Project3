//
// Created by barca on 2/21/2020.
//

#include "account.h"
#include "branch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

char displayOptions(){
    char choice;
    cout << "Press n to create an account, c to see account details, a to deposit money, t to start a transfer or x to exit program: ";
    cin >> choice;
    return choice;
}

int chooseBranch(){
    char branchInt = 1;
    while(branchInt == 1 or branchInt == 2 or branchInt == 3) {
        cout << "Welcome! Choose your branch: 1 for VT, 2 for ME, 3 for NH: ";
        cin >> branchInt;
    }
    return branchInt;
}

int getAccountIndex(vector<Account> p_accountRecord, int id){
    for(int i = 0; i < p_accountRecord.size(); ++i){
        if(p_accountRecord[i].getId() == id) //changed .getId to -> getId
            return i;
    }
    return -1;
}

int fundsTransfer(Account source, Account target, double amount){
    if(amount > 0 and source.getBalance() > amount){
        source.debitAccount(amount);
        target.creditAccount(amount);
        return 0;
    }
    return 1;
}

int main(){
    Branch vermontBranch = Branch("Vermont","Nolan Jimmo");  //This is branch 1
    vermontBranch.set_bank_name_and_id("National Bank of New England", 1212121229);
    Branch maineBranch = Branch("Maine", "Noah Straqualursi");  //This is branch 2
    maineBranch.set_bank_name_and_id("National Bank of New England", 1212121229);
    Branch newHampshireBranch = Branch("New Hampshire", "Joe Jones");  //This is branch 3
    newHampshireBranch.set_bank_name_and_id("National Bank of New England", 1212121229);

    char choice;
    bool exitCall;
    int branchInt = chooseBranch();

    while (!exitCall){
        choice = displayOptions();
        if (choice == 'n') {
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
            Account newAccount = Account(firstNameTemp, lastNameTemp, middleNameTemp, prefixTemp, birthdayTemp);
            if(branchInt == 49)
                vermontBranch.add_account(newAccount);
            else if(branchInt == 50)
                maineBranch.add_account(newAccount);
            else
                newHampshireBranch.add_account(newAccount);

            //branchPoint.add_account(newAccount);
            cout << "This is your account information! Please record it for your records\n" << endl;
            newAccount.printAccountDetails(); //changed this . to an arrow because it is a pointer now

        } else if(choice == 'c'){
            int idTemp;
            int targetIndex;
            cout << "Please enter your account ID number: ";
            cin >> idTemp;
            switch (branchInt) {
                case 49: targetIndex = getAccountIndex(vermontBranch.get_accounts(), idTemp);
                    break;
                case 50: targetIndex = getAccountIndex(maineBranch.get_accounts(), idTemp);
                    break;
                case 51: targetIndex = getAccountIndex(newHampshireBranch.get_accounts(), idTemp);
                }
            //targetIndex = getAccountIndex(branchPoint.get_accounts(), idTemp);
            if (targetIndex >= 0) {
                switch (branchInt){
                    case 49: vermontBranch.get_accounts()[targetIndex].printAccountDetails();
                        break;
                    case 50: maineBranch.get_accounts()[targetIndex].printAccountDetails();
                        break;
                    case 51: newHampshireBranch.get_accounts()[targetIndex].printAccountDetails();
                }
            }
            else
                cout << "Your account could not be found \n" << endl;

        }else if(choice == 'a'){
            int idTemp;
            int targetIndex = 0;
            double creditAmount;
            bool success = true;
            cout << "Please enter your account ID number: ";
            cin >> idTemp;
            switch (branchInt){
                case 49: targetIndex = getAccountIndex(vermontBranch.get_accounts(), idTemp);
                    break;
                case 50: targetIndex = getAccountIndex(maineBranch.get_accounts(), idTemp);
                    break;
                case 51: targetIndex = getAccountIndex(newHampshireBranch.get_accounts(), idTemp);
            }
            if (targetIndex >= 0) {
                cout << "Enter the amount to be added: ";
                cin >> creditAmount;
                switch (branchInt){
                    case 49: success = vermontBranch.get_accounts()[targetIndex].creditAccount(creditAmount);
                        break;
                    case 50: targetIndex = maineBranch.get_accounts()[targetIndex].creditAccount(creditAmount);
                        break;
                    case 51: targetIndex = newHampshireBranch.get_accounts()[targetIndex].creditAccount(creditAmount);
                }
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
            int sourceIndex = 0;
            int targetIndex = 0;
            double transferAmount = 0;

            do {
                cout << "Account ID to transfer money FROM: ";
                cin >> sourceAccount;
                switch (branchInt){
                    case 49: sourceIndex = getAccountIndex(vermontBranch.get_accounts(), sourceAccount);
                        break;
                    case 50: sourceIndex = getAccountIndex(maineBranch.get_accounts(), sourceAccount);
                        break;
                    case 51: sourceIndex = getAccountIndex(newHampshireBranch.get_accounts(), sourceAccount);
                }
                if(sourceIndex < 0)
                    cout << "Account does not exist" << endl;
            } while(sourceIndex < 0);

            do {
                cout << "Account ID to transfer money TO: ";
                cin >> targetAccount;
                switch (branchInt){
                    case 49: targetIndex = getAccountIndex(vermontBranch.get_accounts(), sourceAccount);
                        break;
                    case 50: targetIndex = getAccountIndex(maineBranch.get_accounts(), sourceAccount);
                        break;
                    case 51: targetIndex = getAccountIndex(newHampshireBranch.get_accounts(), sourceAccount);
                }
                if(targetIndex < 0)
                    cout << "Account does not exist" << endl;
            } while(targetIndex < 0);

            while(transferAmount <= 0) {
                cout << "Amount to be transferred: ";
                cin >> transferAmount;
                if(transferAmount < 0)
                    cout << "Amount must be greater than 0" << endl;
            }
            int transferResponse = 0;
            switch (branchInt){
                case 49: transferResponse = fundsTransfer(vermontBranch.get_accounts()[targetIndex],  vermontBranch.get_accounts()[targetIndex], transferAmount);
                    break;
                case 50: sourceIndex = transferResponse = fundsTransfer(maineBranch.get_accounts()[targetIndex],  maineBranch.get_accounts()[targetIndex], transferAmount);
                    break;
                case 51: sourceIndex = transferResponse = fundsTransfer(newHampshireBranch.get_accounts()[targetIndex],  newHampshireBranch.get_accounts()[targetIndex], transferAmount);
            }
            if(transferResponse != 1){
                cout << "Success! Your Transfer of $" << transferAmount << " from account " << sourceAccount << " to " << targetAccount << " is completed" << endl;
            } else
                cout << "Transfer could not be completed. Insufficient funds or account not found." << endl;
        }
        else if(choice == 'x')
            exitCall = true;

    }

    return 0;
};