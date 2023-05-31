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

// Morris Algorithum -> printing Inorder with time comp B(n) and space B(1)

vector<int> MorrisTraversal(Node * root){

	Node * curr = root;

	vector<int> ans;

	while(curr != NULL){
		if(curr->left == NULL){
			ans.push_back(curr->data);
			curr = curr->right;
		}
		else{
			Node * prev = curr->left;

		while(prev->right && prev->right != curr){
			prev = prev->right;
		}

		if(prev->right == NULL){
			prev->right = curr;
			// ans.push_back(curr->data); -> // For PreOrder
			curr = curr->left;
		}
		else{

			prev->right = NULL;
			ans.push_back(curr->data);
			curr = curr->right;
		}
 	}

	}

	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif
// taking input

    Node* root = newNode(4); 
	root->left = newNode(2); 
	root->right = newNode(5); 
	root->left->left = newNode(1); 
	root->left->right = newNode(3); 

    vector<int> a = MorrisTraversal(root);
    

    for(auto i : a){
    	cout << i << endl;
    }
    


 }




