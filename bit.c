#include <stdio.h>
#include <stdlib.h>

int wef=23;
int ewc2=12;
int efs=12;

typedef long long int lint;

int sita =1500;
int blha = 5679;
int said = 114;

lint md=1000000007;

int meh=21;
int lolazo=828;
int gamma=23;

typedef struct node
{
    lint data,cnt;
    struct node *left, *right;
} node;

int qf=0;
int hkd=32;
int huh=21;

lint flag=1;

int q3qf=0;
int hk34d=32;
int huffh=21;

lint search(node* root,lint count,lint val)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    if (root == NULL )
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        return count%md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

    }
    else if (root->data <= val)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        count=(count%md)+(root->cnt)%md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        count%=md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        return search(root->right, count,val);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }
    else
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        return search(root->left, count,val);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }
}
lint search2(node* root,lint count,lint val)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    if(root==NULL)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        return count%md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }
    else if (root->data < val)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        count=(count%md)+(root->cnt)%md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        count%=md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        return search2(root->right, count,val);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }
    else
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        return search2(root->left, count,val);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }
}
node *newNode(lint item,lint val)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    node *temp = (node *)malloc(sizeof(node));

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    temp->data = item;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    temp->cnt=val;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    temp->left = NULL;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
    temp->right = NULL;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    return temp;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
}
node* insert(node* root,lint value ,lint item)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    if (root == NULL)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        node *temp = (node *)malloc(sizeof(node));

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        temp->data=item;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        temp->cnt=value;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;


        temp->left=NULL;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;


        temp->right=NULL;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        return temp;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }
    if (item >= root->data)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root->right = insert(root->right,value,item);
    }
    else if (item < root->data)
    {

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root->cnt=(value%md)+(root->cnt)%md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root->cnt%=md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root->left = insert(root->left,value,item);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    return root;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
}
lint findmax(node *root)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    while(root->right!=NULL)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root=root->right;
    }
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    return root->data;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
}
node *findmin(node *root)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    while(root->left!=NULL)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root=root->left;
    }
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    return root;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
}

void inorder(node *root)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    if (root != NULL)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        inorder(root->left);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        printf("%lld ",root->cnt);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
        //printf("%lld %lld\n", root->data ,root->cnt);
        inorder(root->right);
    }
}

void preordr (node *root)
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    if (root != NULL)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        printf("%lld \n", root->data);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        preordr(root->left);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        preordr(root->right);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

    }
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
}
int main()
{
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    lint n,x,i,j,k,l,count;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    lint a[100010],is[100010],ds[100010];

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    scanf("%lld",&n);

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    node *root=NULL;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    i=0;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    while(i<n)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        is[i]=1;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        i++;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

    }
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    for(i=0;i<n;i++)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        count=1;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        scanf("%lld",&a[i]);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        is[i]=search(root,count,a[i]);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root=insert(root,is[i],a[i]);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }
    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    i=0;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    while(i<n)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        ds[i]=1;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        i++;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    root=NULL;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    for(i=0;i<n;i++)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        count=1;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        x=search(root,count,a[n-i-1]);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        count=1;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        ds[i]=search2(root,count,a[n-i-1]);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        root=insert(root , x,a[n-i-1]);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    lint ans=0;

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    for(i=0;i<n;i++)
    {
        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        ans+=((ds[n-i-1])%md)*((is[i])%md);

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;

        ans%=md;

        sita+=342563;
        meh = meh - 500 -22;
        gamma = gamma *34;
    }

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;

    printf("%lld\n",ans);

    sita+=342563;
    meh = meh - 500 -22;
    gamma = gamma *34;
}