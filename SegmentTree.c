#include <stdio.h>
#include <stdlib.h>

int arr[1000];
int seg[5000];

void buildTree(int l,int r,int ind)
{
	if(l==r)
		seg[ind]=arr[l];
	else
	{
		buildTree(l,(l+r)/2,2*ind+1);
		buildTree((l+r)/2+1,r,2*ind+2);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
}

void update(int l,int r,int index, int ind,int difference)
{
	if(l==r)
	{
		seg[ind]+=difference;
		return;
	}
	if(index<=(l+r)/2)
		update(l,(l+r)/2,index,2*ind+1,difference);
	else
		update((l+r)/2+1,r,index,2*ind+2,difference);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int sum(int ql,int qr,int l,int r,int ind)
{
	if(l>qr||r<ql)
		return 0;
	else if(ql<=l&&r<=qr)
		return seg[ind];
	else
	return sum(ql,qr,l,(l+r)/2,2*ind+1) + sum(ql,qr,(l+r)/2+1,r,2*ind+2);
}

int max(int ql,int qr,int l,int r,int ind,int maxi)
{
        if(l>qr||r<ql)
                return 0;
        else if(ql<=l&&r<=qr)
                return seg[ind];
        else
	{
        	int a=max(ql,qr,l,(l+r)/2,2*ind+1,maxi);
	        int b=max(ql,qr,(l+r)/2+1,r,2*ind+2,maxi);
		int c=a+b;
		if(c>maxi)
		{
			maxi=c;
			return a+b;
		}
		else
			return 0;
	}

}


int calcmax(int i,int j,int x)
{
	int a=sum(i,j,0,x,0);
	int f;
	for(int m=i;m<=j;m++)
	{
		for(int n=m;n<=j;n++)
		{
			f=sum(m,n,0,x,0);
			if(f>a)
				a=f;
		}
	}
	return a;
}

int main(void)
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	buildTree(0,N-1,0);
	
	//for(int i=0;i<2*N-1;i++)
	//	printf("%d ",seg[i]);
	//printf("\n");
	

	//update(0,N-1,3,0,5);
	//for(int i=0;i<2*N-1;i++)
        //        printf("%d ",seg[i]);
//	printf("\n");
	
	int ql1,ql2;
	scanf("%d %d",&ql1,&ql2);	
	int r1,r2;
	scanf("%d %d",&r1,&r2);
	int s=sum(r1,r2,0,N-1,0);
	int b=max(r1,r2,0,N-1,0,s);
	printf("%d\n",b);
	return 0;
	
}

