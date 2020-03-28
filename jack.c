#include<stdio.h>

struct appy
{
    long long int ind;
    long long int val;
};

struct appy stck[100002];

long long int arr[100002];

long long int arr2[100002];

long long int mint(long long int k,long long int n)
{
    if(k==n-1)
        return n-1;

    long long int start=0,end=0,i,j,ans,value;
     stck[end].val=arr[0];
    stck[end].ind=0;

    for(i=1;i<k;i++)
    {
        value=arr[i];

        for(;;)
        {
            if((end>=0) && stck[end].val > value)
                end--;
            else
                break;
        }
        end++;
        stck[end].val=value;
        stck[end].ind=i;
    }

    for(i=k;i<n-1;i++)
    {
        for(;;)
        {
            if(stck[start].ind<i-k)
                start++;
            else
                break;
        }

        value=arr[i]+stck[start].val;

        for(;;)
        {
            if((end>=0) && stck[end].val>value)
                end--;
            else
                break;
        }
        end++;
        stck[end].val=value;
        stck[end].ind=i;
    }
    return stck[end].val+n-1;
}
int main()
{
/*
    arr[0]=1;
    arr[1]=3;
    arr[2]=2;
    arr[3]=5;
    arr[4]=6;
    arr[5]=8;
    arr[6]=0;

    printf("%lld\n",mint(3,8));
    */

    long long int i,j,k,n,t,ans=100000000000,min,temp,l,r,m;
    scanf("%lld%lld",&n,&t);

    for(i=0;i<n-1;i++)
        scanf("%lld",&arr2[i]);
    for(i=0;i<n-2;i++)
        scanf("%lld",&arr[i]);

    l=1;
    r=n-1;
    arr[n-1]=0;
    for(;;)
    {
        if(l>r)
            break;

        m=(l+r)/2;
        printf("bin %lld\n",mint(m,n));
        if(mint(m,n)>t)
            l=m+1;
        else
            r=m-1;
    }
    printf("%lld\n",l);
    min=arr2[l-1];
    for(i=l-1;i<n-1;i++)
    {
        if(arr2[i]<min)
            min=arr2[i];
    }

    printf("%lld\n",min);

    return 0;
}
