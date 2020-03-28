#include <stdio.h>
#include <math.h>

long long int start[100002];
long long int speed[100002];


struct Node
{
	long long int a;
	long long int b;
};

struct Node dequeue[100002];
long long int position[100002];

int main(void)
{
	long long int n;
	long long int k;
	long long int th;
	scanf("%lld%lld%lld",&n,&k,&th);
	
	for(long long int i=0;i<n;i++)
		scanf("%lld",&start[i]);

	//printf("heelo");

	for(long long int m=0;m<n;m++)
	{
		scanf("%lld",&speed[m]);
	}

	//printf("hello");

	
	long long int starttiming=0;
	long long int endtiming=th;
	long long int midtiming;
	long long int totalvalue=0;
	long long int answer=0;
	//printf("ram ji");
	while(starttiming<=endtiming)
	{
		//printf("bolo ram ram");
		totalvalue=0;
		midtiming=(starttiming+endtiming)/2;
		
		//calculating for this time

		long long int timing=midtiming;
	//	printf("Case analysis for time %lld\n\n",timing);
		//defining a stack
	//	printf("Value for position array\n\n");
		for(long long int i=0;i<n;i++)
		{
			dequeue[i].a=0;
			dequeue[i].b=0;
			position[i]=start[i]+(speed[i]*(timing));
	//		printf("%lld is value at position %lld\n ",position[i],i);
		}
		
		//printf("ram ram");
		
		long long int start=0;
		long long int end=0;
		
		dequeue[0].a=position[0];
		dequeue[0].b=0;

		for(long long int i=1;i<k;i++)
		{
			if(position[i]<=dequeue[end].a)
			{
				end++;
				dequeue[end].a=position[i];
				dequeue[end].b=i;
			}
			else
			{
				long long int rem=position[i];
				long long int z;
				for(z=end;z>=0;z--)
				{
					if(dequeue[z].a>=rem)
					{
						break;
					}
				}
				end=z+1;
				dequeue[end].a=position[i];
				dequeue[end].b=i;
			}
		}
	//	printf("\n\n");
	//	printf("%lld for first element \n",dequeue[start].a);
		totalvalue+=dequeue[start].a;
		
		for(long long int i=k;i<n;i++)
		{
			if(position[i]<=dequeue[end].a)
                        {
	                        end++;
        
				dequeue[end].a=position[i];
                                dequeue[end].b=i;
                        }
                        else
                        {
        	                long long int rem=position[i];
				long long int z;
                                for(z=end;z>=start;z--)
                                {
                	                if(dequeue[z].a>=rem)
                                        {
                        	                break;
                                        }
                                }
                                end=z+1;
                                dequeue[end].a=position[i];
                                dequeue[end].b=i;
                        }

			long long int range=i-k+1;

			for(;;)
			{
				long long int max=dequeue[start].a;
				long long int maxpos=dequeue[start].b;

				if(maxpos<range)
					start++;
				else
				{
					totalvalue+=max;
	//				printf("%lld was added for element \n",max);
					break;
				}
			}
		}
	//	printf("Totalvalue at %lld is %lld\n",timing,totalvalue);
		if(totalvalue<th)
		{
			starttiming=midtiming+1;
		}
		else if(totalvalue==th)
		{
			answer=timing+1;
			break;
		}
		else
		{
			answer=timing;
			endtiming=midtiming-1;
		}
	}

	printf("%lld\n",answer);
	return 0;
}






















		
