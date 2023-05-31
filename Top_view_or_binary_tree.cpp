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

vector<int> TopView(struct Node * root){

   map<int , int> maps;
    vector<int> ans;

    if(root == NULL) return ans;

	queue<pair<Node * , int>> q;
	q.push({root , 0});

	while(!q.empty()){
    
    Node * temp = q.front().first;
    int vertical = q.front().second;
    q.pop();

    if(maps.find(vertical) == maps.end()){

    	maps[vertical] = temp->data;
    }

    if(temp->left){

    	q.push({temp->left , vertical - 1});
    }

    if(temp->right){

    	q.push({temp->right , vertical + 1});

        }

	}

  
	for(auto i : maps){
		ans.push_back(i.second);
	}

	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

	Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);


    vector<int> ans = TopView(root);

    for(auto i : ans){
    	cout << i << endl;
    }

 
}


