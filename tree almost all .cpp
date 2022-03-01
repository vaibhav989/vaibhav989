
#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node( int d){
		data=d; //
		left=NULL;
		right=NULL;
	}
};

node* buildtree(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}
	node* n=new node(d);

	n->left=buildtree();
	n->right=buildtree();

	return n;
}
// printing in level order

void printlevelorder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node*temp=q.front();

		if(temp==NULL){
			cout<<endl;
			q.pop();

			if(!q.empty()){
				q.push(NULL);
			}	
		}
		else{
			q.pop();
			cout<<temp->data<<" ";

			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return;
}

// helping in diameter so height is required


int height(node* root){
	if(root==NULL){
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	return 1+max(h1,h2);
}
// it takes  O(n^2)

int diameter(node* root){
	if(root==NULL){
		return 0;
	}
	int d1=height(root->left)+height(root->right);
	int d2=diameter(root->left);
	int d3=diameter(root->right);

	return max(d1,max(d2,d3));
}

// optimized code for diameter it take o(n)

class Hdpair{
 public:
   int height;
   int diameter;
};
Hdpair optDiameter(node* root){
	Hdpair p;
	if(root==NULL){
		p.diameter=p.height=0;
		return p;
	}
	Hdpair left=optDiameter(root->left);
	Hdpair right=optDiameter(root->right);

	p.height=max(left.height ,right.height) + 1;

	// now diameter

	int d1=left.height+right.height;
	int d2=diameter(root->left);
	int d3=diameter(root->right);

	p.diameter=max(d1,max(d2,d3));
	return p;
}
// balanced height of tree KHATARNAK 
/*
pair<int,bool> isheightbalanced(node*root) {
	pair<int,bool> p,left,right;

	if(root=NULL){
		p.first=0;
		p.second=true;
	}
	left=isheightbalanced(root->left);
	right=isheightbalanced(root->right);

	int height=max(left.first,right.first)+1;
	if(abs(left.first-right.first)<=1 and left.first and right.first){
		return make_pair(height,true);
	}
	return make_pair(height,false)
}
*/


int replacewithsum(node* root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}
	int ls=replacewithsum(root->left);
	int rs=replacewithsum(root->right);

	int temp=root->data;
	root->data=ls+rs;

	return root->data + temp;
}
int main(){
	node* root=buildtree();
	printlevelorder(root);
	cout<<endl;
	//cout <<" Opt Diameter is " << optDiameter(root).diameter <<endl;
	replacewithsum(root);
}

// input :-1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
