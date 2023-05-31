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

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

Node * constructAtree(vector<int> & InOrder , vector<int> & preOrder , 
	                                           int is , int ie , int ps , int pe , map<int , int> &maps){

	if(is > ie || ps > pe) return NULL;

	Node * node = newNode(preOrder[ps]);

	int Inmap = maps[node->data];
	int LeftElement = Inmap - is;

	node->left = constructAtree(InOrder , preOrder , is , Inmap - 1 ,  ps + 1 , ps + LeftElement , maps);
	node->right = constructAtree(InOrder , preOrder , is + 1 , ie , ps + LeftElement + 1 , pe , maps);

    return node;

}
Node * PreAndInorder(vector<int> & InOrder , vector<int> &preOrder){
    
    map<int , int> maps;
    
    for(int i = 0; i < InOrder.size(); i++){
    	maps[InOrder[i]] = i;
    }

    return constructAtree(InOrder , preOrder , 0 , InOrder.size() - 1 , 0 , preOrder.size() - 1 , maps);
   

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
    // Node* root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->left->left = newNode(8);
    // root->left->left->right = newNode(9);
    // root->right->left = trrgnewNode(6);
    // root->right->right = newNode(7);

    vector<int> InOrder{1 , 6 , 8 , 7};
    vector<int> preOrder{1 , 6 , 7 , 8};

    Node * root = PreAndInorder(InOrder , preOrder);
    
    printPostOrder(root);


 }




