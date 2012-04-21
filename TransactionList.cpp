//Pascale Vacher - March 12
//OOP Assignment Semester 2

#include "TransactionList.h"

//---------------------------------------------------------------------------
//TransactionList: class implementation
//---------------------------------------------------------------------------

//____public member functions

//____constructors & destructors

//____other public member functions

void TransactionList::addNewTransaction( const Transaction& tr) {
    listOfTransactions_.addInFront( tr);
}
const Transaction TransactionList::newestTransaction() const {
    return (listOfTransactions_.first());
}
const TransactionList TransactionList::olderTransactions() const {
	TransactionList trlist( *this);
    trlist.deleteFirstTransaction();
    return trlist;
}
void TransactionList::deleteFirstTransaction() {
    listOfTransactions_.deleteFirst();
}
void TransactionList::deleteGivenTransaction( const Transaction& tr) {
    listOfTransactions_.deleteOne( tr);
}
int TransactionList::size() const {
    return (listOfTransactions_.length());
}

const string TransactionList::toFormattedString() const {
//return transaction list as a (formatted) string
	ostringstream os_transactionlist;
    TransactionList tempTrList( *this);
	while ( ! ( tempTrList.size() == 0))
    {
		os_transactionlist << tempTrList.newestTransaction().toFormattedString() << endl;
        tempTrList.deleteFirstTransaction();
    }
	return ( os_transactionlist.str());
}

ostream& TransactionList::putDataInStream( ostream& os) const {
//put (unformatted) transaction list into an output stream
    TransactionList tempTrList( *this);
	while ( ! ( tempTrList.size() == 0))
    {
		os << tempTrList.newestTransaction() << endl;
        tempTrList.deleteFirstTransaction();
    }
	return os;
}
istream& TransactionList::getDataFromStream( istream& is) {
//read in (unformatted) transaction list from input stream
	Transaction aTransaction;
	is >> aTransaction;	//read first transaction
	while ( is != 0) 	//while not end of file
	{
		listOfTransactions_.addAtEnd( aTransaction);   //add transaction to list of transactions
		is >> aTransaction;	//read in next transaction
	}
	return is;
}

TransactionList TransactionList::getAllDepositTransactions() const {
	TransactionList deposits;
	TransactionList copy(*this);
	Transaction temp;

	for(int i(0); i < size(); i++) {
		temp = copy.newestTransaction();
		if(temp.getAmount() > 0)
			deposits.addNewTransaction(temp);
		copy.deleteFirstTransaction();
	}
	return deposits;
}
TransactionList TransactionList::getMostRecentTransactions(int n) const{
	TransactionList trl;
	TransactionList copy(*this);
	Transaction temp;

	if (n < size()) // If there are more availiable transaction than requested
	{				// produce a list of them
		for(int i(0); i < n; i++) {
			trl.addNewTransaction(copy.newestTransaction());
			copy.deleteFirstTransaction();
		}
	} else { //else get all availiable and display how many
		for(int i(0); i < size(); i++) {
			trl.addNewTransaction(copy.newestTransaction());
			copy.deleteFirstTransaction();
		}
	}
	return trl;
}
TransactionList TransactionList::getTransactionsForAmount(double a) const {
	TransactionList trl;
	TransactionList copy(*this);
	Transaction temp;

	for(int i(0); i < size(); i++) {
		temp = copy.newestTransaction();
		if(temp.getAmount() == a)
			trl.addNewTransaction(temp);
		copy.deleteFirstTransaction();
	}
	return trl;
}
double TransactionList::getTotalTransactions() const {
	double total( 0);
	TransactionList copy(*this);
	Transaction temp;

	for(int i(0); i < size(); i++) {
		temp = copy.newestTransaction();
		if(temp.getAmount() > 0)
			total += temp.getAmount();
		copy.deleteFirstTransaction();
	}
	return total;
}
int TransactionList::getNumberOfTransactions() const {
	return size();
}

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<( ostream& os, const TransactionList& aTransactionList) {
    return ( aTransactionList.putDataInStream( os));
}
istream& operator>>( istream& is, TransactionList& aTransactionList) {
	return ( aTransactionList.getDataFromStream( is));
}
