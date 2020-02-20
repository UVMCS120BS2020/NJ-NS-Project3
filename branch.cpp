#include "branch.h"

/* constructors */
Branch::Branch(){
    std::string f_branch_name = "";
    std::string f_branch_manager = "";
    std::vector<Account> f_accounts = {};
}

Branch::Branch(std::string p_branch_name, std::string p_branch_manager, std::vector<Account> p_accounts){
    std::string f_branch_name = p_branch_name;
    std::string f_branch_manager = p_branch_manager;
    std::vector<Account> f_accounts = p_accounts;
}

Branch::Branch(std::string p_branch_name, std::string p_branch_manager){
    std::string f_branch_name = p_branch_name;
    std::string f_branch_manager = p_branch_manager;
    std::vector<Account> f_accounts = {};
}

/* getters */
std::string Branch::get_branch_name(){
    return f_branch_name;
}

std::string Branch::get_branch_manager(){
    return f_branch_manager;
}

std::vector<Account> Branch::get_accounts(){
    return f_accounts;
}

/* setters */
void Branch::set_branch_name(std::string p_branch_name){
    f_branch_name = p_branch_name;
}

void Branch::set_branch_manager(std::string p_branch_manager){
    f_branch_manager = p_branch_manager;
}

void Branch::set_accounts(std::vector<Account> p_accounts){
    f_accounts = p_accounts;
}

/* functions */
void Branch::add_account(Account p_account){
    f_accounts.push_back(p_account);
}

