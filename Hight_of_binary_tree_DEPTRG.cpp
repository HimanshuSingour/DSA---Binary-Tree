#include<bits/stdc++.h>
using namespace std;

struct node{
 
 public:
	int data;
	struct node* left;
	struct node* right;};

struct node* newNode(int data){

	struct node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;}


int HightOfTheTree(node * root){

   
   if(root == NULL) return 0;

	int left = HightOfTheTree(root->left);
	int right = HightOfTheTree(root->right);

	return 1 + max(left , right);
	
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

	struct node* root = newNode(2);
    root->right = newNode(1);
    root->right->left = newNode(3);
   

    cout << HightOfTheTree(root);

 
}