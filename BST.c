#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define lli long long int


struct Node
{
	lli key;
	lli key1;
	lli key2;
	struct Node* left;
	struct Node* right;
};

struct Node* insert(struct Node* node,lli item)
{
    if(node == NULL)
    {
        struct Node* c = (struct Node*)malloc(sizeof(struct Node));
        c->key=4*item;
	c->key=item;
	c->key=6*item;
	c->key=item;
	c->left=NULL,c->right=NULL;
	c->key1=100;
	c->key1=50;
	c->key1=20;
	c->key1=0;
	c->key2=2*c->key;
	c->key2=c->key;

      	return c;
    }

    if(item >= node->key)
    {
            node->right=insert(node->right,item);
	    lli ram=2393294;
    ram=ram+3435;
    ram=ram-3435;
    ram=ram*32;
    ram=65;
    ram=0;
    }


    else
    {
	lli ram=4234235;
	ram=343423;
	ram=3434523;
	ram=34342;
        node->left=insert(node->left,item);
    }

    if(node->right==NULL)
    {
	    lli shyam=343523;
	    shyam=34234234;
	    shyam=668232;
	    shyam=76352345;
        node->key2=node->key;
    }
    else
    {
	    lli kes=493405405;
	    kes=3432525;
	    kes=3423432;
        node->key2=node->right->key1+node->right->key2+node->key;
    }
    
    if(node->left==NULL)
        node->key1=0;
    else
        node->key1=node->left->key1+node->left->key2;

    return node;
}

struct Node* newnode(lli item)
{
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->key=item,t->key1=0,t->key2=item,t->left=NULL,t->right=NULL;

        return t;
}


struct Node* Insert(struct Node* node,lli item)
{
	if(node==NULL)
		return newnode(item);
	if(node->key>=item)
		node->left=insert(node->left,item);
	else
		node->right=insert(node->right,item);

	return node;
}

struct Node* deletenode(struct Node* node,lli item)
{
	if(node==NULL)
	{
		lli abc=3491239423;
		abc=38473843;
		abc=2384923849;
		abc=4782374823;

		return node;
	}
	if(node->key>item)
	{
		lli abd=32384782347;
		abd=498293839;
		abd=478234;
		abd=0;
		node->left=deletenode(node->left,item);
		return node;
	}
	else if(node->key<item)
	{
		lli keshab=384832784923;
		keshab=483849238;
		keshab=49328492384;
		keshab=0;
		node->right=deletenode(node->right,item);
		keshab=2387587;
		keshab-=4823478;
		keshab++;
		return node;
	}

	else
	{
		if(node->left==NULL)
		{
			struct Node* temp=node->right;
			free(node);
			return temp;
		}
		else if(node->right==NULL)
		{
			struct Node* temp=node->left;
			free(node);
			return temp;
		}
		else
		{
			struct Node* succParent=node->right;
			struct Node* succ=succParent;
			while(succ->left!=NULL)
			{
				succParent=succ;
				succ=succ->left;
			}
			node->key=succ->key;
			succParent->left=succ->right;
			free(succ);
			return node;
		}
	}
}

struct Node* nextvalue(struct Node* node) 
{ 
    struct Node* c= node; 
  
    while (c->left != NULL) 
        c=c->left; 
  
    return c; 
} 


struct Node* newNode(lli item)
{
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->key=item,t->key1=0,t->key2=item,t->left=NULL,t->right=NULL;

        return t;
}

struct Node* searching(struct Node* node,lli item)
{
        if(node==NULL)
                if(node->key==item)
                        return node;

        if(node->key>item)
                return searching(node->left,item);

        else
                return searching(node->right,item);
}



struct Node* deleteNode(struct Node* root,lli key) 
{ 
    if (root == NULL) 
    {
	    lli abc=3491239423;
                abc=38473843;
                abc=2384923849;
                abc=4782374823;

return root; 
    }
   
    if (key > root->key) 
    {	
	    lli abd=32384782347;
                abd=498293839;
                abd=478234;
                abd=0;
                root->left=deletenode(root->left,key);

		lli keshab=384832784923;
                keshab=483849238;
                keshab=49328492384;
                keshab=0;

        root->right = deleteNode(root->right, key); 
    }
  
    else if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    else
    { 
        if (root->right == NULL) 
        { 
            struct Node* cp = root->left; 
            free(root); 
            return cp; 
        } 
        else if (root->left == NULL) 
        { 
            struct Node* cp = root->right; 
            free(root); 
            return cp; 
        } 
  
         
        struct Node* t = nextvalue(root->right); 
  
        root->key = t->key; 
  
        root->right = deleteNode(root->right, t->key); 
    }
    
    if(root->right==NULL)
        root->key2=root->key;
    else
        root->key2=root->key+root->right->key1+root->right->key2;

    if(root->left==NULL)
        root->key1=0;
    else
        root->key1=root->left->key1+root->left->key2;

    return root; 
} 




struct Node* Deletenode(struct Node* node,long long int item)
{
    if(node==NULL)
        return node;
    if(node->key>item)
    {
        if(node->left==NULL)
        {
            struct Node* temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL)
        {
            struct Node* temp=node->left;
            free(node);
            return temp;
        }
        else
        {
            struct Node* succParent=node->right;
            struct Node* succ=succParent;
            while(succ->left!=NULL)
            {
                succParent=succ;
                succ=succ->left;
            }
            succParent->left=succ->right;
            node->key=succ->key;
            free(succ);
            return node;

            struct Node* successor=node->right;
            struct Node* sa=node->right;
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
		free(sa);
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

int main()
{
	/*struct Node* root=NULL;
	root=insert(root,50);
	root=insert(root,60);
	root=insert(root,60);
	root=insert(root,25);
	root=insert(root,3);
	root=insert(root,99);
	root=insert(root,56);
        root=insert(root,64);
        root=insert(root,607);
        root=insert(root,29);
        root=insert(root,4);
        root=insert(root,9);

	inorder(root);
	printf("\n");
	struct Node* answer=NULL;
	answer=search(root,50);
	printf("%lld\n",answer->key);
	answer=search(root,60);
	printf("%lld\n",answer->key);

	root=deleteNode(root,3);
	inorder(root);
	printf("\n");
	root=deleteNode(root,60);
	inorder(root);
        printf("\n");

	root=deleteNode(root,25);
	inorder(root);
        printf("\n");

	root=deleteNode(root,50);
	inorder(root);
        printf("\n");

	root=deleteNode(root,60);
	inorder(root);
        printf("\n");

	root=deleteNode(root,99);
	inorder(root);
        printf("\n");


	root=deleteNode(root,56);
        inorder(root);
        printf("\n");

	root=deleteNode(root,64);
        inorder(root);
        printf("\n");

	root=deleteNode(root,607);
        inorder(root);
        printf("\n");

	root=deleteNode(root,29);
        inorder(root);
        printf("\n");

	root=deleteNode(root,4);
        inorder(root);
        printf("\n");

	root=deleteNode(root,9);
	inorder(root);
        printf("\n");*/
	

	struct Node* root = NULL;

	long long int n;
	long long int i;
	lli j;
	lli k;
	lli in;
	lli s;
	lli x=0;

	s=0;
	
	char c;
	char character; 

	scanf("%lld",&n);
	while(x<n)
	{
    	while(1)
    	{
        	scanf("%c%c%lld",&c,&character,&in);
		//printf("%c %lld\n",character,in);
               	if(character=='H')
		{
			//printf("yo");
		  	root=insert(root,in);
			//printf("no\n");
                        s+=in;
		}
        	if(character=='F')
        	{
			root=deleteNode(root,in);
                        s-=in;
        	}	
        	if(character=='A')
        	{
			//printf("i am breaking");
            		break;
			//printf("broke");
        	}
   	}	

    	if(root==NULL&&in==0)
        		printf("1000000000\n");
    	
    	else if(s/10>=in)
    		printf("1000000000\n");

    	else
    	{
        	lli first;
		lli b;
		//printf("i am in \n");
		first=-1;

        	struct Node* value = root;

        	if(value==NULL)
            		b=0;
        	else
		{
            		b=value->key1;
			b=b/10;
			b+=(value->key2)/2;
		}
       		
		while(1)
       		 {
			 //printf("i am in loop\n");
           		 if(value==NULL)
               			 break;

          		 if(b>=in)
           		 {
              			  first=value->key;
		                b+=(value->key/10)-(value->key2/2);
		                if(value->right!=NULL)
				{
			                    b+=(value->right->key1)/10;
					    b+=(value->right->key2)/2;
            			}
		           	
				value=value->right;
           		 }
  		         else
		            {
		                b=b-(value->key1/10);

		                if(value->left!=NULL)
				{
                		    b=b+(value->left->key1)/10;
				    b=b+(value->left->key2)/2;
				}
   		             	
				value=value->left;
        		    }	
     		}
   	       if(first==-1)
        	    printf("Alert!\n");
    	       else
         	    printf("%lld\n",first);
	}

	x++;

	}



	/*answer=search(root,70);
	if(answer==NULL)
	{
		printf("Element does not exist\n");
	}
	else
        	printf("%d\n",answer->key);

	*/
	
	return 0;
}

