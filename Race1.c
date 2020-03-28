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
	long long int totalvalue;

        scanf("%lld%lld%lld",&n,&k,&th);

        for(long long int i=1;i<=n;i++)
                scanf("%lld",&start[i]);

        printf("heelo");

        for(long long int m=1;m<=n;m++)
        {
                scanf("%lld",&speed[m]);
        }

        printf("hello");


	printf("bolo ram ram");
                totalvalue=0;
                
                //calculating for this time

                long long int time=4;

                //defining a stack

                for(long long int i=1;i<=n;i++)
                {
                        dequeue[i].a=0;
                        dequeue[i].b=0;
                        position[i]=start[i]+(speed[i]*time);
                }

                printf("ram ram");

                long long int start=0;
                long long int end=-1;


                for(long long int i=1;i<k;i++)
                {
                        if(end==-1)
                        {
                                end++;
                                dequeue[end].a=position[i];
                                dequeue[end].b=i;
                        }
                        else
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

                                        for(long long int k=end;k>=0;k--)
                                        {
                                                if(dequeue[k].a>=rem)
                                                {
                                                        break;
                                                }
                                        }
                                        end=k+1;
                                        dequeue[end].a=position[i];
                                        dequeue[end].b=i;
                                }
                        }
                }

                for(long long int i=k;i<=n;i++)
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

                                for(long long int z=end;z>=0;z--)
                                {
                                        if(dequeue[z].a>=rem)
                                       {
                                                break;
                                        }
                                }
                                end=k+1;
                                dequeue[end].a=position[i];
                                dequeue[end].b=i;
                        }

                        long long int range=i-k+1;

                        for(long long int z=start;z<=end;k++)
                        {
                                long long int max=dequeue[z].a;
                                long long int maxpos=dequeue[z].b;

                                if(maxpos<range)
                                        start++;
                                else
                                {
                                        totalvalue+=max;
                                        break;
                                }
                        }
                }
		printf("%lld",totalvalue);
		return 0;
}

                

