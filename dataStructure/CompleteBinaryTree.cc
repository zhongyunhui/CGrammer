#include "Tree.h"
#include <math.h>
int countNodes(Node* root){
	Node *l=root,*r=root;
	int hl=0, hr=0;
	while(l){
		l=l->left;
		hl++;
	}
	while(r){
		r=r->right;
		hr++;
	}
	
	if(hl==hr){
		return pow(2,hl)-1;
	}
	else return 1+countNodes(root->right)+countNodes(root->left);
}
