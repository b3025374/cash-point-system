// Updated by: Antony Marsden, Tom Pearson and Edward Willoughby

#if !defined ISAH
#define ISAH

#include "Date.h"
#include "savingsaccount.h"
class ISAaccount :
	public SavingsAccount
{
public:
	ISAaccount(void);
	virtual ~ISAaccount(void);

	//functions to put data into and get data from streams
	virtual ostream& putDataInStream( ostream& os) const;
	virtual istream& getDataFromStream( istream& is);

	virtual bool canDeposit( double amount) const;
	virtual void recordDeposit( double amount);
	virtual void recordTransferDeposit( const string& account_details, double amountToDeposit);

	double getMaximumYearlyDeposit() const;
	double getCurrentYearlyDeposit() const;
	Date getEndDepositPeriod() const;
private:
	void updateCurrentYearlyDeposit(const double a);
	virtual const string prepareFormattedAccountDetails() const;
	Date endDepositPeriod_;
	double maximumYearlyDeposit_;
	double currentYearlyDeposit_;
};

#endif