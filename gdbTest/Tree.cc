#include <iostream>
#include <stdlib.h>
using namespace std;

struct Tree{
	int a;
	struct Node{
		void init(){
			printf("%d",.a);
		}
	}node;
}tree;

int main(){
	tree.node.init();
}
		

