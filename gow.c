#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long int a1[100005];
long long int a2[100005];
long long int arr[100005];
long long int values[100005];
long long int sorted[100005];

struct MyNode
{
	long long int key;
	struct MyNode* left;
	struct MyNode* right;
};

struct MyNode* deleteNode(struct MyNode* node,long long int item)
{
    if(node==NULL)
        return node;
    if(node->key>item)
    {
        node->left=deleteNode(node->left,item);
        return node;
    }
    else if(node->key<item)
    {
        node->right=deleteNode(node->right,item);
        return node;
    }
    else
    {
        if(node->left==NULL)
        {
            struct MyNode* temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL)
        {
            struct MyNode* temp=node->left;
            free(node);
            return temp;
        }
        else
        {
            /*struct MyNode* succParent=node->right;
            struct MyNode* succ=succParent;
            while(succ->left!=NULL)
            {
                succParent=succ;
                succ=succ->left;
            }
            succParent->left=succ->right;
            node->key=succ->key;
            free(succ);
            return Mynode;*/

            struct MyNode* successor=node->right;
            struct MyNode* sa=node->right;
            long long int sum=0;
            while(successor->left!=NULL)
            {
                sum++;
                sa=successor;
                successor=successor->left;
            }
            if(sum==0&&successor->right==NULL)
            {
                node->key=successor->key;
                free(successor);
                return node;
            }
            else if(sum==0&&successor->right!=NULL)
            {
                node->key=successor->key;
                successor->key=successor->right->key;
                free(successor->right);
                return node;
            }
            else if(sum!=0 && successor->right!=NULL)
            {
                node->key=successor->key;
                successor->key=successor->right->key;
                free(successor->right);
                return node;
            }
            else
            {

                node->key=successor->key;
                sa->left=NULL;
                free(successor);
                return node;
            }

        }

    }
}


void Merge(long long int arr[],long long int l,long long int m,long long int r)
{
        long long int size=r-l+1;
        long long int K[size];
        //temporary array used is K from indices 0 to size-1
        long long int i=l;
        long long int j=m+1;
	
	//filling values until which the respective midpoints are not overflowed with values
        for(long long int z=0;z<size;z++)
        {
                if(i<=m&&j<=r)
                {
                if(arr[i]<arr[j])
                {
                        K[z]=arr[i];
                        i++;
                }
                else
                {
                        K[z]=arr[j];
                        j++;
                }
                }
                else
                {
			//either of i or j have overflowed values
                        if(i>m)
                        {
				//if i has overflowed then simply copy j into the array
                                for(long long int yo=j;yo<=r;yo++)
                                {
                                        K[z]=arr[yo];
                                        z++;
                                }
                                break;
                        }
                        else
			{
				//else copy i into the array
                                for(long long int yo=i;yo<=m;yo++)
                                {
                                        K[z]=arr[yo];
                                        z++;
                                }
                                break;
                        }
                }
        }
	
	//storing all the values back into the original array
        for(long long int z=0;z<size;z++)
        {
                arr[l+z]=K[z];
        }
}

void MergeSort(long long int arr[],long long int l,long long int r)
{
        if(l<r)
        {
		//this representation allows the prevention of integer overflow
                long long int m=l+(r-l)/2;

		//recursion used to sort the array
                MergeSort(arr,l,m);
                MergeSort(arr,m+1,r);

		//merge the output of the two recursive calls
                Merge(arr,l,m,r);
        }
}

int main(void)
{
	long long int n,t,k;
	scanf("%lld %lld %lld",&n,&t,&k);

	for(long long int i=0;i<n;i++)
		scanf("%lld",&values[i]);

	//to find the subarray with the highest sum
	
	long long int c,d,index;
	long long int i=0;
	c=0;
	d=0;
	index=0;

	for(;i<t;)
	{
		c=c+values[i];
		d=d+values[i];
		i++;
	}

	for(long long int m=1;m<n-t+1;m++)
	{
		d=d-values[m-1]+values[m+t-1];
		if(d>c)
		{
			c=d;
			index=m;
		}
	}
	
	long long int j=index;
	
	for(;j<index+t;)
	{
		arr[j-index]=values[j];
		j++;
	}
	
	MergeSort(arr,0,t-1);

	//for(long long int s=0;s<t;s++)
	//{
	//	printf("%lld ",arr[s]);
	//}
	
	long long int r=t-k;
	
	long long int finalanswer;

	finalanswer=0;

	for(;r<t;)
	{
		finalanswer=finalanswer+arr[r];
		r++;
	}

	printf("%lld\n",finalanswer);


	return 0;
}

	





