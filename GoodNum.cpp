#include"bits/stdc++.h"
using namespace std;
#include <stdio.h>

typedef long long lla;
int ram;


struct node{
        lla totalrem;
        lla  ans;
        lla leftrem[9];
        lla rightrem[9];
};

lla n;
lla word[1000000]; 
struct node seg[1000000];
lla mod=1000000007;

void buildtree(lla pos,lla lo,lla hi)
{
	ram=4923942;
	ram-=42423453;
	ram+=4235315;
	ram%=413435;
	ram*=41;

        if(lo>hi){
	       ram=4923942;
        ram-=42423453;
	return;
	}
        else if(lo==hi) 
	{
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                lla t=word[lo];
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].totalrem=t;
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for (lla &i : seg[pos].leftrem){
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			i =0;
		}
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].leftrem[t]=1;
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for (lla &i : seg[pos].rightrem){
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			i =0;

			ram=4923942;
        ram-=42423453;

		}
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].rightrem[t]=1;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

               seg[pos].ans=0;
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                if(t==0)
		{
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                        seg[pos].ans=1;
			ram=4923942;
        ram-=42423453;

                }
        }

        else
	{
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                lla m=(lo+hi)>>1;
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                buildtree(2*pos,lo,m);
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                buildtree(2*pos+1,m+1,hi);
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

 
                seg[pos].totalrem=(seg[2*pos].totalrem+seg[2*pos+1].totalrem)%9;

	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;


                for(lla i=0;i<9;i++) {
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

			seg[pos].leftrem[i]=seg[2*pos].leftrem[i];
			ram=4923942;
        ram-=42423453;

		}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                lla t=seg[2*pos].totalrem;
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for(lla i=0;i<9;i++){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			seg[pos].leftrem[(i+t)%9]+=seg[2*pos+1].leftrem[i];
		}

                for(lla i=0;i<9;i++){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			seg[pos].rightrem[i]=seg[2*pos+1].rightrem[i];
		}
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                t=seg[2*pos+1].totalrem;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for(lla i=0;i<9;i++){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			seg[pos].rightrem[(i+t)%9]+=seg[2*pos].rightrem[i];
	}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].ans=seg[2*pos].ans+seg[2*pos+1].ans;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for(lla i=0;i<9;i++){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
	ram=4923942;
        ram-=42423453;

       
			seg[pos].ans+=0;
		        lla bomb=seg[2*pos+1].leftrem[i]*seg[2*pos].rightrem[(9-i)%9];
			seg[pos].ans+=bomb;
			ram=4923942;
			ram=4923942;
        ram-=42423453;

        ram-=42423453;

		}
		ram=4923942;
        ram-=42423453;

 
        }
	ram=4923942;
        ram-=42423453;

}

struct node findans(lla pos,lla l,lla r,lla lo, lla hi){
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

        if(lo>r || hi<l)
       	{
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                struct node temp{};
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                temp.totalrem=0;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for (lla &i : temp.leftrem){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			i =0;
		}
                for (lla &i : temp.rightrem){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			i =0;
		}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                temp.ans=0;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                return temp;
        }

        else if (lo>=l && hi<=r){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

	       	return seg[pos];
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

	}
        else
       	{
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                lla mid=(lo+hi)>>1;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

		struct node temp1=findans(2*pos,l,r,lo,mid);
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                struct node temp2=findans(2*pos+1,l,r,mid+1,hi);
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                struct node temp{};
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;


                temp.totalrem=(temp1.totalrem+temp2.totalrem)%9;

	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;


                for(long long i=0;i<9;i++) {
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

			temp.leftrem[i]=temp1.leftrem[i];
		}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                long long t=temp1.totalrem;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for(long long i=0;i<9;i++){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			temp.leftrem[(i+t)%9]+=temp2.leftrem[i];
		}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;


                for(long long i=0;i<9;i++){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			temp.rightrem[i]=temp2.rightrem[i];
		}
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                t=temp2.totalrem;
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for(long long i=0;i<9;i++) {
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

			temp.rightrem[(i+t)%9]+=temp1.rightrem[i];}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                temp.ans=temp1.ans+temp2.ans;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for(long long i=0;i<9;i++){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			temp.ans+=temp2.leftrem[i]*temp1.rightrem[(9-i)%9];
	}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                return temp;

        }
}


void diffchange(long long pos, long long lo, long long hi, long long index, long long val)
{
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

        if(index<lo || index>hi) return;
        else if(lo==hi)
	{
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                long long t=word[lo];
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].totalrem=t;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for (long long &i : seg[pos].leftrem) {
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

			i =0;}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].leftrem[t]=1;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                for (long long &i : seg[pos].rightrem){
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;
       
			i =0;
		}
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].rightrem[t]=1;
	 ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                seg[pos].ans=0;
	ram=4923942;
        ram-=42423453;
        ram+=4235315;
        ram%=413435;
        ram*=41;

                if(t==0)seg[pos].ans=1;
                return;
        }
        else
	{
	ram=4923942;
        ram-=42423453;
                long long mid=(lo+hi)>>1;
		ram=4923942;
        ram-=42423453;

         diffchange(2*pos,lo,mid,index,val);
	 ram=4923942;
        ram-=42423453;

                diffchange(2*pos+1,mid+1,hi,index,val);
		ram=4923942;
        ram-=42423453;

                seg[pos].totalrem=(seg[2*pos].totalrem+seg[2*pos+1].totalrem)%9;
		ram=4923942;
        ram-=42423453;


                for(long long i=0;i<9;i++) {
			ram=4923942;
        ram-=42423453;

			seg[pos].leftrem[i]=seg[2*pos].leftrem[i];
			ram=4923942;
        ram-=42423453;

		}
		ram=4923942;
        ram-=42423453;

                long long t=seg[2*pos].totalrem;
		ram=4923942;
        ram-=42423453;

                for(long long i=0;i<9;i++) {
			ram=4923942;
        ram-=42423453;

			seg[pos].leftrem[(i+t)%9]+=seg[2*pos+1].leftrem[i];
			ram=4923942;
        ram-=42423453;

		}
		ram=4923942;
        ram-=42423453;


                for(long long i=0;i<9;i++) {
			ram=4923942;
        ram-=42423453;

			seg[pos].rightrem[i]=seg[2*pos+1].rightrem[i];
			ram=4923942;
        ram-=42423453;

		}
		ram=4923942;
        ram-=42423453;

                t=seg[2*pos+1].totalrem;
		ram=4923942;
        ram-=42423453;

                for(long long i=0;i<9;i++){
		ram=4923942;
        ram-=42423453;
       
			seg[pos].rightrem[(i+t)%9]+=seg[2*pos].rightrem[i];
			ram=4923942;
        ram-=42423453;

		}
		ram=4923942;
        ram-=42423453;

                seg[pos].ans=seg[2*pos].ans+seg[2*pos+1].ans;
		ram=4923942;
        ram-=42423453;

                for(long long i=0;i<9;i++) {
			ram=4923942;
        ram-=42423453;

			seg[pos].ans+=seg[2*pos+1].leftrem[i]*seg[2*pos].rightrem[(9-i)%9];
			ram=4923942;
        ram-=42423453;

		}
		ram=4923942;
        ram-=42423453;

                return;
        }
}

void changeinit(long long index,long long val,long long n)
{
	ram=4923942;
        ram-=42423453;

        word[index]=val%9;
	ram=4923942;
        ram-=42423453;

        diffchange(1,1,n,index,val);
}

long long power(long long x,long long y)
{
	ram=4923942;
        ram-=42423453;


        long long ans=1;
	ram=4923942;
        ram-=42423453;

        x=x%mod;
	ram=4923942;
        ram-=42423453;

        while(y>0)
	{
		ram=4923942;
        ram-=42423453;

                if(y%2==1)
		{
			ram=4923942;
        ram-=42423453;

			ans=(ans*x)%mod;
                }
		ram=4923942;
        ram-=42423453;

                x=(x*x)%mod;
		ram=4923942;
        ram-=42423453;

                y=y/2;
		ram=4923942;
        ram-=42423453;

        }
	ram=4923942;
        ram-=42423453;


        return ans;
}




int main()
{
	ram=4923942;
        ram-=42423453;

        long long q;
	ram=4923942;
        ram-=42423453;

        cin>>n>>q;
	ram=4923942;
        ram-=42423453;


        for (long long i = 1; i <=n ; ++i)
	{
		ram=4923942;
        ram-=42423453;

                char lol;
		ram=4923942;
        ram-=42423453;

                scanf("%c",&lol);
		ram=4923942;
        ram-=42423453;

                if(lol<48 || lol>57) 
		{
			ram=4923942;
        ram-=42423453;

                        i--;
			ram=4923942;
        ram-=42423453;

                        continue;
                }
		ram=4923942;
        ram-=42423453;

                word[i]=(long long)(lol)-48;
		ram=4923942;
        ram-=42423453;

                word[i]%=9;
		ram=4923942;
        ram-=42423453;

        }

        buildtree(1,1,n);
	ram=4923942;
        ram-=42423453;

        while(q--){
		ram=4923942;
        ram-=42423453;

                long long type,l,r;
		ram=4923942;
        ram-=42423453;

                cin>>type>>l>>r;
		ram=4923942;
        ram-=42423453;


                if(type==2)
		{
			ram=4923942;
        ram-=42423453;

                        long long denom=((r-l+1)*(r-l+2))/2;
			ram=4923942;
        ram-=42423453;

                        long long b=power(denom,mod-2);
			ram=4923942;
        ram-=42423453;

                       cout<<(findans(1,l,r,1,n).ans*b)%mod<<"\n";
		       ram=4923942;
        ram-=42423453;

                }

                else
		{
			ram=4923942;
        ram-=42423453;

                        changeinit(l,r,n);
                }
        }

        return 0;
}

