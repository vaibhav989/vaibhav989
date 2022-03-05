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
// tree to ll

class linkedlist{
public:
	node* head;
	node* tail;
};

linkedlist treetoll(node*root){
 linkedlist l;
 if(root==NULL){
 	l.head=l.tail=NULL;
 	return l;
 }

 else if(root->left!=NULL and root->right==NULL){
 	linkedlist leftll=treetoll(root->left);
 	leftll.tail->right=root;

 	l.head=leftll.head;
 	l.tail=root;
 }
 else if(root->left==NULL and root->right!=NULL){
 	linkedlist rightll=treetoll(root->right);
 	root->right=rightll.head;

 	l.head=rightll.head;
 	l.tail=root;
 }
 else{
 	linkedlist leftll=treetoll(root->left);
 	linkedlist rightll=treetoll(root->right);

 		leftll.tail->right = root;
		root->right = rightll.head;

		l.head = leftll.head;
		l.tail = rightll.tail;
  }
  return l;
}

int main(){
	node*root=NULL;
	int arr[]={8,3,10,1,6,14,4,7,13};

	for(int x : arr){
		root=insert(root,x);
	}
	inorder(root);

	 linkedlist l= treetoll(root);

	 node*temp=l.head;
	 while(temp!=NULL){
	 	cout<<temp->key<<" --> ";
	 	temp=temp->right;
	 }

	return 0;
}
