#include <stdio.h>
#include <ctime>
#include "cpu.h"
#include <iostream>
#include <cstdlib>
#include "readyqueue.h"
using namespace Altman_1;
using namespace std;

int main(int argc, char **argv)
{
	
	srand((int)time(NULL));
	readyqueue sch1;	//Scheduler Object
	
	cpu cpu1;			//CPU object

//	Bootup simulation, populating the ready queue with a random number of 
	
	int bootup_processes;
	bootup_processes = ((int)rand( ) % 1000 + 1);
	for(int i = 0; i < bootup_processes; ++i)
	{
		sch1.enqueue( );
		
	}
	
//	processes at computer startup.
	
	

	
	//Declare variales for storing execution time statistics.
	int ex_time_seed = 0, ex_time_sum = 0, ex_time_average = 0, ex_time_min = 0, ex_time_max = 0, 
	queue_length_min = 0, queue_length_max = 0, priority_min = 0, priority_max = 0, priority_seed;
	
	
	//Create a seed queue length for comparing min and max queue length
	queue_length_min = sch1.size( );
	queue_length_max = sch1.size( );
	cout << "The size of the queue at boot:\t" << sch1.size( ) << endl;
	
	//Create a seed process priority weight for comparing min and max priorities
	priority_seed = sch1.dequeue( );
	priority_min = priority_seed; 
	priority_max = priority_seed;
	
	//Create a seed time to compare the min and max execution times
	ex_time_seed = cpu1.execute( );
	ex_time_min = ex_time_seed;
	ex_time_max = ex_time_seed;
	
	//Store the sum of all the execution times
	ex_time_sum += ex_time_seed;
	
	//Run
	for(unsigned int i = 0; i < 999; ++i)
	{
		ex_time_seed = cpu1.execute( );
		int pID;
		sch1.enqueue( );
		if(list_length(sch1.get_front()) > 1)
			pID = sch1.dequeue();
		if(ex_time_seed > ex_time_max)
			ex_time_max = ex_time_seed;
		if(ex_time_seed < ex_time_min)
			ex_time_min = ex_time_seed;
			
		if(sch1.size( ) >= queue_length_max)
			queue_length_max = sch1.size( );
		if(sch1.size( ) <= queue_length_min)
			queue_length_min = sch1.size( );
			
		if(pID > priority_max)
			priority_max = pID;
		if(pID < priority_min)
			priority_min = pID;
			
		ex_time_sum += ex_time_seed;
	}
	
	//Take the execution time average of 1000 executions
	ex_time_average = ex_time_sum/1000;
	
	//Print results
	cout << "The average execution of 1000 processes is:\t " << ex_time_average << endl;
	cout << "The maximum execution time is:\t" << ex_time_max << endl;
	cout << "The minimum execution time is:\t" << ex_time_min << endl;
	cout << "The maximum queue length is:\t" << queue_length_max << endl;
	cout << "The minimum queue length is:\t" << queue_length_min << endl;
	cout << "The maximum priority is:\t" << priority_max << endl;
	cout << "The minumum priority is:\t" << priority_min << endl;
	
	
	
}
