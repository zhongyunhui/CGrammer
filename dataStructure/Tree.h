#include <iostream>
struct Node{
	int value;
	Node* right, *left;
	Node(int val):value(val),right(nullptr),left(nullptr){}
};
