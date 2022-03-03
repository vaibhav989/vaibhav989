#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int key;
	node* left;
	node* right;

	node(int key){
		this->key=key;
		left=right=NULL;
	}
};

node* insert(node* root, int key){
	if(root==NULL){
		return new node(key);
	}
	if(key<root->key){
		root->left=insert(root->left,key);
	}
	else{
		root->right=insert(root->right,key);
	}
	return root;
}

void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->key<<" , ";
	inorder(root->right);
}


int main(){
	node*root=NULL;
	int arr[]={8,3,10,1,6,14,4,7,13};

	for(int x : arr){
		root=insert(root,x);
	}
	inorder(root);

	return 0;
}
