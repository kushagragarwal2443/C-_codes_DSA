#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};
struct Node* mynode(int value)
{
	struct Node* a=(struct Node*)malloc(sizeof(struct Node));
	a->key=value;
	a->left=NULL;
	a->right=NULL;
	return a;
}

struct Node* insertNode(struct Node* z,int value)
{
	if(z==NULL)
		return mynode(value);
	else
	{
		if(value<z->key)
			z->left=insertNode(z->left,value);
		else
			z->right=insertNode(z->right,value);
	}
	return z;
}
struct Node* inordertraversal(struct Node* root)
{
	if(root!=NULL)
	{
		inordertraversal(root->left);
		printf("%d ",root->key);
		inordertraversal(root->right);
	}
}
int sumelements(struct Node* root, int val)  
{
	if(root != NULL )
	{
		int a,b;
		a=sumelements(root->left,val);
		b=sumelements(root->right,val);
		val=a+b+root->key;
		printf("%d ",val);
		return val;
	}
	else
	{
		return 0;
	}
}

int main(void)
{

	struct Node* root=NULL;
	root=insertNode(root,10);
	insertNode(root,7);
	insertNode(root,15);
	insertNode(root,3);
	insertNode(root,8);
	insertNode(root,11);
	insertNode(root,17);

	inordertraversal(root);
	int c=sumelements(root,0);


	return 0;
}





