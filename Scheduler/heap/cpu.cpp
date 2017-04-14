#include "cpu.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace Altman_1
{
	cpu::cpu( ){ };
	int cpu::execute( int process)
	{
		int execution_time;
		execution_time = (rand( ) % 10  +1);
		return execution_time * process;
	}
}
