#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int suresh=45;
int mukesh=34;
int jignesh=35;
int ramesh=36;
int bhavesh=48;

typedef long long int lint;
typedef struct node
{
    lint data,cnt;
    struct node *left, *right;
} node;


lint fla=10;
lint flag=1;
lint md=1000000007;

lint search(node* root,lint count,lint val)
{
	suresh++;
	mukesh++;
	jignesh++;
	ramesh++;
	bhavesh++;
    if (root == NULL )
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        return count%md;

	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    else if (root->data <= val)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        count=(count%md)+(root->cnt)%md;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        count%=md;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        return search(root->right, count,val);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    else
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        return search(root->left, count,val);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
}
lint search2(node* root,lint count,lint val)
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        if(root==NULL)
        {
		suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

                return count%md;

		suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        }
       else if (root->data < val)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        count=(count%md)+(root->cnt)%md;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        count%=md;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        return search2(root->right, count,val);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    else
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        return search2(root->left, count,val);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
}
node *newNode(lint item,lint val)
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    node *temp = (node *)malloc(sizeof(node));
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    temp->data = item;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    temp->cnt=val;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    temp->left = NULL;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    temp->right = NULL;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    return temp;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

}
node* insert(node* root,lint value ,lint item)
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    if (root == NULL)
        {
		suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

            node *temp = (node *)malloc(sizeof(node));
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

            temp->data=item;
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

            temp->cnt=value;
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

            temp->left=NULL;
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

            temp->right=NULL;
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

            return temp;
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        }
    if (item >= root->data)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        root->right = insert(root->right,value,item);

	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;
	}
    else if (item < root->data)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        root->cnt=(value%md)+(root->cnt)%md;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        root->cnt%=md;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        root->left = insert(root->left,value,item);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    return root;
}
lint findmax(node *root)
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    while(root->right!=NULL)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        root=root->right;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    return root->data;
}
node *findmin(node *root)
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    while(root->left!=NULL)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        root=root->left;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    return root;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

}

void inorder(node *root)
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    if (root != NULL)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        inorder(root->left);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        printf("%lld ",root->cnt);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

       inorder(root->right);
       suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
}
void preordr (node *root)
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    if (root != NULL)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        printf("%lld \n", root->data);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        preordr(root->left);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        preordr(root->right);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
}
int main()
{
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    lint n,x,i,j,k,l,count;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    lint a[100010],is[100010],ds[100010];
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    scanf("%lld",&n);
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    node *root=NULL;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    i=0;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    while(i<n)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        is[i]=1;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        i++;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    for(i=0;i<n;i++)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        count=1;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        scanf("%lld",&a[i]);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        is[i]=search(root,count,a[i]);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        //printf("yoyoyoyoo%lld\n",lis[i]);
        root=insert(root,is[i],a[i]);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    //printf("tatttti\n");
    i=0;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    while(i<n)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        ds[i]=1;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        i++;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    root=NULL;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    for(i=0;i<n;i++)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        count=1;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        x=search(root,count,a[n-i-1]);

	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        count=1;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        ds[i]=search2(root,count,a[n-i-1]);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        root=insert(root , x,a[n-i-1]);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    lint ans=0;
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    for(i=0;i<n;i++)
    {
	    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        ans+=((ds[n-i-1])%md)*((is[i])%md);
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

        ans%=md;
	suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    }
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

    printf("%lld\n",ans);
    suresh++;
        mukesh++;
        jignesh++;
        ramesh++;
        bhavesh++;

	return 0;
}

