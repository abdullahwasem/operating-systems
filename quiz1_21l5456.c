#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	pid_t P1, P2;
	int t_time;
	int nooflap = atoi(argv[1]);
	int lap_t = atoi(argv[2]);
	int total = 0;
	
	int i ; 
	
	printf(" \n ptocess 1 ID %d" , getpid());
	pid_t id = 0 ; 
	

	
	id = fork();
	
	
	if(id == 0)
	{
		printf(" \n ptocess 2 ID %d" , getpid());
		printf("\n");
		
		for(i=0;i<nooflap;i++)
		{
		sleep(lap_t);
		printf("lap %d" , i+1);
		printf("finished");
		
		}
		
		
	}
	
	if(id>0)
	{
	  	t_time+=lap_t*nooflap;
	  	wait(NULL);
	  	int hour = t_time/3600;
	  	
	  	int minutes = (t_time-(3600*hour))/60;
	  	
	  	int seconds = (t_time-(3600*hour)-(minutes*60);
	  	
	  	printf("Total Time %d" , hour);
	  	printf(" :%d" , minutes);
	  	printf(" :%d" , seconds);
	  	
	  	pid_t id3;
	  	id3=fork();
	  	
	  	if(id3==0)
	  	{	printf("process 3 ID %d" , getpid());
	  		printf("MUHAMMAD ABDULLAH 21L-5456 process ID %d" , getpid());
	  		}
	  		
	  		else if (id3>0)
	  		{	
	  			wait(NULL);
	  		}
	  		
	  		}
	  		
	  		return 0 ; 
	  	
		}