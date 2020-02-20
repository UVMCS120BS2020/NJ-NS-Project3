
#ifndef NJ_NS_PROJECT3_BRANCH_H
#define NJ_NS_PROJECT3_BRANCH_H

#include "bank.h"
#include "account.h"
#include <vector>

class Branch : public Bank{
protected:
    std::string f_branch_name;
    std::string f_branch_manager;
    std::vector<Account> f_accounts;
public:

    /* constructors */
    Branch();
    Branch(std::string p_branch_name, std::string p_branch_manager, std::vector<Account> p_accounts);
    Branch(std::string p_branch_name, std::string p_branch_manager);

    /* getters */
    std::string get_branch_name();
    std::string get_branch_manager();
    std::vector<Account> get_accounts();

    /* setters */
    void set_branch_name(std::string p_branch_name);
    void set_branch_manager(std::string p_branch_manager);
    void set_accounts(std::vector<Account> p_accounts);

    /* functions */
    void add_account(Account p_account);

};
#endif //NJ_NS_PROJECT3_BRANCH_H
