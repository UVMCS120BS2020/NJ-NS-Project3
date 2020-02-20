//
// Created by Noah Stracqualursi on 2/20/20.
//

#ifndef NJ_NS_PROJECT3_BANK_H
#define NJ_NS_PROJECT3_BANK_H
#include <string>

class Bank{
private:
    int f_bank_id; // 10 digit id number
    bool check_id(std::string p_bank_name, int p_bank_id);

protected:
    std::string f_bank_name; // name of bank

public:
    Bank();
    Bank(std::string p_bank_name, int p_bank_id);

    void set_bank_name_and_id(std::string p_bank_name, int p_bank_id);
    std::string get_bank_name();

};
#endif //NJ_NS_PROJECT3_BANK_H
