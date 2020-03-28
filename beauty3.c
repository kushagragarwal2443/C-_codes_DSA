#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

long long int ans=0;

struct trie_node
{
    struct trie_node *children[5];
    long long int eofw,flag;
};

void trie_insert(struct trie_node *root, char key[])
{
    long long int i,j,len,index;
    len=strlen(key);

    struct trie_node *start=root;

    for(i=0;i<len;i++)
    {
        index= ((int)key[i]-(int)'a');
        if(start->children[index]==NULL)
        {
            struct trie_node *temp=(struct trie_node *)malloc(sizeof(struct trie_node));
            temp->eofw=0;
            for(j=0;j<5;j++)
                temp->children[j]=NULL;
            temp->flag=-1;
            start->children[index]=temp;
        }

            start=start->children[index];
    }
    start->eofw++;
}
void trie_search(struct trie_node *root,long long int beg,char key[],long long int q)
{
    long long int i,j,index,len=strlen(key);
    struct trie_node *start = root;
    for(i=beg;i<len;i++)
    {
        index= ((int)key[i]-(int)'a');
        if(key[i]!='?')
        {
            index= ((int)key[i]-(int)'a');
       
            if(start->children[index]==NULL)
                return;

            start=start->children[index];
        }
        else if(key[i]=='?')
        {
            for(j=0;j<5;j++)
                if(start->children[j]!=NULL)
                    trie_search(start->children[j],i+1,key,q);

            trie_search(start,i+1,key,q);

            return;
        }
    }

    if(start!=NULL&&start->eofw>0)
        {
            if(start->flag<q)
            {
                start->flag=q;
                ans+=start->eofw;
            }
            else
                return;
        }
    else
        return;
}
int main()
{
    long long int i,j,k,n,q,len,count,ind1,ind2,ind3,p,r,temp,new;
    char str[10000],str2[10000],b[6]={'a','b','c','d','e',' '};
    struct trie_node *root=(struct trie_node *)malloc(sizeof(struct trie_node));
    root->eofw=false;
    for(i=0;i<5;i++)
        root->children[i]=NULL;
    root->flag=-1;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        trie_insert(root,str);
    }

    scanf("%lld",&q);
    for(i=0;i<q;i++)
    {
        ans=0;
        scanf("%s",str);
        trie_search(root,0,str,i);
        printf("%lld\n",ans);
    }
}






























