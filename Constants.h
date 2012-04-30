//Pascale Vacher - March 12
// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby
//OOP Assignment Semester 2

#ifndef ConstantsH
#define ConstantsH

//menu command
const int QUIT_COMMAND( 0);

//account type
const int BANKACCOUNT_TYPE( 0);
const int CURRENTACCOUNT_TYPE( 1);
const int SAVINGSACCOUNT_TYPE( 2);
const int CHILDACCOUNT_TYPE( 3);
const int ISAACCOUNT_TYPE( 4);

//account state
const int VALID_ACCOUNT(		0);
const int ALREADY_OPEN_ACCOUNT(	1);
const int UNKNOWN_ACCOUNT(		2);
const int INACCESSIBLE_ACCOUNT(	3);

// trasfer validation
const int TRANSFER_VALID(				0);
const int INVALID_WITHDRAWAL_DEPOSIT(	1);
const int INVALID_WITHDRAWAL(			2);
const int INVALID_DEPOSIT(				3);

#endif