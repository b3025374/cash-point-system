//Pascale Vacher - March 12
//OOP Assignment Semester 2

#include "CashPoint.h"

//---------------------------------------------------------------------------
//CashPoint: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

CashPoint::CashPoint()
	: p_theActiveAccount_( nullptr), p_theCashCard_( nullptr)
{ }

CashPoint::~CashPoint()
{
	assert( p_theActiveAccount_ == nullptr);
	assert( p_theCashCard_ == nullptr);
}


//____other public member functions

void CashPoint::activateCashPoint() {
	int command;
	theUI_.showWelcomeScreen();
    command = theUI_.readInCardIdentificationCommand();
	while ( command != QUIT_COMMAND)
    {
		performCardCommand( command);
	    theUI_.showByeScreen();
		command = theUI_.readInCardIdentificationCommand();
	}

}


//---------------------------------------------------------------------------
//private support member functions
//---------------------------------------------------------------------------

void CashPoint::performCardCommand( int option) {
    switch ( option)
	{
		case 1:
        {
            //read in card number and check that it is valid
            string cashCardNum;
			string cashCardFileName( theUI_.readInCardToBeProcessed( cashCardNum));	//read in card name & produce cashcard filename
            bool validCard( validateCard( cashCardFileName));		//check valid card
            theUI_.showValidateCardOnScreen( validCard, cashCardNum);
            if ( validCard) //valid card
            {
				//dynamically create a cash card & store card data
        		activateCashCard( cashCardFileName);
				//display card data with available accounts
				string s_card( p_theCashCard_->toFormattedString());
				theUI_.showCardOnScreen( s_card);
				//process all request for current card (& bank accounts)
                processOneCustomerRequests();
				//free memory space used by cash card
				releaseCashCard();
            }
            break;
		}
		default:theUI_.showErrorInvalidCommand();
	}
}
bool CashPoint::validateCard( const string& cashCardFileName) const {
//check that the card exists (valid)
    if ( ! canOpenFile( cashCardFileName))   //invalid card
        return false;
    else    //card exist
        return true;
}

int CashPoint::validateAccount( const string& bankAccountFileName) const {
//check that the account is valid (MORE WORK NEEDED: it should also check that it is accessible with that card and not already open)
    int validCode;
    if ( ! canOpenFile( bankAccountFileName)) 
		//account does not exist
		validCode = UNKNOWN_ACCOUNT;
	else
	  	//unaccessible account (exist0 but not listed on card)
		if ( ! p_theCashCard_->onCard( bankAccountFileName))     
    		validCode = UNACCESSIBLE_ACCOUNT;
		else
			//account valid (exists) and accessible
       		validCode = VALID_ACCOUNT;
    return validCode;
}

void CashPoint::processOneCustomerRequests() {
//process from one account
    string anAccountNumber, anAccountSortCode;
    //select active account and check that it is valid
    string bankAccountFileName( theUI_.readInAccountToBeProcessed( anAccountNumber, anAccountSortCode));
    int validAccountCode( validateAccount( bankAccountFileName));  //check valid account
    theUI_.showValidateAccountOnScreen( validAccountCode, anAccountNumber, anAccountSortCode);
    if ( validAccountCode == VALID_ACCOUNT) //valid account: exists, accessible with card & not already open
    {
       	//dynamically create a bank account to store data from file
        p_theActiveAccount_ = activateBankAccount( bankAccountFileName);
		//process all request for current card (& bank accounts)
    	processOneAccountRequests();
		//store new state of bank account in file & free bank account memory space
        p_theActiveAccount_ = releaseBankAccount( p_theActiveAccount_, bankAccountFileName);
    }
}

void CashPoint::processOneAccountRequests() {
    int option;
	//select option from account processing menu
  	option = theUI_.readInAccountProcessingCommand();
	while ( option != QUIT_COMMAND)
	{
		performAccountProcessingCommand( option);   //process command for selected option
		theUI_.wait();
        option = theUI_.readInAccountProcessingCommand();   //select another option
	}
}


void CashPoint::performAccountProcessingCommand( int option) {
	switch ( option)
	{
		case 1:	m1_produceBalance();
				break;
		case 2: m2_withdrawFromBankAccount();
 				break;
		case 3:	m3_depositToBankAccount();
				break;
		case 4:	m4_produceStatement();
				break;
		case 5: m5_showAllDepositTransactions();
				break;
		case 6: m6_showMiniStatement();
				break;
		case 7: m7_seachTransactions();
				break;
		case 8: m8_clearAllTransactionsUpToDate();
				break;
		default:theUI_.showErrorInvalidCommand();
	}
}
//------ menu options
//---option 1
void CashPoint::m1_produceBalance() const {
	double balance( p_theActiveAccount_->getBalance());
	theUI_.showProduceBalanceOnScreen( balance);
}
//---option 2
void CashPoint::m2_withdrawFromBankAccount() {
    double amountToWithdraw( theUI_.readInWithdrawalAmount());
    bool transactionAuthorised( p_theActiveAccount_->canWithdraw( amountToWithdraw));
    if ( transactionAuthorised)
    {   //transaction is accepted: money can be withdrawn from account
        p_theActiveAccount_->recordWithdrawal( amountToWithdraw);
    }   //else do nothing
    theUI_.showWithdrawalOnScreen( transactionAuthorised, amountToWithdraw);
}
//---option 3
void CashPoint::m3_depositToBankAccount() {
    double amountToDeposit( theUI_.readInDepositAmount());
    p_theActiveAccount_->recordDeposit( amountToDeposit);
    theUI_.showDepositOnScreen( true, amountToDeposit);
}
//---option 4
void CashPoint::m4_produceStatement() const {
	theUI_.showStatementOnScreen( p_theActiveAccount_->prepareFormattedStatement());
}
//---option 5
void CashPoint::m5_showAllDepositTransactions() const {
	bool noTransaction( p_theActiveAccount_->isEmptyTransactionList());
	string s;
	double d = 0;
	if( !noTransaction) {
		p_theActiveAccount_->produceAllDepositTransactions(s, d);
	}
	theUI_.showAllDepositsOnScreen(noTransaction, s, d);
}
//---option 6
void CashPoint::m6_showMiniStatement() const {
	bool noTransaction( p_theActiveAccount_->isEmptyTransactionList());
	string s;
	double d = 0;
	if( !noTransaction) {
		int num = theUI_.readInNumberOfTransactions();
		p_theActiveAccount_->produceMostRecentTransactions(num, s, d);
	}
	theUI_.showMiniStatementOnScreen(noTransaction,s,d);
}
//---option 7
void CashPoint::m7_seachTransactions() const {
	bool noTransaction( p_theActiveAccount_->isEmptyTransactionList());
	if ( !noTransaction)
	{
		int choice = theUI_.readInSearch(noTransaction);
		switch (choice) {
		case 0:
			break;
		case 1:
			m7a_showTransactionsForAmount();
			break;
		case 2: 
			//Search by title/subtitle
			m7b_showTransactionsForTitle();
			break;
		case 3:
			//Search by date
			m7c_showTransactionsForDate();
			break;
		}
	}
	else
		theUI_.showNoTransactionsOnScreen();
}
void CashPoint::m7a_showTransactionsForAmount() const {
	string str;
	int n;
	double a = theUI_.readInAmount();
	p_theActiveAccount_->produceTransactionsForAmount(a,str,n);
	theUI_.showMatchingTransactionsOnScreen(a, n, str);
}
void CashPoint::m7b_showTransactionsForTitle() const {
	string str;
	int n;
	string title = theUI_.readInSearchTitle();
	p_theActiveAccount_->produceTransactionsForTitle(title,str,n);
	theUI_.showMatchingTransactionsOnScreen<string>(title, n,str);
}
void CashPoint::m7c_showTransactionsForDate() const {
	string str;
	int n;
	Date d = theUI_.readInDate();
	p_theActiveAccount_->produceTransactionsForDate(d,str,n);
	theUI_.showMatchingTransactionsOnScreen<Date>(d, n,str);
}
//option 8
void CashPoint::m8_clearAllTransactionsUpToDate() const {
	string str;
	int i;
	Date d;
	bool noTransaction = p_theActiveAccount_->isEmptyTransactionList();
	if (!noTransaction) {
		Date cd = p_theActiveAccount_->getCreationDate();
		d = theUI_.readInValidDate(cd);
		p_theActiveAccount_->produceTransactionsUpToDate(d, str, i);
	}
	theUI_.showTransactionsUpToDateOnScreen(noTransaction, d, i, str);
	if (!noTransaction && !str.empty())
	{
		bool deletionConfirmed = theUI_.readInConfimedDeletion();
		if (deletionConfirmed)
			p_theActiveAccount_->recordDeletionOfTransactionUpToDate(d);
		theUI_.showDeletionOfTransactionUpToDateOnScreen(i,d,deletionConfirmed);
	}
}
//------private file functions

bool CashPoint::canOpenFile( const string& st) const {
//check if a file already exist
	ifstream inFile;
	inFile.open( st.c_str(), ios::in); 	//open file
	//if does not exist fail, otherwise open file but do nothing to it
	bool exist;
    if ( inFile.fail())
        exist = false;
    else
        exist = true;
    inFile.close();			//close file: optional here
    return exist;
}

void CashPoint::activateCashCard( const string& aCCFileName) {
//dynamically create a cash card to store data from file
    //effectively create the cash card instance with the data
	p_theCashCard_ = new CashCard;
    p_theCashCard_->readInCardFromFile( aCCFileName);
}

void CashPoint::releaseCashCard() {
//release the memory allocated to the dynamic instance of a CashCard
	delete p_theCashCard_;
	p_theCashCard_ = nullptr;
}

int CashPoint::checkAccountType( const string& aBAFileName) const {
    //(simply) identify type/class of account from the account number
    //start with 0 for bank account, 1 for current account, 2 for saving account, etc.
	return( atoi( aBAFileName.substr( 8, 1).c_str()));
}

BankAccount* CashPoint::activateBankAccount(  const string& aBAFileName) {
	//check the type of the account (already checked for validity)
	int accType( checkAccountType( aBAFileName));
    //effectively create the active bank account instance of the appropriate class
	//& store the appropriate data read from the file
	BankAccount* p_BA( nullptr);
	switch( accType)
    {
   //  	case BANKACCOUNT_TYPE:	//NOT NEEDED WITH ABSTRACT CLASSES
   //     	cout << "\n-------BANK-------\n";
   // 		p_BA = new BankAccount;    //points to a BankAccount object
   //    		p_BA->readInBankAccountFromFile( aBAFileName); //read account details from file
			//break;
		case CURRENTACCOUNT_TYPE:
			cout << "\n-------BANK-------\n";
    		p_BA = new CurrentAccount;    //points to a BankAccount object
      		p_BA->readInBankAccountFromFile( aBAFileName); //read account details from file
		break;
		case CHILDACCOUNT_TYPE:
			cout << "\n-------BANK-------\n";
    		p_BA = new ChildAccount;    //points to a BankAccount object
      		p_BA->readInBankAccountFromFile( aBAFileName); //read account details from file
		break;
		case ISAACCOUNT_TYPE:
			cout << "\n-------BANK-------\n";
    		p_BA = new ISAaccount;    //points to a BankAccount object
      		p_BA->readInBankAccountFromFile( aBAFileName); //read account details from file
		break;
    }
	//use dynamic memory allocation: the bank account created will have to be released in releaseBankAccount
	return p_BA;
}

BankAccount* CashPoint::releaseBankAccount( BankAccount* p_BA, string aBAFileName) {
//store (possibly updated) data back in file
    p_BA->storeBankAccountInFile( aBAFileName);
	//effectively destroy the bank account instance
	delete p_BA;
	return nullptr;
}

