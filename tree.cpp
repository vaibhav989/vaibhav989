#include <iostream>
#include <queue>
#include "treenod.h"
using namespace std;

// take input level wise
treeNode <int>* takeinputlevelwise(){
  int rootdata;
  cout<<"enter rootdata"<<endl;
  cin>>rootdata;
  treeNode<int>* root=new treeNode<int>(rootdata);

  queue<treeNode<int>*> pendingnodes;
  pendingnodes.push(root);
  while(pendingnodes.size()!=0){
  treeNode<int>* front=pendingnodes.front();
  pendingnodes.pop();
  cout<<"enter the number of children of"<<root->data<<endl;

    int numchild;
    cin>>numchild;

    for(int i=0;i<numchild;i++){
      int ChildDAta;
      cout<<"enter"<<i<<"th child of "<<front->data<<endl;
      cin>>ChildDAta;
      treeNode<int>*child=new treeNode<int>(ChildDAta);
      front->children.push_back(child);
      pendingnodes.push(child);
    }
    return root;
  }
}

treeNode<int>* takeinput(){
 int rootdata;
 cout<<"enter data"<<endl;
 cin>>rootdata;
treeNode<int>* root=new treeNode<int>(rootdata);
 int n;
 cout<<"enter the number of children of"<<rootdata<<endl;
 cin>>n;
 for(int i=0;i<n;i++){
   treeNode<int>* child=takeinput();
   root->children.push_back(child);
 }
 return root;
}

void printTree(treeNode<int>*root){
  cout<<root->data<<":";
  for(int i=0;i<=root->children.size();i++){
    cout<<root->children[i]->data<<",";
  }
  cout<<endl;
  for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);
  }
}

int main(){
/*
  treeNode<int>* root=new treeNode<int>(1);
  treeNode<int>* node1=new treeNode<int>(2);
  treeNode<int>* node2=new treeNode<int>(3);

  root->children.push_back(node1);
  root->children.push_back(node2);
  */
 treeNode<int>*root =takeinputlevelwise();
  printTree(root); 
}
