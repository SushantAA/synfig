/*! ========================================================================
** Extended Template and Library Test Suite
** Clock Test
** $Id$
**
** Copyright (c) 2002 Robert B. Quattlebaum Jr.
**
** This package is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License as
** published by the Free Software Foundation; either version 2 of
** the License, or (at your option) any later version.
**
** This package is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** General Public License for more details.
**
** === N O T E S ===========================================================
**
** ========================================================================= */

/* === H E A D E R S ======================================================= */

#include <ETL/clock>
#include <stdio.h>

/* === M A C R O S ========================================================= */

using namespace etl;

/* === C L A S S E S ======================================================= */


/* === P R O C E D U R E S ================================================= */

int basic_test(void)
{
	int ret=0;
	fprintf(stderr,"default etl::clock precision:  %0.8f\n",etl::clock::precision());
	fprintf(stderr,"realtime etl::clock precision: %0.8f\n",etl::clock_realtime::precision());
	fprintf(stderr,"proctime etl::clock precision: %0.8f\n",etl::clock_proctime::precision());

	etl::clock_realtime timer;
	etl::clock::value_type amount,total;

	for(amount=3.0;amount>=0.00015;amount/=2.0)
	{
		if(amount*1000000.0<1000.0f)
			fprintf(stderr,"waiting %f microseconds...\n",amount*1000000.0);
		else if(amount*1000.0<400.0f)
			fprintf(stderr,"waiting %f milliseconds...\n",amount*1000.0);
		else
			fprintf(stderr,"waiting %f seconds...\n",amount);

		timer.reset();
		etl::clock::sleep(amount);
		total=timer();
		if((total-amount)*1000000.0<1000.0f)
			fprintf(stderr," ** I waited %f seconds, error of %f microseconds\n",total,(total-amount)*1000000);
		else if((total-amount)*1000.0<400.0f)
			fprintf(stderr," ** I waited %f seconds, error of %f milliseconds\n",total,(total-amount)*1000);
		else
			fprintf(stderr," ** I waited %f seconds, error of %f seconds\n",total,total-amount);

	}
	return ret;
}

/* === E N T R Y P O I N T ================================================= */

int main()
{
	int error=0;

	error+=basic_test();

	return error;
}

