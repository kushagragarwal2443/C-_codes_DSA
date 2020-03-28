#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int heap[100000];
long long n=0;


void heapify_down(long long int i)
{
	long long int max;
	long long int j=i;
	long long int pos=-1;
	for(;j<n;)
	{
		if(2*j+2<n)
		{
		if(heap[2*j+1]>heap[2*j+2])
		{
			max=heap[2*j+1];
			pos=2*j+1;
		}
		else
		{
			max=heap[2*j+2];
                        pos=2*j+2;
		}
		
		if(heap[j]<max)
		{
			long long int swap=max;
			heap[pos]=heap[j];
			heap[j]=swap;
			j=pos;
		}
		else
			break;
		}
		else
		{
			if(2*j+1<n)
			{
			if(heap[j]<heap[2*j+1])
               		{
                   	   	 long long int swap=heap[2*j+1];

                                 heap[2*j+1]=heap[j];
                     	  	 heap[j]=swap;
                       		 j=2*j+1;
			}
			}
			else
				break;
                }

	}
}


void heapify_up(long long int i)
{
	long long int j=i;

	for(;j>=0;)
	{
		if(j>0)
                {
                if(heap[(j-1)/2]<heap[j])
                {
                        long long int swap=heap[(j-1)/2];
                        heap[(j-1)/2]=heap[j];
                        heap[j]=swap;
                        j=(j-1)/2;
                }
		else
			break;
		}
		else
			break;
	}
}

void insert(long long int val)
{
	heap[n]=val;
	n++;
	heapify_up(n-1);
	printf("\n");
	for(long long int i=0;i<n;i++)
        {
                printf("%lld ",heap[i]);
        }
	printf("\n");

}

void pop()
{
	heap[0]=heap[n-1];
	n=n-1;
	heapify_down(0);
	for(long long int i=0;i<n;i++)
        {
                printf("%lld ",heap[i]);
        }
	printf("\n");

}

void delete(long long int i)
{
	heap[i]=heap[n];
	n=n-1;
	heapify_down(i);
	for(long long int i=0;i<n;i++)
        {
                printf("%lld ",heap[i]);
        }

}


int main()
{
	long long int c,d;
	for(;;)
	{
		printf("1.insert 2.delete 3.pop 4.stop \n");
		scanf("%lld",&c);
		if(c==1)
		{

			scanf("%lld",&d);
			insert(d);
			
		}

		else if(c==2)
		{
			scanf("%lld",&d);
			delete(d);
		}
		else if(c==3)
		{
			pop();
		}
		else
			break;
	}
	
	for(long long int i=0;i<=n;i++)
	{
		printf("%lld ",heap[i]);
	}


	return 0;
}








