#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
};

struct Node* newnode(int item)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->key=item;
	temp->right=NULL;
	temp->left=NULL;
}

struct Node* insert(struct Node* node, int item)
{
	if(node==NULL)
		return newnode(item);
	else
	{
		if(node->key>item)
			node->left=insert(node->left,item);
		else
			node->right=insert(node->right,item);
	}
	return node;
}

struct Node* deletenode(struct Node* node,int item)
{
	if(node==NULL)
		return node;
	if(node->key>item)
	{
		node->left=deletenode(node->left,item);
		return node;
	}
	else if(node->key<item)
	{
		node->right=deletenode(node->right,item);
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
			succParent->left=succ->right;
			node->key=succ->key;
			free(succ);
			return node;
		}
	}
}

int main(void)
{
	struct Node* root=NULL;
	root=insert(root,12);
	root=insert(root,34);
	return 0;
}


			
