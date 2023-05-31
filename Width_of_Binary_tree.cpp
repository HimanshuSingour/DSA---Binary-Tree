#include<bits/stdc++.h>
using namespace std;

// left = 2 * i + 1
// right = 2 * i + 2;

// width = right - left + 1;

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

int NodeToRoot(struct Node * root){

  if(root == NULL) return 0;

  int ans = 0;
  
  queue<pair<Node * , int>> q;
  q.push({root , 0});


  while(!q.empty()){
    
    int size = q.size();

    int first;
    int last;

    for(int i = 0; i < size; i++){

    	Node * node = q.front().first;
    	int Index = q.front().second;
    	q.pop();

        if(i == 0) first = Index;
        if(i == size - 1) last = Index;

    	if(node->left){

    		q.push({node->left , 2 * Index + 1});
    	}

    	if(node->right){

    		q.push({node->right , 2 * Index + 2});
    	}
    } 

    ans = max(ans , last - first + 1);

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
    root->left = newNode(3);
    root->right = newNode(7);
    root->right->right = newNode(4);
    root->left->left = newNode(8);
   

    
  cout << NodeToRoot(root);

 
}




