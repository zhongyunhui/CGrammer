#include <iostream>
using namespace std;
struct Node{
	int val;
	Node *next;
	Node(int v):val(v){}
};
int main(int argc, char *argv[]){
	cout<<"hello, world"<<endl;
	//cout<<argv[1]<<endl;
	Node *t=new Node(1);
	t=t->next;
	cout<<t->val<<endl;
	return 0;
}
