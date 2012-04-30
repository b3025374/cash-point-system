// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby

#if !defined ChildAccountH
#define ChildAccountH

#include "savingsaccount.h"
class ChildAccount :
	public SavingsAccount
{
public:
	ChildAccount(void);
	virtual ~ChildAccount(void);

	//functions to put data into and get data from streams
	virtual ostream& putDataInStream( ostream& os) const;
	virtual istream& getDataFromStream( istream& is);

	virtual bool canDeposit( double amount) const;

	double getMinimumPaidIn() const;
	double getMaximumPaidIn() const;
private:
	virtual const string prepareFormattedAccountDetails() const;
	double minimumPaidIn_;
	double maximumPaidIn_;
};

#endif