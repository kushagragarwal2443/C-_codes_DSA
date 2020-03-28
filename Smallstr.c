#include <stdio.h>
#include <string.h>

char arr[100010];
char stack[100010];
char answer[100010];

int main(void)
{
	int n;
	scanf("%d",&n);
	scanf("%s",arr);
	int top=-1;
	int k=0;
	char c;
	int pos;
	for(int i=0;i<n;)
	{
		c=arr[i];
		pos=i;

		//least character

		for(int j=i;j<n;j++)
		{
			if(arr[j]<c)
			{
				c=arr[j];
				pos=j;
			}
		}
		if(top>=0&&c>=stack[top])
		{
			printf("%c",stack[top]);
			top--;
		}
		else
		{
			for(int z=i;z<pos;z++)
			{
				stack[++top]=arr[z];
			}

			printf("%c",c);
			i=pos+1;
		}
	}
	for(;top>-1;top--)
	{
		printf("%c",stack[top]);
	}
	return 0;
}
