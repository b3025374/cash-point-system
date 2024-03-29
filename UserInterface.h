//Pascale Vacher - March 12
// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby
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
	void	showTransactionsUpToDateOnScreen(const bool noTransaction, const Date d, const int i, const string str) const;
	void	showDeletionOfTransactionUpToDateOnScreen(const int i, const Date d, const bool deletionConfirmed) const;
	void	show_validate_transfer_on_screen( const int& valid) const;
	void	show_valid_transfer_on_screen() const;

    double	readInWithdrawalAmount() const;
    double	readInDepositAmount() const;
	double	readInTransferAmount() const;
	double	readInAmount() const;
	string	readInSearchTitle() const;
	Date	readInDate() const;
	int		readInSearch(const bool noTrans) const;
	Date	readInValidDate(const Date cd) const;
	bool	readInConfimedDeletion() const;

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
