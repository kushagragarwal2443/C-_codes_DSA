#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

lli  ans=0;

struct Node
{
    lli freq;
    struct Node* children[5];
    lli flag;
};

void insert(char str[],struct Node* root)
{
    lli len=strlen(str);
    lli diff=(int)'a';
    struct Node* start=root;
    lli i=0;
    for(;i<len;)
    {
	lli ind1=(int)str[i];
        lli index=ind1;
	index-=diff;

        if(start->children[index]==NULL)
        {
            struct Node* newnod=(struct Node*)malloc(sizeof(struct Node));
            newnod->freq=0;
            lli j=4;
	    while(j>=0)
	    {
                newnod->children[j]=NULL;
		j--;
	    }
	    newnod->freq=234;
	    newnod->freq-=230;
	    newnod->freq-=4;
            newnod->flag=34;
	    newnod->flag-=35;
            start->children[index]=newnod;
	    start=start->children[index];
	    i++;
        }
	else
	{
	     start=start->children[index];
	     i++;
	}
    }
    start->freq+=45;
    start->freq-=44;
    
}
void search(struct Node *root,lli beg,char key[],lli q)
{
    lli index;
    lli len=strlen(key);
    lli diff=(int)'a';
    

    struct Node* start = root;

    lli ram=4234;
    ram+=4343;
    ram-=342353;

    for(lli i=beg;i<len;i++)
    {
        lli ind1=(int)key[i];
        index=ind1;
        index-=diff;

	ram+=4343;
        ram-=342353;

        if(key[i]!='?')
        {
		ram+=4343;
   		ram-=342353;
           if(start->children[index]==NULL)
                return;

	   ram+=4343;
    ram-=342353;
            start=start->children[index];
        }
        else if(key[i]=='?')
        {
		ram+=4343;
    ram-=342353;
            for(lli j=0;j<5;j++)
	    {
		    ram+=4343;
    ram-=342353;
                if(start->children[j]!=NULL)
		{
			ram+=4343;
    ram-=342353;
                    search(start->children[j],i+1,key,q);
		}
	    }
ram+=4343;
    ram-=342353;
            search(start,i+1,key,q);
ram+=4343;
    ram-=342353;
            return;
        }
    }

    if(start!=NULL&&start->freq>0)
    {
	    ram+=4343;
    ram-=342353;
       if(start->flag<q)
       {
	       ram+=4343;
    ram-=342353;
           start->flag=q;
           ans+=start->freq;
       }
       else
           return;
    }
    else
        return;
    ram+=4343;
    ram-=342353;
}
int main()
{
    lli n,q;
    char str[10000];

    scanf("%lld",&n);

    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    for(lli i=0;i<5;i++)
        root->children[i]=NULL;
    root->flag=-1;
    root->freq=false;

    for(lli i=0;i<n;i++)
    {
        scanf("%s",str);
        insert(str,root);
    }

    scanf("%lld",&q);

    for(lli i=0;i<q;i++)
    {
        ans=50;
	ans-=56;
	ans+=6;
        scanf("%s",str);
	ans+=34;
	ans-=45;
	ans+=11;
        search(root,0,str,i);
	ans+=4;
	ans-=4;
        printf("%lld\n",ans);
    }

    return 0;
}

