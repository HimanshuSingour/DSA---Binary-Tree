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

vector<int> LeftView(struct Node * root){

  
  vector<int> ans;

  if(root == NULL) return ans;

  queue<Node * > q;
  q.push(root);

  while(!q.empty()){

  	int size = q.size();

  	for(int i = 0; i < size; i++){
        
       Node * temp = q.front();
       q.pop();


       if(i == 0){
       	  ans.push_back(temp->data);
       }  

       if(temp->left != NULL){
       	  q.push(temp->left);
       } 

       if(temp->right != NULL){
       	  q.push(temp->right);
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



    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

   vector<int> ans = LeftView(root);
   

   for(auto i : ans){
   	cout << i << endl;
   }


 
}


