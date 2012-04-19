//Pascale Vacher - March 12
//OOP Assignment Semester 2

#ifndef CashPointH
#define CashPointH 

//---------------------------------------------------------------------------
//CashPoint: class declaration
//---------------------------------------------------------------------------

#include "CashCard.h"
#include "BankAccount.h"
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

    //support file handling functions & creation of dynamic objects
    bool canOpenFile( const string&) const;
	int checkAccountType( const string&) const;

	BankAccount* activateBankAccount( const string&);
	BankAccount* releaseBankAccount( BankAccount*, string);

    void activateCashCard( const string&);
	void releaseCashCard();
};

#endif
