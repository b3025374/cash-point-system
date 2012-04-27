#include "CurrentAccount.h"


CurrentAccount::CurrentAccount(void)
	:overdraftLimit_(0)
{}

CurrentAccount::~CurrentAccount(void)
{}

double CurrentAccount::borrowable() const {
//return borrowable amount
    return getBalance();
}