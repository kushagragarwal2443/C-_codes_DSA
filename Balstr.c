#include <stdio.h>
char arr[100001];
int main(void)
{
	int s;
	scanf("%d",&s);
	for(int i=0;i<s;i++)
		scanf("%c",&arr[i]);
	if(s%2==1)
	{
		printf("-1\n");
	}
	else
	{
		int count=0;
		int change=0;
		for(int i=0;i<s;i++)
		{
			if(arr[i]=='A')
				count++;
			else if(arr[i]=='C'&&count==0)
			{
				count++;
				change++;
			}
			else
				count--;
		}
		change+=count/2;
		printf("%d\n",change);
	}
	return 0;
}
