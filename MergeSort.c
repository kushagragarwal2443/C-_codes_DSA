#include <stdio.h>
int a[10000];

void Merge(int a[],int l,int m,int r)
{
	int size=r-l+1;
	int K[size];
	//temporary array used is K from indices 0 to size-1
	int i=l;
	int j=m+1;

	for(int z=0;z<size;z++)
	{
		if(i<=m&&j<=r)
		{
		if(a[i]<a[j])
		{
			K[z]=a[i];
			i++;
		}
		else
		{
			K[z]=a[j];
			j++;
		}
		}
		else
		{
			if(i>m)
			{
				for(int yo=j;yo<=r;yo++)
				{
					K[z]=a[yo];
					z++;
				}
				break;
			}
			else
			{
				for(int yo=i;yo<=m;yo++)
                                {
                                        K[z]=a[yo];
                                        z++;
                                }
                                break;
			}
		}
	}

	for(int z=0;z<size;z++)
	{
		a[l+z]=K[z];
	}
}

void MergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
	        MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		Merge(a,l,m,r);
	}
}

int main()
{
	for(int i=0;i<10;i++)
	scanf("%d",&a[i]);

	MergeSort(a,0,9);
	
	for(int i=0;i<10;i++)
        printf("%d ",a[i]);
  	printf("\n");	
	return 0;
}
