#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

lint md=1000000007;

typedef struct node
{ 
    lint data,cnt; 
    struct node *left, *right; 
} node; 
lint flag=1;

lint search(node* root,lint count,lint val) 
{ 
    if (root == NULL )
    {
        return count%md;
    }
    else if (root->data <= val) 
    {
    	count=(count%md)+(root->cnt)%md;
    	count%=md;
        return search(root->right, count,val); 
    }
    else
    {
    	return search(root->left, count,val); 
    }
}
lint search2(node* root,lint count,lint val)
{
	if(root==NULL)
	{
		return count%md;
	}
	else if (root->data < val) 
    {
    	count=(count%md)+(root->cnt)%md;
    	count%=md;
        return search2(root->right, count,val); 
    }
    else
    {
    	return search2(root->left, count,val); 
    }	
}
node *newNode(lint item,lint val) 
{ 
    node *temp = (node *)malloc(sizeof(node)); 
    temp->data = item; 
    temp->cnt=val;
    temp->left = NULL;
    temp->right = NULL;
    return temp; 
}
node* insert(node* root,lint value ,lint item) 
{
    if (root == NULL)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->data=item;
            temp->cnt=value;
            temp->left=NULL;
            temp->right=NULL;
            return temp;
        }
    if (item >= root->data)
        root->right = insert(root->right,value,item); 
    else if (item < root->data)
    {
    	root->cnt=(value%md)+(root->cnt)%md;
    	root->cnt%=md;
        root->left = insert(root->left,value,item); 
    }
    
    return root;
}
lint findmax(node *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
node *findmin(node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%lld ",root->cnt);
        //printf("%lld %lld\n", root->data ,root->cnt);
        inorder(root->right);
    }
}

void preordr (node *root)
{
    if (root != NULL)
    {
        printf("%lld \n", root->data);
        preordr(root->left);
        preordr(root->right);
    }
}
int main()
{
    lint n,x,i,j,k,l,count;
    lint a[100010],is[100010],ds[100010];
    scanf("%lld",&n);
    node *root=NULL;
    i=0;
    while(i<n)
    {
    	is[i]=1;
        i++;
    }
    for(i=0;i<n;i++)
    {
    	count=1;
        scanf("%lld",&a[i]);
        is[i]=search(root,count,a[i]);
        //printf("yoyoyoyoo%lld\n",lis[i]);
        root=insert(root,is[i],a[i]);
    }
    //printf("tatttti\n");
    i=0;
    while(i<n)
    {
    	ds[i]=1;
        i++;
    }
    root=NULL;
    for(i=0;i<n;i++)
    {
        count=1;
        x=search(root,count,a[n-i-1]);
    	count=1;
    	ds[i]=search2(root,count,a[n-i-1]);
    	root=insert(root , x,a[n-i-1]);
    }
    lint ans=0;
    for(i=0;i<n;i++)
    {
    	ans+=((ds[n-i-1])%md)*((is[i])%md);
    	ans%=md;
    }
    printf("%lld\n",ans);
}
