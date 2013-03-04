// Copyright (C) 2012 Reply S.p.A. and/or its subsidiary(-ies). All rights reserved.
// Released under the the GNU Lesser General Public License version 2.1. In addition, as a special exception, Reply S.p.A. gives you certain additional rights.
// Alternatively, this file may be used in accordance with the terms and conditions contained in a signed written agreement between you and Reply S.p.A., and/or its subsidiary(-ies).
// See Licence.txt

#include "performance.h"

namespace performance {

	//double subtractTimes( Clock startTime, Clock endTime )
	//{	
	//	//to do: verify it...
	//	double timediff = ((double) (endTime - startTime)/CLOCKS_PER_SEC );  //CLOCKS_PER_SEC=1000 , return seconds
	//	return timediff;
	//}


	Clock   Start() {
		//return clock();
		LARGE_INTEGER li;
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
    if(!QueryPerformanceFrequency(&li))
	printf("QueryPerformanceFrequency failed!\n");

    PCFreq = double(li.QuadPart);  //out is in seconds...

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
	return CounterStart;
	}
	Clock   Stop() {
		//return clock();
		LARGE_INTEGER li;
	double PCFreq = 0.0;
	__int64 CounterStop = 0;
    if(!QueryPerformanceFrequency(&li))
	printf("QueryPerformanceFrequency failed!\n");

    PCFreq = double(li.QuadPart);  //out is in seconds...

    QueryPerformanceCounter(&li);
    CounterStop = li.QuadPart;
	return CounterStop;
	}

	double   ExecutionTime  (Clock start, Clock stop) {
		//return subtractTimes(start, stop);
		 LARGE_INTEGER li;
	double PCFreq = 0.0;
	 if(!QueryPerformanceFrequency(&li))
	printf("QueryPerformanceFrequency failed!\n");

    PCFreq = double(li.QuadPart);   //out is in seconds...
	//QueryPerformanceCounter(&li);
    return double(stop-start)/PCFreq;

	}

}
