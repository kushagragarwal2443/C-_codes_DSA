#include <stdio.h>
#include <string.h>
#include <math.h>

struct Node
{
	int a;
	int b;
};



char arr[1005][1005];
int arr1[1005][1005];
int arr2[1005][1005];
struct Node stack[1005];

int main(void)
{
	int m,n;
	scanf("%d %d",&m,&n);

	//forming arr
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			scanf(" %c",&arr[i][j]);
	
	}

	//forming arr1
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]=='E')
				arr1[i][j]=0;
			else
				arr1[i][j]=1;
		}
	}

	//checking arr1
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr1[i][j]);
		}
		printf("\n");
	}*/

	//forming arr2
	for(int j=0;j<n;j++)
		arr2[0][j]=arr1[0][j];
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr1[i][j]==0)
				arr2[i][j]=0;
			else
				arr2[i][j]=arr2[i-1][j]+arr1[i][j];
		}
	}
	
	//checking arr2
	/*for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("%d ",arr2[i][j]);
                }
                printf("\n");
        }*/
	
	//Now maximum area under a histogram algo
	
	int maxarea=0,area; 
	for(int i=0;i<m;i++)
	{
		
		int top=-1;//signifies ki stack empty hai
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(top==-1||stack[top].a<=arr2[i][j])
			{
				top++;
				stack[top].a=arr2[i][j];
				stack[top].b=j;
			}
			else if(stack[top].a>arr2[i][j])
			{
				for(;top>-1;)
				{
					int k=stack[top].a;
					if(k>arr2[i][j])
					{
						if(top!=0)
							area=k*(j-stack[top-1].b-1);
						else
							area=k*(j);
						//printf("Area for %d is %d and count is %d \n",k,area,stack[top-1].b);
						if(area>maxarea)
							maxarea=area;
						top--;
					}
					else
					{
						break;
					}
				}
				top++;
                                stack[top].a=arr2[i][j];
                                stack[top].b=j;

			}
		}
		for(;top>-1;)
                {
		    if(top!=0)
    	            	area=stack[top].a*(n-stack[top-1].b-1);
		    else
		    	area=stack[top].a*(n);
		    //printf("AREA for %d is %d and count is %d\n",stack[top].a,area,stack[top].b);
		    if(area>maxarea)
			    maxarea=area;
		    top--;
		}
	}

	printf("%d\n",maxarea);
	return 0;
}
