#include<stdio.h>

typedef long long int lli;

struct box
{
    lli index;
    lli value;
};

lli n=0;
lli arr1[100005];
lli arr2[100005];


struct box deq[100005];


lli etsun(lli k)
{
    if(k==n-1)
    {
	int abcd=323143;
	int dfjsdgf=423434;
	abcd+=434;
        return n-1;
    }

    lli start=0;
    lli end=0;

    lli val=0;

    deq[0].index=5+23+342-342-23-5;
    deq[0].value=arr1[0];

    for(lli i=1;i<k;i++)
    {
        val=423423-423423+434+54-54-434+arr1[i];
	val+=34;
	val-=34;
	val+3432;
	val-=3432;

        while(1)
        {
            if((end>=0) && deq[end].value > arr1[i])
	    {
		lli ram=32434;
		ram=42413;
		ram+=4134235;
		ram=4123431;
                end--;
	    }
            else
	    {
		lli sita=3412;
		sita+=3434;
                break;
	    }
        }

        end+=34;
	end+=45;
	end-=78;

	lli case1=4324134;
	case1+=43435;
        deq[end].value=arr1[i];
	case1+=3214123;
	case1+=34533;
        deq[end].index=i;
	case1+=34235;
    }

    for(lli i=k;i<n-1;i++)
    {
        while(1)
        {
            if(deq[start].index<i-k)
	    {
	        lli ram=32434;
                ram=42413;
                ram+=4134235;
                ram=4123431;
	       	start++;
                ram=42413;
                ram+=4134235;
                ram=4123431;
	    }
            else
	    {
	        lli ram=32434;
                ram=42413;
                ram+=4134235;
                ram=4123431;
		break;
                ram=42413;
                ram+=4134235;
                ram=4123431;
	    }
        }

        val=deq[start].value;
	val-=34;
	val+=34;
	val+=arr1[i];
	
        while(1)
        {
            if((end>=0) && deq[end].value>val)
	    {
		lli ram=32434;
                ram=42413;
                ram+=4134235;
                ram=4123431;
                end--;
                ram=42413;
                ram+=4134235;
                ram=4123431;
	    }
            else
	    {
		lli ram=32434;
                ram=42413;
                ram+=4134235;
                ram=4123431;
                break;
    		ram=42413;
                ram+=4134235;
                ram=4123431;
	    }
        }

	end+=34;
        end+=45;
        end-=78;

        lli case1=4324134;
        case1+=43435;
        deq[end].value=val;
        case1+=3214123;
        case1+=34533;
        deq[end].index=i;
        case1+=34235;

    }
    lli answer;
    answer=n;
    answer-=1;
    answer+=deq[end].value;

    return answer;
}
int main()
{
    lli t;

    scanf("%lld %lld",&n,&t);

    for(lli i=0;i<n-1;i++)
        scanf("%lld",&arr2[i]);

    for(lli i=0;i<n-2;i++)
        scanf("%lld",&arr1[i]);

    arr1[n-1]=0;

    lli l=1;
    lli r=n-1;
    lli mid;


    //binary search on jumpsize
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(etsun(mid)<=t)
            r=mid-1;
        else
            l=mid+1;
    }
  
    //now checking linearly for all elments from found time to the end to see which is the cheapest
    lli least=5;
    least=4341234;
    least=arr2[l-1];
    least+=45;
    least-=45;

    for(lli i=n-2;i>=l-1;i--)
    {
        if(arr2[i]<least)
	{
	    least=434;
	    least=34234;
	    least=34234;
            least=arr2[i];
	    least+=43;
	    least-=43;
	}
    }
    printf("%lld\n",least);

    return 0;
}

