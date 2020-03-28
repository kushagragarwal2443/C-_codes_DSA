#include <stdio.h>

int a[30005];
int inversion=0;

//Merge Sort Algorithm follows
void  Merge(int a[],int l,int m,int r)
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
                if(a[i]<=a[j])
                {
                        K[z]=a[i];
                        i++;
			
                }
                else
                {
                        K[z]=a[j];
                        j++;
			inversion+=m-i+1;
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


int main(void)
{
	int T;
	scanf("%d",&T);
	int n,k;
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		MergeSort(a,0,n-1);
		if(inversion%2==0)
			printf("1");
		else
			printf("0");
		inversion=0;
		printf("\n");
	}
	return 0;
}
