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

vector<vector<int>> VerticalTraversal(struct node * root){

  map<int , map<int , multiset<int>>> maps;

  queue<pair<node* , pair<int , int>>> q;
  q.push({root , {0 , 0}}); 

  while(!q.empty()){

  	node * temp = q.front().first;
  	int vertical = q.front().second.first;
  	int level = q.front().second.second;
  	q.pop();
  	

  	maps[vertical][level].insert(temp->data);

  	if(temp->left){
  		q.push({temp->left , {vertical - 1 , level + 1}});

  	}
  	if(temp->right){
  		q.push({temp->right , {vertical + 1 , level + 1}});
  	}

  }

  vector<vector<int>> ans;
  for(auto p : maps){
    
    vector<int> col;
  	for(auto q : p.second){

  		col.insert(col.end() , q.second.begin() , q.second.end());
  	}

  	ans.push_back(col);
  }

  return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);


    vector<vector<int>> ans = VerticalTraversal(root);

    for(int i = 0; i < ans.size(); i++){
    	for(int j = 0; j < ans[i].size(); j++){
    		cout << ans[i][j] << " ";
    	}

    	cout << "\n";
    }
   
  
 
}


