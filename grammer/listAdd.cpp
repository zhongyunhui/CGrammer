#include<iostream>
using namespace std;

struct Node{
  int val;
  Node * next;
  Node(int value):val(value),next(nullptr){}
};
Node* getResult(Node * A, Node *B){
  Node *head=new Node(0);
  Node *cnt=head;
  while(A!=nullptr&&B!=nullptr){
    if(A->val<B->val){
      head->next=A;
      A=A->next;
      head=head->next;
      head->next=nullptr;
    }else{
      head->next=B;
      B=B->next;
      head=head->next;
      head->next=nullptr;
    }
  }
  if(A!=nullptr){
    head->next=A;
  }
  if(B!=nullptr){
    head->next=B;
  }
  Node *result=cnt->next;
  delete cnt;
  return result;
}

int main(){
  int arr1[3]={1,5,9};
  int arr2[3]={2,5,10};
  Node *A,*B;
  Node *headA,*headB;
  for(int i=0;i<3;i++){
    if(i==0){
      A=new Node(arr1[i]);
      headA=A;
    }else{
      A->next=new Node(arr1[i]);
      A=A->next;
    }
  }
  for(int i=0;i<3;i++){
    if(i==0){
      B=new Node(arr2[i]);
      headB=B;
    }else{
      B->next=new Node(arr2[i]);
      B=B->next;
    }
  }
  Node* result=getResult(headA,headB);
  while(result){
    cout<<result->val<<" ";
    result=result->next;
  }
  return 0;
}
