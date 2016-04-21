/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node *left_fix(struct node *root, int value)
{
	static struct node *temp = NULL;
	if (root == NULL)
		return temp;
	if (root->data > value)
		temp = root;
	else
	{
		left_fix(root->left, value);
		left_fix(root->right, value);
	}
	return temp;
}
struct node *right_fix(struct node *root, int value)
{
	 static struct node *temp1 = NULL;
	if (root == NULL)
		return temp1;
	if (root->data < value)
		temp1 = root;
	else
	{
		right_fix(root->left, value);
		right_fix(root->right, value);
	}
	return temp1;
}
void fix_bst(struct node *root){
	if (root!=NULL)
	{
		struct node *find_left;
		struct node *find_right;
		find_left = left_fix(root->left, root->data);
		find_right = right_fix(root->right, root->data);
		int temp = find_left->data;
		find_left->data = find_right->data;
		find_right->data = temp;
	}
}
