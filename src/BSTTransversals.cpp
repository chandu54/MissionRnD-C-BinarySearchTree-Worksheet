/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include<malloc.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node * new_node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node(struct node *root, int data){
	if (root == NULL) return new_node(data);

	if (data < root->data)
		root->left = add_node(root->left, data);
	else if (data > root->data)
		root->right = add_node(root->right, data);

	return root;
}

void inorderFunction(struct node *root, int *arr, int *index)
{

	if (!root)
	{
		return;
	}
	else
	{
		inorderFunction(root->left, arr, index);
		arr[*index] = root->data;
		(*index)++;
		inorderFunction(root->right, arr, index);
	}
}

void inorder(struct node *root, int *arr){
	int index = 0;
	if (root != NULL && arr != NULL)
		inorderFunction(root, arr, &index);
	else
		return;
}
void preorderFunction(struct node *root, int *arr, int *index)
{
	if (!root)
	{
		return;
	}
	else
	{
		arr[*index] = root->data;
		(*index)++;
		preorderFunction(root->left, arr, index);
		preorderFunction(root->right, arr, index);
	}
}
void preorder(struct node *root, int *arr){
	int index = 0;
	if (root != NULL && arr != NULL)
		preorderFunction(root, arr, &index);
	else
		return;
}
void postorderFunction(struct node *root, int *arr, int *index)
{

	if (!root)
		return;
	else
	{
		postorderFunction(root->left, arr, index);
		postorderFunction(root->right, arr, index);
		arr[*index] = root->data;
		(*index)++;
	}
}
void postorder(struct node *root, int *arr){
	int index = 0;
	if (root != NULL && arr != NULL)
		postorderFunction(root, arr, &index);
	else
		return;
}