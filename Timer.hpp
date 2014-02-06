#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

#define NS_IN_SEC 1000000.0f

class Timer {
private:

	timeval startTime;
        timeval endTime;
	double duration;

public:
	Timer() {
		duration = 0.0f;
	}

	void start(){
		gettimeofday(&startTime, NULL);
	}

	void stop(){
	        long seconds, nseconds;

		gettimeofday(&endTime, NULL);

		seconds  = endTime.tv_sec  - startTime.tv_sec;
		nseconds = endTime.tv_usec - startTime.tv_usec;

		duration = seconds + nseconds/NS_IN_SEC;
	}

        double getDuration() {
	  return duration;
	}

	void printTime(double duration){
		printf("%5.3f seconds\n", duration);
	}
};

