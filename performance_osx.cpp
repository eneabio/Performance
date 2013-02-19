// Copyright (C) 2012 Reply S.p.A. and/or its subsidiary(-ies). All rights reserved.
// Released under the the GNU Lesser General Public License version 2.1. In addition, as a special exception, Reply S.p.A. gives you certain additional rights.
// Alternatively, this file may be used in accordance with the terms and conditions contained in a signed written agreement between you and Reply S.p.A., and/or its subsidiary(-ies).
// See Licence.txt

#include "performance.h"

#include <stdint.h>
#include <mach/mach_time.h>

namespace performance {
//reference: http://www.macresearch.org/tutorial_performance_and_time

	//Raw mach_absolute_times going in, difference in seconds out
	double subtractTimes( uint64_t startTime, uint64_t endTime )
	{
		uint64_t difference = endTime - startTime;
		static double conversion = 0.0;
		
		if( conversion == 0.0 )
		{
			mach_timebase_info_data_t info;
			kern_return_t err = mach_timebase_info( &info );
			
			//Convert the timebase into seconds
			if( err == 0  )
				conversion = 1e-9 * (double) info.numer / (double) info.denom;
		}
		
		return conversion * (double) difference;
	}


	uint64_t   Start() {
		return mach_absolute_time();
	}
	uint64_t   Stop() {
		return mach_absolute_time();
	}
	double   ExecutionTime  (uint64_t start, uint64_t stop) {
		return subtractTimes(start, stop);
	}

}
