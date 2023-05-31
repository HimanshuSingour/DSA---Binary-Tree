#include<bits/stdc++.h>

using namespace std;

// Tree Traversal -  DFS -> PreOrder , InOrder , PostOrder
//                   BFS 


// Structure
struct node{
 
 public:
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data){

	struct node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void preOrderTraversal(node * Node){

	if(Node == NULL){
		return;
	}

	cout << Node->data << endl;
	preOrderTraversal(Node->left);
	preOrderTraversal(Node->right);
}


void InOrderTraversal(node * Node){

	if(Node == NULL){
		return;
	}

	InOrderTraversal(Node->left);
	cout << Node->data << endl;
	InOrderTraversal(Node->right);
}



void PostOrderTraversal(node * Node){

	if(Node == NULL){
		return;
	}

	
	PostOrderTraversal(Node->left);
	PostOrderTraversal(Node->right);
	cout << Node->data << endl;
}




int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

	struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    PostOrderTraversal(root);


 
}