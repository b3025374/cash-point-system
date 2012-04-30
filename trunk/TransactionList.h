//Pascale Vacher - March 12
// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby
//OOP Assignment Semester 2

#ifndef TransactionListH
#define TransactionListH

//---------------------------------------------------------------------------
//TransactionList: class declaration
//---------------------------------------------------------------------------

#include "ListT.h"
#include "Transaction.h"

#include <cassert> 	// for assert()
#include <sstream>

class TransactionList {
public:

	void   addNewTransaction( const Transaction&);
    const  Transaction newestTransaction() const;
    const  TransactionList olderTransactions() const;
    void   deleteFirstTransaction();
    void   deleteGivenTransaction( const Transaction&);
	int    size() const;
	TransactionList getAllDepositTransactions() const;
	TransactionList getMostRecentTransactions(int n) const;
	TransactionList getTransactionsForAmount(const double a) const;
	TransactionList getTransactionsForTitle(const string title) const;
	TransactionList getTransactionsForDate(const Date d) const;
	TransactionList getTransactionsUpToDate(const Date d) const;
	double getTotalTransactions() const;
	int	getNumberOfTransactions() const;
	void deleteTransactionsUpToDate(const Date d);


	const string toFormattedString() const;		//return transactionlist as a (formatted) string
	ostream& putDataInStream( ostream& os) const;	//send TransactionList info into an output stream
	istream& getDataFromStream( istream& is);	//receive TransactionList info from an input stream


private:
    List<Transaction> listOfTransactions_;	//list of transactions
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<( ostream&, const TransactionList&);	//insertion operator
istream& operator>>( istream& is, TransactionList& trl); //extraction operator

#endif

