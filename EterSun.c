#include <stdio.h>
#include <math.h>

long long int arr[100001];

int main(void)
{
	long long int n,k;
	scanf("%lld %lld",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	long long int j,l=0,sum=arr[0],min,pos;

	for(;;)
	{
		min=arr[l+1];
		pos=l+1;
		for(j=l+1;j<=l+k;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];
				pos=j;
			}
		}
		if(pos<n-1)
			l=pos;
		else if(pos>=n-1)
		{
			l=n-1;
			sum+=arr[n-1];
			break;
		}
		sum=sum+arr[l];
	}
	if(n==1)
		sum=sum/2;


	printf("%lld\n",sum);
	return 0;
}
		
