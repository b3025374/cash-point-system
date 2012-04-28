#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(void)
	:minimumBalance_(0)
{}


SavingsAccount::~SavingsAccount(void)
{}

double SavingsAccount::borrowable() const {
//return borrowable amount
    return( getBalance() - getMinimumBalance());
}

double SavingsAccount::getMinimumBalance() const {
	return minimumBalance_;
}

void SavingsAccount::setMinimumBalance(const double d) {
	minimumBalance_ = d;
}