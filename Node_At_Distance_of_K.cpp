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

void FindParentsOfEactNode(Node * root ,  unordered_map<Node * , Node *> & parent_tra){

	queue<Node * > q;
	q.push(root);


	while(!q.empty()){

		Node * current = q.front();
		q.pop();

		if(current->left){
           parent_tra[current->left] = current;
           q.push(current->left); 
		}

		if(current->right){

			parent_tra[current->right] = current;
			q.push(current->right);
		}
	}
}

vector<int> Print2Distance(Node * root , int k , Node* target){

  unordered_map<Node * , Node *> parent_tra;
  FindParentsOfEactNode(root , parent_tra);

  queue<Node *> q;
  unordered_map<Node * , bool> visited;
  q.push(target);
  visited[target] = true;

  int count = 0;

  while(!q.empty()){

  	int size = q.size();

  	if(count++ == k) break;

  	for(int i = 0; i < size; i++){

  		Node * current = q.front();
  		q.pop();

  		if(current->left && !visited[current->left]){
  			q.push(current->left);
  			visited[current->left] = true;
  		}

  		if(current->right && !visited[current->right]){
  			q.push(current->right);
  			visited[current->right] = true;
  		}
        
        if(parent_tra[current] && !visited[parent_tra[current]]){
        	q.push(parent_tra[current]);
        	visited[parent_tra[current]] = true;
        }

  	}
  }

  vector<int> ans;

  while(!q.empty()){
  	Node * node = q.front();
  	ans.push_back(node->data);
  	q.pop();
  }

  return ans;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(1);
    root->right->right = newNode(8);
    root->right->left = newNode(0);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

   vector<int> ans = Print2Distance(root , 2 , root->left);
   
   for(auto i : ans){
   	cout << i << endl;
   }
    

 }




