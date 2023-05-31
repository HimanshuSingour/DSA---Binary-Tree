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

Node * BuildTree(vector<int> & InOrder , int is , int ie , vector<int> & postOrder , int ps , int pe , map<int , int> & maps){

	if(is > ie || ps > pe) return NULL;

    Node * node = newNode(postOrder[pe]);

    int inRoot = maps[node->data];
    int numLeft = inRoot - is;


    node->left = BuildTree(InOrder, is , inRoot - 1 , postOrder , ps , ps + numLeft - 1 , maps);
    node->right = BuildTree(InOrder , inRoot + 1 , ie , postOrder , ps + numLeft , pe - 1 , maps);
    return node;

}

Node * Construct(vector<int> & InOrder , vector<int> & postOrder){

	if(InOrder.size() != postOrder.size()) return NULL;

    map<int , int> maps;
    
    for(int i = 0; i < InOrder.size(); i++){
         maps[InOrder[i]] = i;
    }

    return BuildTree(InOrder , 0 , InOrder.size() - 1 , postOrder , 0 , postOrder.size() - 1 , maps);

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



    vector<int> InOrder{9 , 3 , 15 , 20 , 17};
    vector<int> postOrder{9 , 15 , 7 , 20 , 3};

    Node * root = Construct(InOrder , postOrder);
    
    printPostOrder(root);





 }




