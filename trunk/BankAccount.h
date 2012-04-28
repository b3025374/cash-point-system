//Pascale Vacher - March 12
//OOP Assignment Semester 2

#ifndef BankAccountH
#define BankAccountH

//---------------------------------------------------------------------------
//BankAccount: class declaration
//---------------------------------------------------------------------------

//#include "Date.h"
//#include "Transaction.h"
#include "TransactionList.h"

#include <fstream>
using namespace std;


class BankAccount {
public:
    //constructors & destructor
	BankAccount();
    BankAccount( const string& typ, const string& acctNum, const string& sCode,
                          const Date& cD, double b,
                          const TransactionList& trList);
    virtual ~BankAccount();

	//getter (assessor) functions
	const string getAccountType() const;
    const string getAccountNumber() const;
    const string getSortCode() const;
    const Date getCreationDate() const;
	double getBalance() const;
    const TransactionList getTransactions() const;
    bool	isEmptyTransactionList() const;
	void produceAllDepositTransactions(string& s, double& d);
	void produceMostRecentTransactions(const int n, string& s, double& d);
	void produceTransactionsForAmount(const double a, string& str, int& n);
	void produceTransactionsForTitle(const string title, string& str, int& n);
	void produceTransactionsForDate(const Date d, string& str, int& n);
	void produceTransactionsUpToDate(const Date d, string& str, int& i);
	void recordDeletionOfTransactionUpToDate(const Date d);

	//setters
	void setAccountType(string);
    void setAccountNumber(string);
    void setSortCode(string);
    void setCreationDate(Date);
	void setBalance(double);
    void setTransactions(TransactionList);

	//functions to put data into and get data from streams
	virtual ostream& putDataInStream( ostream& os) const;// =0;
	virtual istream& getDataFromStream( istream& is);// =0;

	//other operations
	const string prepareFormattedStatement() const;

	virtual bool canDeposit( double amount) const =0;
    void recordDeposit( double amount);

	virtual double borrowable() const = 0;
	bool canWithdraw( double amount) const;
    virtual void recordWithdrawal( double amount);

	void readInBankAccountFromFile( const string& fileName);
	void storeBankAccountInFile( const string& fileName) const;

private:
    //data items
    string accountType_;
    string accountNumber_;
    string sortCode_;
    Date   creationDate_;
	double balance_;
    TransactionList transactions_;
 
	//support functions
	void updateBalance( double amount);
	const string prepareFormattedAccountDetails() const;
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<( ostream&, const BankAccount&);	//output operator
istream& operator>>( istream&, BankAccount&);	    //input operator

#endif
