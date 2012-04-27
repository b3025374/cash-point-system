#include "ISAaccount.h"


ISAaccount::ISAaccount(void)
	:maximumYearlyDeposit_( 0), currentYearlyDeposit_( 0)
{
	Date temp = Date::currentDate();
	endDepositPeriod_.setDate( temp.getDay(), temp.getMonth(), temp.getYear()+1);
}

ISAaccount::~ISAaccount(void)
{}