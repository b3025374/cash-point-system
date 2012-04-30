//Pascale Vacher - March 12
// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby
//OOP Assignment Semester 2

#include "UserInterface.h" 

//---------------------------------------------------------------------------
//UserInterface: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

//____other public member functions

//menu functions

void UserInterface::wait() const {
	char ch;
	cout << "\n\nPress RETURN to go back to menu\n";
	cin.get( ch);
	cin.get( ch);
//	flushall();
}
int UserInterface::readInCardIdentificationCommand() const {
    showCardIdentificationMenu();
    return ( readInCommand());
}
void UserInterface::showCardIdentificationMenu() const {
	cout << "\n\n\n      ________________________________________";
	cout << "\n      _______CARD IDENTIFICATION MENU________";
	cout << "\n      ________________________________________";
	cout << "\n       0           Quit CashPoint application";
	cout << "\n       1              Enter your card details";
	cout << "\n      ________________________________________";
}
int UserInterface::readInAccountProcessingCommand() const{
    showAccountProcessingMenu();
    return ( readInCommand());
}
int UserInterface::readInNumberOfTransactions() const {
	cout << "ENTER THE NUMBER OF TRANSACTIONS REQUIRED: ";
	return readInPositiveNumber();
}
void UserInterface::showAccountProcessingMenu() const {
	cout << "\n\n\n      ________________________________________";
	cout << "\n      ________ACCOUNT PROCESSING MENU________";
	cout << "\n      ________________________________________";
	cout << "\n       0 End account processing & remove card";
	cout << "\n       1                      Display balance";
	cout << "\n       2                Withdraw from account";
	cout << "\n       3                 Deposit into account";
	cout << "\n       4                       Show statement";
	cout << "\n       5                    Show all deposits";
	cout << "\n       6                  Show mini statement";
	cout << "\n       7    Show all transations above amount";
	cout << "\n       8    Clear all transactions up to date";
	cout << "\n       9          Transfer to another account";
	cout << "\n         ________________________________________";
}

const string UserInterface::readInCardToBeProcessed( string& aCardNumber) const {
	cout << "\n SELECT THE CARD ...\n";
	cout << "   CARD NUMBER:  ";         //ask for card number
    cin >> aCardNumber;
    cout << "\n=========================================";
    //create card file name
    return( "card_" + aCardNumber + ".txt");
}

void UserInterface::showValidateCardOnScreen( bool valid, const string& cashCardNum) const {
	if ( ! valid)   //invalid card
        cout << "\nERROR: INVALID CARD\n"
             << "\nTHE CARD (NUMBER: " << cashCardNum << ") DOES NOT EXIST!";
    else   //card exists
        cout << "\nTHE CARD (NUMBER: " << cashCardNum << ") EXISTS!";
}

void UserInterface::showCardOnScreen( const string& aCardDetails) const {
    cout << "\n=========================================";
    cout << "\n________ CARD DETAILS ___________________";
	cout << aCardDetails;
    cout << "\n________ END CARD DETAILS _______________";
    cout << "\n=========================================";
}

const string UserInterface::readInAccountToBeProcessed( string& anAccountNumber, string& aSortCode) const {
    cout << "\n SELECT THE ACCOUNT ...\n";
	cout << "   ACCOUNT NUMBER:  ";	//ask for account number
    cin >> anAccountNumber;
	cout << "   SORT CODE:       ";	//ask for sort code
    cin >> aSortCode;
    cout << "\n=========================================";
    //create account file name
    return( "account_" + anAccountNumber + "_" + aSortCode + ".txt");
}
void UserInterface::showValidateAccountOnScreen( int validCode, const string& accNum, const string& srtCode) const {
    switch( validCode)
    {
    	case VALID_ACCOUNT:		//account valid: it exists, is accessible with that card
        	cout << "\nTHE ACCOUNT (NUMBER: " << accNum
             	 << " CODE: " << srtCode << ") IS NOW OPEN!";
            break;
		case ALREADY_OPEN_ACCOUNT:		//account valid: it exists, is accessible with that card but is already open
        	cout << "\nTHE ACCOUNT (NUMBER: " << accNum
             	 << " CODE: " << srtCode << ") IS ALREADY OPEN!";
            break;
    	case UNKNOWN_ACCOUNT:		//account does not exist
        	cout << "\nERROR: INVALID ACCOUNT"
                 << "\nTHE ACCOUNT (NUMBER: " << accNum
                 << " CODE: " << srtCode << ") DOES NOT EXIST!";
            break;
    	case INACCESSIBLE_ACCOUNT:		//account exists but is not accessible with that card
        	cout << "\nERROR: INVALID ACCOUNT"
             	 << "\nTHE ACCOUNT (NUMBER: " << accNum
             	 << " CODE: " << srtCode << ") IS NOT ACCESSIBLE WITH THIS CARD!";
            break;
    }
}

void UserInterface::showNoTransactionsOnScreen() const {
	 cout << "\nNO TRANSACTIONS IN BANK ACCOUNT" ;
}

void UserInterface::showTransactionsUpToDateOnScreen(const bool noTransaction, const Date d, const int i, const string str) const {
	if (noTransaction)
	{
		cout << "\nNO TRANSACTIONS IN BANK ACCOUNT UP TO DATE:" << d << "\n"; 
	} else {
		cout << "\n" << i << " TRANSACTIONS FOUND FOR DATE: " << d << "\n" << str << "\n";
	}
}

void UserInterface::showDeletionOfTransactionUpToDateOnScreen(const int i, const Date d, const bool deletionConfirmed) const {
	if (deletionConfirmed)
	{
		cout << "THE " << i << " TRANSACTIONS IN BANK ACCOUNT UP TO DATE " << d << " HAVE BEEN DELETED\n";
	} else {
		cout << "OPERATION CANCELED\n";
	}
}

void UserInterface::show_validate_transfer_on_screen( const int& valid) const {
	if( valid == TRANSFER_VALID)
		cout << "THE TRANSFER IS VALID\n";
	else {
		cout << "TRANSFER CANCELLED\n";

		if( valid == INVALID_WITHDRAWAL_DEPOSIT)
			cout << "INVALID: INSUFFICIENT FUNDS AND UNABLE TO DEPOSIT\n";
		else if( valid == INVALID_WITHDRAWAL)
			cout << "INVALID: INSUFFICIENT FUNDS\n";
		else if( valid == INVALID_DEPOSIT)
			cout << "INVALID: TOO MUCH TO DEPOSIT\n";
	}
}

void UserInterface::show_valid_transfer_on_screen() const {
	cout << "TRANSFER SUCCESSFUL\n";
}

//input functions

double UserInterface::readInWithdrawalAmount() const {
    //ask for the amount to withdraw
    cout << "\nAMOUNT TO WITHDRAW: \234" ;
	return ( readInPositiveAmount());
}
double UserInterface::readInDepositAmount() const {
    //ask for the amount to deposit
    cout << "\nAMOUNT TO DEPOSIT: \234" ;
	return ( readInPositiveAmount());
}
double UserInterface::readInTransferAmount() const {
    //ask for the amount to transfer
    cout << "\nAMOUNT TO TRANSFER: \234" ;
	return ( readInPositiveAmount());
}
double UserInterface::readInAmount() const {
	cout << "\nENTER AMOUNT: \234";
    double amount;
	cin >> amount;
    return amount;
}
string UserInterface::readInSearchTitle() const {
	cout << "\nENTER SEARCH CRITERIA: ";
	string criteria;
	cin >> criteria;
	return criteria;
}
Date UserInterface::readInDate() const {
	cout << "\nENTER DATE (DD MM YYYY): ";
	int d, m, y;
	cin >> d >> m >> y;
	Date date(d, m, y);
	return date;
}
int UserInterface::readInSearch(const bool noTrans) const {
	int num = 0;
	if( !noTrans)
	{
		cout << "ENTER SEARCH CRITERIA (0 - cancel search, 1 - search by amount, 2 - search by title/subtitle, 3 - search by date): ";
		cin >> num;
		while (num < 0 || num > 3)
		{
			cout << "INVALID SEARCH. ENTER SEARCH CRITERIA: ";
			cin >> num;
		}
	}
	else
		cout << "NO TRANSACTIONS IN BANK ACCOUNT";
	return num;
}

Date UserInterface::readInValidDate(const Date cd) const {
	cout << "ENTER A DATE: (dd:mm:yy)";
	int day,month,year;
	cin >> day >> month >> year;
	Date date(day,month,year);
	while (!date.isValid(cd))
	{
		cout << "ENTER A DATE: (dd:mm:yy)";
		int day,month,year;
		cin >> day >> month >> year;
		date.setDate(day,month,year);
	}
	return date;
}

bool UserInterface::readInConfimedDeletion() const {
	cout << "ARE YOU SURE YOU WANT TO DELETE DISPLAYED TRANSACTIONS (Y/N): \n";
	char c;
	cin >> c;
	while (toupper(c) != 'Y' && toupper(c) != 'N')
	{
		cout << "INVALID CHOICE. PLEASE ENTER Y OR N: \n";
		cin >> c;
	}
	if (toupper(c) == 'Y')
		return true;
	else
		return false;
}

//output functions

void UserInterface::showProduceBalanceOnScreen( double balance) const {
    cout << "\nTHE CURRENT BALANCE IS: \234" << setw(12) << balance;
}
void UserInterface::showWithdrawalOnScreen( bool trAuthorised, double amountWithdrawn) const {
    if ( trAuthorised)
    	cout << "\nTRANSACTION AUTHORISED!: \n\234"
             << setw(0) << amountWithdrawn
             << " WITHDRAWN FROM ACCOUNT";
    else //not enough money
		cout << "\nTRANSACTION IMPOSSIBLE!";
}
void UserInterface::showDepositOnScreen( bool trAuthorised, double amountDeposited) const {
    if ( trAuthorised)
    	cout << "\nTRANSACTION AUTHORISED!:\n\234"
             << setw(0) << amountDeposited
             << " DEPOSITED INTO ACCOUNT";
    else //too much to deposit
		cout << "\nTRANSACTION IMPOSSIBLE!";
}
void UserInterface::showAllDepositsOnScreen( const bool noTrans, const string str, const double total) const {
	if(!noTrans) {
		Time t( Time::currentTime());
		Date d( Date::currentDate());
		string s( "ALL DEPOSIT TRANSACTIONS REQUESTED AT " + t.toFormattedString() + " ON " + d.toFormattedString() + "\n" + str + " TOTAL: ");
		cout << s << 156 << total;
	}
	else
		cout << "NO TRANSACTIONS IN BANK ACCOUNT";
}
void UserInterface::showMiniStatementOnScreen( const bool noTrans, const string str, const double total) const {
	if(!noTrans) {
		Time t( Time::currentTime());
		Date d( Date::currentDate());
		string s( "RECENT TRANSACTIONS REQUESTED AT " + t.toFormattedString() + " ON " + d.toFormattedString() + "\n" + str + " TOTAL: ");
		cout << s << 156 << total;
	}
	else
		cout << "NO TRANSACTIONS IN BANK ACCOUNT";
}
//template <class TYPE>
//void UserInterface::showMatchingTransactionsOnScreen(const TYPE& a, const int n, const string str) const {
//	Time time( Time::currentTime());
//	Date d( Date::currentDate());
//	string s( "SEARCH REQUESTED AT " + time.toFormattedString() + " ON " + d.toFormattedString() + "\n" + str);
//	cout << s << "FOUND " << n << " TRANSACTIONS IN BANK ACCOUNT MATCHING THE SEARCH CRITERION " << a;
//}

void UserInterface::showStatementOnScreen( const string& statement) const {
    cout << "\nPREPARING STATEMENT...";
    cout << "\n________ ACCOUNT STATEMENT _____";
	cout << statement;
    cout << "\n________ END ACCOUNT STATEMENT _____";
}

//---------------------------------------------------------------------------
//private support member functions
//---------------------------------------------------------------------------

void UserInterface::showWelcomeScreen() const {
	cout << "\n\n\n             _____WELCOME TO THE ATM_____";
}
void UserInterface::showByeScreen() const {
    cout << "\n\n\n________________NEXT CUSTOMER...\n\n";
}
int UserInterface::readInCommand() const{
	int com;
	cout << "\n          ENTER YOUR COMMAND: ";
	cin >> com;
	return com;
}
void UserInterface::showErrorInvalidCommand() const {
	cout << "\nINVALID COMMAND CHOICE, TRY AGAIN";
}
double UserInterface::readInPositiveAmount() const {
    double amount;
	cin >> amount;
	while ( amount <= 0.0)
    {
	    cout << "\nAMOUNT SHOULD BE A POSITIVE AMOUNT, TRY AGAIN: ";
		cin >> amount;
	}
    return amount;
}
int UserInterface::readInPositiveNumber() const {
    int amount;
	cin >> amount;
	while ( amount <= 0.0)
    {
	    cout << "\nAMOUNT SHOULD BE A POSITIVE AMOUNT, TRY AGAIN: ";
		cin >> amount;
	}
    return amount;
}