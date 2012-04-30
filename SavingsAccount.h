// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby

#ifndef SavingsAccountH
#define SavingsAccountH

#include "bankaccount.h"
class SavingsAccount :
	public BankAccount
{
public:
	SavingsAccount(void);
	virtual ~SavingsAccount(void);

	//functions to put data into and get data from streams
	virtual ostream& putDataInStream( ostream& os) const =0;
	virtual istream& getDataFromStream( istream& is) =0;

	virtual bool canDeposit( double amount) const =0;
	virtual double borrowable() const;
	double getMinimumBalance() const;
	void setMinimumBalance(const double);
private:
	double minimumBalance_;
};

#endif