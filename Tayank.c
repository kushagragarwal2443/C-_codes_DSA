#include <stdio.h>

int arr[30005];

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",&arr[i]);
		int f=0,flag=0;
		if(N==1)
			printf("1\n");
		else if(N==2)
		{
			if(arr[0]<=arr[1])
				printf("1\n");
			else
				printf("0\n");
		}
		else
		{
		for(int i=0;i<N-2;i++)
		{
			int a,b,c;
			a=arr[i];
			b=arr[i+1];
			c=arr[i+2];

			if(b>a&&b>c&&c>a)
				flag=1;
			else if(b<a&&b<c&&c>a)
				flag=1;
			else if(a>b&&b>c)
				flag=1;
			else
			{
				if(a<=b&&b<=c)
				{
					arr[i]=a;
					arr[i+1]=b;
					arr[i+2]=c;
				}
				else if(b>=a&&b>=c&&c<=a)
				{
					arr[i]=c;
                                        arr[i+1]=a;
                                        arr[i+2]=b;
                                }
				else
				{
					arr[i]=b;
					arr[i+1]=c;
					arr[i+2]=a;
				}
			}

			for(int x=0;x<=i+2;x++)
				printf("%d ",arr[x]);
			printf("\n");

			if(flag==1)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
		}
	}
	return 0;
}


