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

// Child Sum Proerties.... 

void InorderTrave(Node * root){

	if(root == NULL) return;

    cout << root->data << endl;
	InorderTrave(root->left);
	InorderTrave(root->right);
}

void ChildSUmProperty(struct Node * root){

	if(root == NULL) return;

    int sum = 0;

	if(root->left){
		sum = sum + root->left->data;
	}
	if(root->right){
		sum = sum + root->right->data;
	}

	if(sum <= root->data){

		if(root->left) {

			root->left->data = root->data;
		}

		else if(root->right){

			root->right->data = root->data;
		}
	}
	else{

		root->data = sum;
	}

	ChildSUmProperty(root->left);
	ChildSUmProperty(root->right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;


}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

    Node* root = newNode(40);
    root->left = newNode(10);
    root->right = newNode(20);
    root->right->right = newNode(40);
    root->right->left = newNode(30);
    root->left->left = newNode(2);
    root->left->right = newNode(5);
   

    
  ChildSUmProperty(root);

  InorderTrave(root);
  

 
}




