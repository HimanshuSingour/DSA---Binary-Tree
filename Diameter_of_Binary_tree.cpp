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


// B(N)

int hight(node * root ,  int& ans){

	if(root == NULL) return 0; 

	int hl = hight(root->left , ans);   
	int hr = hight(root->right, ans);

	ans = max(ans , hl + hr + 1);

	return 1 + max(hl , hr);
}



// the time complexity is B(N2);
// max(Left Diameter , Right Riameter , Lh + Rh + 1);

// int Diameter(struct node * root ){

// 	if(root == NULL){
//       return 0;

// 	}

// 	int dl = Diameter(root->left);
// 	int dr = Diameter(root->right);
    
//     int lh = hight(root->left);
//     int rh = hight(root->right);

//     int curr = lh + rh + 1;
    
//     return max(curr , max(dl , dr));

// }


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

	struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
   
   
   int ans = 0;
   hight(root , ans);
   cout << ans;
  
 
}


