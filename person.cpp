//
// Created by barca on 2/20/2020.
//

#include "person.h"
#include <string>

using namespace std;
using std::experimental::optional;
using std::experimental::nullopt;

Person::Person() {
    f_firstName = "";
    f_lastName = "";
    f_middleName = nullopt;
    f_prefix = nullopt;
    f_birthday = "";
}

Person::Person(string p_firstName, string p_lastName, string p_middleName, string p_prefix, string p_birthday){
    f_firstName = p_firstName;
    f_lastName = p_lastName;
    if (p_middleName == "n")
        f_middleName = nullopt;
    else
        f_middleName = p_middleName;
    if (p_prefix == "n")
        f_prefix = nullopt;
    else
        f_prefix = p_prefix;
    f_birthday = p_birthday;
}

Person::Person(string p_firstName, string p_lastName, string p_birthday){
    f_firstName = p_firstName;
    f_lastName = p_lastName;
    f_birthday = p_birthday;
}

void Person::setName(string p_firstName, string p_lastName, string p_middleName, string p_prefix){
    f_firstName = p_firstName;
    f_lastName = p_lastName;
    if (p_middleName == "n")
        f_middleName = nullopt;
    else
        f_middleName = p_middleName;
    if (p_prefix == "n")
        f_prefix = nullopt;
    else
        f_prefix = p_prefix;
}

string Person::getName(){
    string fullName;
    if(f_prefix)
        fullName = *f_prefix + " ";
    fullName += f_firstName + " ";
    if(f_middleName)
        fullName += *f_middleName + " ";
    fullName += f_lastName;
    return fullName;
}

bool Person::changeName(string p_firstName, string p_lastName, string p_middleName,string p_prefix){
    this->setName(p_firstName, p_lastName, p_middleName, p_prefix);
    return true;
}

void Person::setBirthday(std::string p_birthday){
    f_birthday = p_birthday;
}

string Person::getBirthday(){
    return f_birthday;
}
//void Person::printName(){
//
//}
