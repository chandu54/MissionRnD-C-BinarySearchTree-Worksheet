/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
#include<malloc.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node*construct_Arr_to_BST(struct node*root, int *arr, int begindex, int lastindex)
{
	struct node*temp;
	int position = (begindex + lastindex) / 2;
	if (begindex > lastindex)
		return NULL;
	if (begindex == lastindex)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->data = arr[position];
			temp->left = NULL;
			temp->right = NULL;
		}
		else
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->data = arr[position];
			temp->left = construct_Arr_to_BST(root, arr, begindex, position - 1);
			temp->right = construct_Arr_to_BST(root, arr, position+1, lastindex );
		}
		return temp;
}
struct node * convert_array_to_bst(int *arr, int len){
	struct node*root = NULL;
	if (arr==NULL)
	return NULL;
	else
		root = construct_Arr_to_BST(root, arr, 0, len - 1);
	return root;
}

