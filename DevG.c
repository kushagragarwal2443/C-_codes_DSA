#include <stdio.h>

int arr1[20005];
int arr2[20005];
int arr3[20005];
int arr4[20005];

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


int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		int N,M;
		scanf("%d",&N);
		for(int j=0;j<N;j++)
		{
			scanf("%d %d",&arr1[j],&arr2[j]);
		}
		scanf("%d",&M);
                for(int j=0;j<M;j++)
                {
                        scanf("%d %d",&arr3[j],&arr4[j]);
                }
		MergeSort(arr1,0,N-1);
		MergeSort(arr2,0,N-1);
		MergeSort(arr3,0,M-1);
		MergeSort(arr4,0,M-1);

		int dist1,dist2,max=0;
		
		dist1=arr1[N-1]-arr4[0];
		dist2=arr3[M-1]-arr2[0];

		if(dist1>max)
			max=dist1;
		if(dist2>max)
			max=dist2;
		printf("%d\n",max);
	}
	return 0;
}


