#include<bits/stdc++.h>
using namespace std;

struct node{
 
 public:
	int data;
	struct node* left;
	struct node* right;};

struct node* newNode(int data){

	struct node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;}

vector<vector<int>> LevelOrdertraversal(node * root){

	vector<vector<int>> ans;
	queue<node *> q;
	q.push(root);

	while(!q.empty()){

		 vector<int> level;

		int size = q.size();
        
		for(int i = 0; i < size; i++){
			node * temp = q.front();
			q.pop();

			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
            level.push_back(temp->data);
		}

		ans.push_back(level);
	} 

	return ans;

}



int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

	struct node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    vector<vector<int>> ans =  LevelOrdertraversal(root);
   

   for(int i = 0; i < ans.size(); i++){
   
   		for(int j = 0; j < ans[i].size(); j++){
   			cout << ans[i][j] << " ";
   		}
   		cout << "\n";
   	
   }

 
}