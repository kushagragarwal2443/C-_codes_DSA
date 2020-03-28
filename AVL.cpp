#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
	int height;
};

Node* insertNode(Node* root)
{
	Node* node=newnode();




int getheight(Node* head)
{
	return head == NULL ? 0 : head->height;
}

void updateheight(Node* head)
{
	head->height=max(getheight(head->left),getheight(head->right))+1;
}

Node* leftrotation(Node* head)
{
	Node * b=head->right;
	head->right=b->left;
	b->left=head;
	return b;
}

Node* rightrotation(Node* head)
{
	Node * b=head->left;
	head->left=b->right;
	b->right=head;
	return b;
}




