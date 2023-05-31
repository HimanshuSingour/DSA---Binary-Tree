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

void parentFindNode(Node * root ,  unordered_map<Node * , Node*> & parents_track){
  
  queue<Node * > q;
  q.push(root);

  while(!q.empty()){

  	 Node * curr = q.front();
  	 q.pop();

     // finding node from where we have start
  	 if(curr->data == start){
  	 	res = curr;
  	 }


  	 if(curr->left){
  	 	parents_track[curr->left] = curr;
  	 	q.push(curr->left);
  	 }
  	 if(curr->right){
  	 	parents_track[curr->right] = curr;
  	 	q.push(curr->right);
  	 }
  }

}

int Print2Distance(Node * root , Node* start){

 unordered_map<Node * , Node *> parents_track;
 parentFindNode(root , parents_track);

 queue<Node * > q;
 q.push(start);

 unordered_map<Node * , bool> visited;
 visited[start] = true;

int maxi = 0;
 while(!q.empty()){


 	int size = q.size();
 	int flag = 0;

    
 	for(int i = 0; i < size; i++){
 		Node * curr = q.front();
 		q.pop();


 		if(curr->left && !visited[curr->left]){
 			flag = 1;
 			visited[curr->left] = true;
 			q.push(curr->left);
 		}

 		if(curr->right && !visited[curr->right]){
 			flag = 1;
 			visited[curr->right] = true;
 			q.push(curr->right);
 		}

 		if(parents_track[curr] && !visited[parents_track[curr]]){
 			flag = 1;
 			visited[parents_track[curr]] = true;
 			q.push(parents_track[curr]);

 		}

 		
 	}
 	if(flag) maxi++;

 }

 return maxi;

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
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    

   cout <<  Print2Distance(root , root->left->left);
   
 

 }




