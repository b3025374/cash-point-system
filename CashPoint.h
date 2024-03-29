//Pascale Vacher - March 12
// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby
//OOP Assignment Semester 2

#ifndef CashPointH
#define CashPointH 

//---------------------------------------------------------------------------
//CashPoint: class declaration
//---------------------------------------------------------------------------


#include "BankAccount.h"
#include "CashCard.h"
#include "ChildAccount.h"
#include "CurrentAccount.h"
#include "ISAaccount.h"
#include "SavingsAccount.h"
#include "UserInterface.h"

#include <fstream>
#include <string>
using namespace std;

class CashPoint {
public:
	//constructors & destructor
	CashPoint();	//default constructor
	~CashPoint();	//destructor
    void activateCashPoint();
private:
	//data items
    BankAccount* p_theActiveAccount_;
    CashCard* p_theCashCard_;
    const UserInterface theUI_;

	//support functions
	void performCardCommand( int);
    void performAccountProcessingCommand( int);
    bool validateCard( const string&) const;
	int  validateAccount( const string&) const;
	void processOneCustomerRequests();
	void processOneAccountRequests();

    void performSubMenuCommand( int);
    //commands
    //option 1
    void m1_produceBalance() const;
    //option 2
    void m2_withdrawFromBankAccount();
    //option 3
    void m3_depositToBankAccount();
    //option 4
    void m4_produceStatement() const;
	//option 5
	void m5_showAllDepositTransactions() const;
	//option 6
	void m6_showMiniStatement() const;
	//option 7
	void m7_seachTransactions() const;
	void m7a_showTransactionsForAmount() const;
	void m7b_showTransactionsForTitle() const;
	void m7c_showTransactionsForDate() const;
	//option 8
	void m8_clearAllTransactionsUpToDate() const;
	// option 9
	void m9_transfer_money();
	void m9_validate_transfer_amount( int& valid, const bool& withdraw, const bool& deposit);

    //support file handling functions & creation of dynamic objects
    bool canOpenFile( const string&) const;
	int checkAccountType( const string&) const;

	BankAccount* activateBankAccount( const string&);
	BankAccount* releaseBankAccount( BankAccount*, string);

    void activateCashCard( const string&);
	void releaseCashCard();
};

#endif
