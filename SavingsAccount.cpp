#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(void)
	:minimumBalance_(0)
{}


SavingsAccount::~SavingsAccount(void)
{}

double SavingsAccount::borrowable() const {
//return borrowable amount
    return getBalance();
}