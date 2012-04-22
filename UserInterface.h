//Pascale Vacher - March 12
//OOP Assignment Semester 2

#ifndef UserInterfaceH 
#define UserInterfaceH

//---------------------------------------------------------------------------
//UserInterface: class declaration
//---------------------------------------------------------------------------

#include "constants.h"
#include "Date.h"
#include "Time.h"

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class UserInterface {
public:
	//constructors & destructor
    void	showWelcomeScreen() const;
    void	showByeScreen() const;

	int		readInCardIdentificationCommand() const;
	int		readInAccountProcessingCommand() const;
	int		readInNumberOfTransactions() const;

	void	showErrorInvalidCommand() const;
    void	wait() const;
	const string	readInCardToBeProcessed( string& cardNum) const;
    void	showValidateCardOnScreen( bool valid, const string& cardNum) const;
	void	showCardOnScreen( const string& cardSt) const;
	const string  readInAccountToBeProcessed( string& aNum, string& sCod) const;
	void	showValidateAccountOnScreen( int valid, const string& aNum, const string& sCod) const;
	void	showNoTransactionsOnScreen() const;

    double	readInWithdrawalAmount() const;
    double	readInDepositAmount() const;
	double	readInAmount() const;
	string	readInSearchTitle() const;
	Date	readInDate() const;
	int		readInSearch(const bool noTrans) const;

    void	showProduceBalanceOnScreen( double bal) const;
    void	showDepositOnScreen( bool auth, double deposit) const;
    void	showWithdrawalOnScreen( bool auth, double withdrawal) const;
    void	showStatementOnScreen( const string&) const;
	void	showAllDepositsOnScreen( const bool noTrans, const string str, const double total) const;
	void	showMiniStatementOnScreen( const bool noTrans, const string str, const double total) const;
	template <class TYPE>
	void	showMatchingTransactionsOnScreen(const TYPE& a, const int n, const string str) const;

private:
    //support functions
	void	showCardIdentificationMenu() const;
	void	showAccountProcessingMenu() const;
    int		readInCommand() const;
    double	readInPositiveAmount() const;
	int		readInPositiveNumber() const;
};

template <class TYPE>
void UserInterface::showMatchingTransactionsOnScreen(const TYPE& a, const int n, const string str) const {
	Time time( Time::currentTime());
	Date d( Date::currentDate());
	string s( "SEARCH REQUESTED AT " + time.toFormattedString() + " ON " + d.toFormattedString() + "\n" + str);
	cout << s << "FOUND " << n << " TRANSACTIONS IN BANK ACCOUNT MATCHING THE SEARCH CRITERION " << a;
}

#endif
