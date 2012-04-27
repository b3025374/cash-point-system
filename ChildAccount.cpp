#include "ChildAccount.h"


ChildAccount::ChildAccount(void)
	:minimumPaidIn_(0), maximumPaidIn_(0)
{}

ChildAccount::~ChildAccount(void)
{}

ostream& ChildAccount::putDataInStream( ostream& os) const {
	//put (unformatted) ChildAccount details in stream
    os << getAccountType() << "\n";				//put account type
    os << getAccountNumber() << "\n";			//put account number
	os << getSortCode() << "\n";					//put sort code
    os << getCreationDate() << "\n";				//put creation date
	os << getBalance() << "\n";					//put balance
	os << getMinimumBalance() << "\n";
	os << getMinimumPaidIn() << "\n";
	os << getMaximumPaidIn() << "\n";
	if (  ! getTransactions().size() == 0)
		os << getTransactions();				//put all transactions, one per line
	return os;
}
istream& ChildAccount::getDataFromStream( istream& is) {
	//get ChildAccount details from stream
	string accountType, accountNumber, sortCode;
	Date creationDate;
	double balance, minBalance;
	TransactionList transactions;

    is >> accountType;						//get account type
	setAccountType(accountType);
    is >> accountNumber;					//get account number
	setAccountNumber(accountNumber);
	is >> sortCode;							//get sort code
	setSortCode(sortCode);
 	is >> creationDate;						//get creation date
	setCreationDate(creationDate);
	is >> balance;							//get balance
	setBalance(balance);
	is >> minBalance;						//get minumum balance
	setMinimumBalance(minBalance);
	is >> minimumPaidIn_;					//get maximum paid in
	is >> maximumPaidIn_;					//get minimum paid in
	is >> transactions;						//get all transactions (if any)
	setTransactions(transactions);
	return is;
}

double ChildAccount::getMinimumPaidIn() const {
	return minimumPaidIn_;
}
double ChildAccount::getMaximumPaidIn() const {
	return maximumPaidIn_;
}