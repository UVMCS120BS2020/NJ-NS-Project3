//
// Created by barca on 2/20/2020.
//

#ifndef NJ_PROJECT3_PERSON_H
#define NJ_PROJECT3_PERSON_H

#include <string>
#include <vector>
#include <experimental/optional>
#include <iostream>

typedef std::experimental::optional<std::string> OPT_string;

class Person{
private:
    std::string f_firstName;   //changed this up to more easily incorporate a middle name
    std::string f_lastName;    //same as above
    OPT_string f_middleName;   //included this middle name as an optional because not everyone has one
    OPT_string f_prefix;
    std::string f_birthday;

public:
    Person();

    Person(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix, std::string p_birthday);

    Person(std::string p_firstName, std::string p_lastName, std::string p_birthday);

    void setName(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix);

    std::string getName();

    bool changeName(std::string p_firstName, std::string p_lastName, std::string p_middleName, std::string p_prefix);

    void setBirthday(std::string p_birthday);

    std::string getBirthday();

};

#endif //NJ_PROJECT3_PERSON_H
