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

bool NodeToRoot(struct Node * root , int x , vector<int> & ans){

	if(root == NULL) return false;

	ans.push_back(root->data);

	if(root->data == x){
		return true;
	}

	if(NodeToRoot(root->left , x , ans) || NodeToRoot(root->right , x , ans)){
		return true;
	}

	ans.pop_back();
	return false;
    

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

  vector<int> ans;

  NodeToRoot(root , 8, ans);


  for(auto i : ans){
  	cout << i << endl;
  }

 
}




Find