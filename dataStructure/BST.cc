#include <iostream>
using namespace std;
struct Node{
	Node value;
	Node* left,* right;
	Node(int val):value(val),left(nullptr),right(nullptr){}
};
Node* getMin(Node* root){
	while(root->left){
		root=root->left;
	}
	return root;
}
Node* deleteNode(Node* root,int key){
	if(root==nullptr)return nullptr;
	if(root->value==key){
		if(root->left==nullptr)return root->right;
		if(root->right==nullptr)return root->left;
		Node* minNode=getMin(root->right);
		root->value=minNode->value;
		root->right=deleteNode(root->right,key);		
	}
	else if(root->value>key){
		return deleteNode(root->left,key);
	}else return deleteNode(root->right,key);
}
