#include "bank.h"

Bank::Bank(){
    f_bank_name = "";
    f_bank_id = 0;
}

Bank::Bank(std::string p_bank_name, int p_bank_id){
    if(Bank::check_id(p_bank_name, p_bank_id)){
        f_bank_name = p_bank_name;
        f_bank_id = p_bank_id;
    }
}

void Bank::set_bank_name_and_id(std::string p_bank_name, int p_bank_id){
    if(Bank::check_id(p_bank_name, p_bank_id)){
        f_bank_name = p_bank_name;
        f_bank_id = p_bank_id;
    }
}

std::string Bank::get_bank_name(){
    return f_bank_name;
}

bool Bank::check_id(std::string p_bank_name, int p_bank_id){
    int START_POINT = 1212121200;
    if(p_bank_id == START_POINT + p_bank_name.size()){
        return true;
    }
}