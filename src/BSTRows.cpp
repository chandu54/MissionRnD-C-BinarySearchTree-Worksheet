/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
#include<queue>
using namespace std;

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void LevelNode(struct node* root, int level, int arr[], int *index)
{
	if (root == NULL)
	{
		return;
	}
	if (level == 1)
	{
		arr[*index] = root->data;
		(*index)++;
		return;
	}
	else if (level > 1)
	{
		LevelNode(root->right, level - 1, arr,index);
		LevelNode(root->left, level - 1, arr, index);
	}
}
int height(struct node*root)
{
	int h1, h2;
	if (root == NULL)
		return 0;
	else
	{
		h1 = height(root->left);
		h2 = height(root->right);
		return 1 + ((h1 > h2) ? h1 : h2);
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int h = height(root);
	int i;
	int *arr = (int *)malloc(sizeof(int) *20);
	int index = 0;
	for (i = 1; i <= h; i++)
	{
		LevelNode(root, i, arr, &index);
	}

	return arr;
}

		
