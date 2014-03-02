#include <iostream>
#include <sys/time.h>
#include <stdint.h>

#include "logger.h"

using namespace std;

int main(int argc, char* argv[])
{	

	struct timeval tv_begin;
	struct timeval tv_end;

	gettimeofday(&tv_begin, NULL);
	uint64_t i = 0;
	for(; i < 1000000L; ++i)
	{
		LOG_DEBUG("hello, world, %d, %s", 110, "张念");
	}
	gettimeofday(&tv_end, NULL);

	cout << "spent: " << (tv_end.tv_sec * 1000 + tv_end.tv_usec / 1000) - 
		(tv_begin.tv_sec * 1000 + tv_begin.tv_usec / 1000) << "ms." << endl;

	return 0;
}