#include <stdio.h>

long long int a[100005];

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		long long int n;
		scanf("%lld",&n);
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}

		int flag=0;long long int pos1=1,pos2=n;
		for(long long int i=0;i<n-1;i++)
		{
			if(flag==0&&a[i]>=a[i+1])
			{
				pos1=i+1;long long int number =a[i];
				for(long long int z=i;z<n-1;z++)
				{
					if(a[z]>number)
					{
						flag=0;
						pos1=1;
						break;
					}
					else if(a[z]<number)
					{
						flag=1;
						pos1=i+1;
						break;
					}
					
				}
			}
			else if(flag==1&&a[i]<a[i+1])
			{
				flag=2;
				pos2=i+1;
			}
			
		}
		//printf("%lld %lld\n",pos1,pos2);
		for(long long int i=0;i<=(pos2-pos1)/2;i++)
		{
			long long int d;
			d=a[pos1-1+i];
			a[pos1-1+i]=a[pos2-1-i];
			a[pos2-1-i]=d;
		}

		//for(long long int i=0;i<n;i++)
		//	printf("%lld ",a[i]);
		//printf("\n");
				
		for(long long int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
				flag=10;
		}

		if(flag==10)
			printf("NotPossible\n");
		else
			printf("%lld %lld\n",pos1,pos2);
	}
	return 0;
}

			
