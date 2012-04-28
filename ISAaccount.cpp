#include "ISAaccount.h"


ISAaccount::ISAaccount(void)
	:maximumYearlyDeposit_( 0), currentYearlyDeposit_( 0)
{
	Date temp = Date::currentDate();
	endDepositPeriod_.setDate( temp.getDay(), temp.getMonth(), temp.getYear()+1);
}

ISAaccount::~ISAaccount(void)
{}

ostream& ISAaccount::putDataInStream( ostream& os) const {
	//put (unformatted) ChildAccount details in stream
    os << getAccountType() << "\n";				//put account type
    os << getAccountNumber() << "\n";			//put account number
	os << getSortCode() << "\n";					//put sort code
    os << getCreationDate() << "\n";				//put creation date
	os << getBalance() << "\n";					//put balance
	os << getMinimumBalance() << "\n";
	os << getMaximumYearlyDeposit() << "\n";
	os << getCurrentYearlyDeposit() << "\n";
	os << getEndDepositPeriod() << "\n";
	if (  ! getTransactions().size() == 0)
		os << getTransactions();				//put all transactions, one per line
	return os;
}
istream& ISAaccount::getDataFromStream( istream& is) {
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
	is >> maximumYearlyDeposit_;			//get maximum yearly deposit
	is >> currentYearlyDeposit_;			//get current yearly deposit
	is >> endDepositPeriod_;				//get end deposit period
	is >> transactions;						//get all transactions (if any)
	setTransactions(transactions);
	return is;
}

bool ISAaccount::canDeposit( double amount) const {
	if (getCurrentYearlyDeposit()+amount <= getMaximumYearlyDeposit() 
			&& Date::currentDate() < getEndDepositPeriod())
	{
		return true;
	}
	else
		return false;
}

void ISAaccount::recordDeposit( double amountToDeposit) {
    BankAccount::recordDeposit(amountToDeposit);
	currentYearlyDeposit_ += amountToDeposit;
}

void ISAaccount::recordTransferDeposit( const string& account_details, double amountToDeposit) {
	BankAccount::recordTransferDeposit( account_details, amountToDeposit);
	currentYearlyDeposit_ += amountToDeposit;
}

//getters
double ISAaccount::getMaximumYearlyDeposit() const {
	return maximumYearlyDeposit_;
}
double ISAaccount::getCurrentYearlyDeposit() const {
	return currentYearlyDeposit_;
}
Date ISAaccount::getEndDepositPeriod() const {
	return endDepositPeriod_;
}

const string ISAaccount::prepareFormattedAccountDetails() const {
	//collect account details in string
	ostringstream os;
	//account details
	os << "\nACCOUNT TYPE:    " << getAccountType() << " ACCOUNT";						//display account type
	os << "\nACCOUNT NUMBER:  " << getAccountNumber();									//display account number
	os << "\nSORT CODE:       " << getSortCode();										//display sort code
	os << "\nCREATION DATE:   " << getCreationDate().toFormattedString();				//display creation date
	os << "\nEND OF DEPOSIT PERIOD: " << endDepositPeriod_.toFormattedString();			//display end deposit period date
	os << fixed << setprecision(2) << setfill(' ');
	os << "\nMAXIMUM YEARLY DEPOSIT: " << maximumYearlyDeposit_;	//display maximum yearly deposit
	os << "\nCURRENT YEARLY DEPOSIT: " << currentYearlyDeposit_;	//display current yearly deposit
	os << "\nBALANCE:         \234" << setw(10) << getBalance();	//display balance
	os << "\nMINIMUM BALANCE: \234" << setw(10) << getMinimumBalance();	//display minimum balance
	return ( os.str());
}