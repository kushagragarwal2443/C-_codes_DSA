#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int values[100002];
long long int totalvalue[100002];


int main(void)
{
	long long int n,k;
	scanf("%lld %lld",&n,&k);
	for(long long int i=0;i<n;i++)
		scanf("%lld",&values[i]);

	for(long long int i=0;i<k;i++)
	{
		totalvalue[i]=values[i];
	}

	for(long long int i=0;i<k;i++)
	{
		if(i!=0)
		{
			totalvalue[i]+=values[0];
		}
	}
	
	long long int minimum=0;
	long long int minimumposition=0;
	minimum+=values[0];
	
	for(long long int i=k;i<n;i++)
	{
		//i need to calculate minimum upto i-1st element
		//there are two cases
		//for first case when minimum element is in the sliding window


		long long int window=i-k;
		if(window<=minimumposition)
		{
			long long int valueminpos=totalvalue[minimumposition];

			if(totalvalue[i-1]>=valueminpos)
			{
				minimum=valueminpos;
			}


			else
			{
				minimumposition=i-1;
                                minimum=totalvalue[i-1];
			}

		}

		//second case when minimum element is outside sliding window



		else
		{

			long long int tempminimum=totalvalue[window];
			long long int tempminimumposition=window;
			long long int j=window;

			while(j<i)
			{
				long long int k=totalvalue[j];
				if(k<tempminimum)
				{
					tempminimumposition=j;
					tempminimum=k;
				}
				j++;
			}


			minimumposition=tempminimumposition;
			minimum=tempminimum;
		}
			
		totalvalue[i]=minimum;
		totalvalue[i]+=values[i];
	}


	printf("%lld",totalvalue[n-1]);
	return 0;
}
