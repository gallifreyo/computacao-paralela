#include <omp.h>
#include <stdio.h>

int vector[] = {2,4,6,8,10,12};

int length = sizeof(vector)/sizeof(int);

int N = 4;


void PrintVector()
{
	
	for(int i = 0; i < length;i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}



int main () {
	
	PrintVector();
	
	//omp_set_num_threads(2);
	
//	#pragma omp paralell for
//	{
//		for(int i=0;i<length/2;i++)
//		{
//			vector[i] *= N;
//		}
//	}
//
//	#pragma omp paralell for
//	{
//		for(int i=length/2;i<length;i++)
//		{
//			vector[i] *= N;
//		}
//	}
//	
	#pragma omp paralell for
	{
		
		for(int i=0;i<length/2;i++)
		{
			vector[i] *= N;
		}
		
		for(int i=length/2;i<length;i++)
		{
			vector[i] *= N;
		}
	}
	
	
	PrintVector();
	
}
