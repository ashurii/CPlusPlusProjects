#include <stdio.h>
#include <ctime>
#include "cpu.h"
#include <iostream>
#include <cstdlib>
#include "priority_queue.h"
using namespace Altman_1;
using namespace std;

int generate_process( )
{
	int process;
	process = ((int)rand( ) % 1000 + 1);
	return process;
}
int main(int argc, char **argv)
{
	
	srand((int)time(NULL));
	priority_queue sch1;	//Scheduler Object
	

	cpu cpu1;			//CPU object

//	Bootup simulation, populating the ready queue with a random number of 
	
	int bootup_processes;
	bootup_processes = ((int)rand( ) % 100 + 1);
	for(int i = 0; i < bootup_processes; ++i)
	{
		if(sch1.size( ) < sch1.max_size( ) - 1)
			sch1.push( generate_process( ));
	}
	
//	processes at computer startup.
	
	
	
	
	//Declare variales for storing execution time statistics.
	unsigned int ex_time_seed = 0, ex_time_sum = 0, ex_time_average = 0, ex_time_min = 0, ex_time_max = 0, 
	queue_length_min = 0, queue_length_max = 0, priority_min = 0, priority_max = 0, priority_seed;
	
	int iterations = 0;
	int processes_queued = 0;
	int processes_executed = 0;
	
	//Set timers for cpu execution times and process generation times
	unsigned int cpu_timer = 0;
	unsigned int process_timer = 0;
	unsigned int pID = 0;
	pID = sch1.top();
	process_timer = pID*(rand( ) % 100 + 1);
	//Create a seed queue length for comparing min and max queue length
	processes_queued += sch1.size( );
	queue_length_min = sch1.size( );
	queue_length_max = sch1.size( );
	cout << "The size of the queue at boot:\t" << sch1.size( ) << endl;
	
	//Create a seed process priority weight for comparing min and max priorities
	priority_seed = sch1.pop( );
	priority_min = priority_seed; 
	priority_max = priority_seed;
	
	//Create a seed time to compare the min and max execution times
	ex_time_seed = cpu1.execute( pID );
	ex_time_min = ex_time_seed;
	ex_time_max = ex_time_seed;
	
	//Store the sum of all the execution times
	ex_time_sum += ex_time_seed;
	

	//Run

		while(sch1.size( ) > 1)
		{
			if(cpu_timer > 0)			// tick down cpu execution timer
				--cpu_timer;
			if(process_timer > 0) 		// tick down process generation timer
				--process_timer;
			
			if(process_timer <= 0)		{			//When the timer reaches 0, add a process to the queue
				sch1.push(generate_process( ) );	
				process_timer = pID*(rand( ) % 1000 + 1);
				++processes_queued;
			}
				
			//If there are processes remaining and the cpu timer is at 0, execute the process at the front of the queue
			if(sch1.size( ) > 1 && cpu_timer == 0)
			{
				pID = sch1.pop();
				ex_time_seed = cpu1.execute( pID);
				cpu_timer = ex_time_seed;
				++processes_executed;
			}
				
		
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
			++iterations;
		}

	
	//Take the execution time average of 1000 executions
	ex_time_average = (ex_time_sum/iterations);
	
	//Print results
	cout << "processes queued:\t" << processes_queued << "\nprocesses executed:\t" << processes_executed << endl;
	cout << "The average execution time is:\t " << ex_time_average << endl;
	cout << "The maximum execution time is:\t" << ex_time_max << endl;
	cout << "The minimum execution time is:\t" << ex_time_min << endl;
	cout << "The maximum queue length is:\t" << queue_length_max << endl;
	cout << "The minimum queue length is:\t" << queue_length_min << endl;
	cout << "The maximum priority is:\t" << priority_max << endl;
	cout << "The minumum priority is:\t" << priority_min << endl;
	
	
	
}
