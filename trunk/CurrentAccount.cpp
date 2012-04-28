#include "CurrentAccount.h"


CurrentAccount::CurrentAccount(void)
	:overdraftLimit_(0)
{}

CurrentAccount::~CurrentAccount(void)
{}

ostream& CurrentAccount::putDataInStream( ostream& os) const {
	//put (unformatted) BankAccount details in stream
    os << getAccountType() << "\n";				//put account type
    os << getAccountNumber() << "\n";			//put account number
	os << getSortCode() << "\n";					//put sort code
    os << getCreationDate() << "\n";				//put creation date
	os << getBalance() << "\n";					//put balance
	os << getOverdraftLimit() << "\n";
	if (  ! getTransactions().size() == 0)
		os << getTransactions();				//put all transactions, one per line
	return os;
}

istream& CurrentAccount::getDataFromStream( istream& is) {
	//get BankAccount details from stream
	string accountType, accountNumber, sortCode;
	Date creationDate;
	double balance;
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
	is >> overdraftLimit_;					//get overdraftLimit
	is >> transactions;						//get all transactions (if any)
	setTransactions(transactions);
	return is;
}
bool CurrentAccount::canDeposit( double amount) const {
	return true;
}

double CurrentAccount::borrowable() const {
//return borrowable amount
    return( getBalance() + getOverdraftLimit());
}

double CurrentAccount::getOverdraftLimit() const {
	return overdraftLimit_;
}

const string CurrentAccount::prepareFormattedAccountDetails() const {
	//collect account details in string
	ostringstream os;
	//account details
	os << "\nACCOUNT TYPE:    " << getAccountType() << " ACCOUNT";						//display account type
	os << "\nACCOUNT NUMBER:  " << getAccountNumber();									//display account number
	os << "\nSORT CODE:       " << getSortCode();										//display sort code
	os << "\nCREATION DATE:   " << getCreationDate().toFormattedString();				//display creation date
	os << fixed << setprecision(2) << setfill(' ');
	os << "\nBALANCE:         \234" << setw(10) << getBalance();	//display balance
	os << "\nOVERDRAFT:       \234" << setw(10) << overdraftLimit_;	//displau overdraft
	return ( os.str());
}