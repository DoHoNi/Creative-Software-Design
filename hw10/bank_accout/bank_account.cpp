

#include "bank_account.h"

unsigned int Account::ComputeExpectedBalance(unsigned int n_years_later) const
{
    return balance_*(1+interest_rate_* n_years_later);
}

unsigned int SavingAccount::ComputeExpectedBalance(unsigned int n_years_later) const
{
    double result=balance_;
    for(int i=0; i< n_years_later; i++)
    {
        result *=(1+interest_rate_);

    }
    return result;
}

Account* CreateAccount(const string& type,const string& name, unsigned int balance, double interest_rate)
{
    if(type=="checking")
    {
        Account * accountp = new Account(name, balance, interest_rate);
        return accountp;
    }
    else if(type =="saving")
    {
        Account * accountp = new SavingAccount(name, balance, interest_rate);
        return accountp;
    }
    return NULL;
}