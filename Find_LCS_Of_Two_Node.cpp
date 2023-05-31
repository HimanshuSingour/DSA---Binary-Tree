#include<bits/stdc++.h>
using namespace std;

struct Node{
 
 public:
	int data;
	struct Node* left;
	struct Node* right;};

struct Node* newNode(int data){

	struct Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;}

Node * NodeToRoot(struct Node * root , int p , int q){

	if(root == NULL){
         return NULL;
	} 

	if(root->data == p || root->data == q){
		return root;
	}

	Node * l = NodeToRoot(root->left , p , q);
	Node * r = NodeToRoot(root->right , p , q);

   
   if(l == NULL) return r;
   else if(r == NULL) return l;
   else return root;
   
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

    
  cout << NodeToRoot(root , 6 , 7)->data;

 
}




