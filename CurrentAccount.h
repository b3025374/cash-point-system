#if !defined CurrentAccountH
#define CurrentAccountH

#include "bankaccount.h"
class CurrentAccount :
	public BankAccount
{
public:
	CurrentAccount(void);
	virtual ~CurrentAccount(void);

	//functions to put data into and get data from streams
	//virtual ostream& putDataInStream( ostream& os) const;
	//virtual istream& getDataFromStream( istream& is);

	virtual double borrowable() const;
	double getOverdraftLimit() const;
private:
	double overdraftLimit_;
};

#endif