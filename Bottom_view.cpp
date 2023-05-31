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

vector<int> BottomView(struct Node * root){

	queue<pair<Node * , int>> q;
	map<int, int> maps;
	vector<int> ans;

	q.push({root , 0});

	while(!q.empty()){

		Node * temp = q.front().first;
		int vertical = q.front().second;
		q.pop();

		maps[vertical] = temp->data;

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



    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    vector<int> ans = BottomView(root);

    for(auto i : ans){
    	cout << i << endl;
    }


 
}


