#include <stdio.h>
#include <string.h>

char arr[10000];
int a[10000];
int b1[10000];

int main(void)
{
	int size;
	scanf("%d",&size);
	scanf("%s",arr);
	int Q;
	int m=10000007;
	a[0]=arr[0]%m;
	b1[size-1]=arr[size-1]%m;

	for(int i=1;i<size;i++)
	{
		a[i]=((a[i-1]*29)%m+arr[i])%m;
	}

	for(int i=size-2;i>=0;i--)
        {
                b1[i]=((b1[i+1]*29)%m+arr[i])%m;
        }
	for(int i=0;i<size;i++)
		printf("%d %d\n",a[i],b1[size-1-i]);

	scanf("%d",&Q);
	
	for(int j=1;j<=Q;j++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int c1=a[r];
		int c2=a[l-1];
		int c3=1;
		for(int b=0;b<=r-l;b++)
		{
			c3=(c3*29)%m;
		}
		int c4=(c3*(c2%m))%m;
		int final=(c1-c4+m)%m;
		int d1=b1[l];
                int d2=b1[r+1];
                int d3=1;
                for(int b=0;b<=r-l;b++)
                {
                        d3=(d3*29)%m;
                }
                int d4=(d3*(d2%m))%m;
                int final1=(d1-d4+m)%m;
		printf("%d %d\n",final,final1);
		if(final==final1)
			printf("YES PALINDROME\n");
		else
			printf("NO PALINDROME\n");
	}
	return 0;
}
		
		


