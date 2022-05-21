#include<bits/stdc++.h>

using namespace std;


class node{

 public:
 	int data;
 	node* next;

 	node(int d){

 		this->data =d;
 		this->next=NULL;
 	}
 	~node(){
 		int value =this->data;
 		if(this->next !=NULL){
 			delete next;
 			next=NULL;
 		}
 		cout<<"memory is free node with delete"<<value<<endl;
 	}
 
};

void insertAthead(node* &head,int data){

    if(head ==NULL){
        head =new node(data);
        return;
    }
    node* n =new node(data);
    n->next=head;
    head=n;
}

 void Print(node* &head){

    node* temp =head;

    while(temp!=NULL){
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
 }

 node* ApprochOneReverse(node* &head){

    if(head ==NULL || head->next == NULL){
        return head;

    }
    node* prev=NULL;
    node* curr =head;
    node* forworad =NULL;

    while(curr != NULL){
         forworad=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forworad;      
    }
    return prev;
 }

 void revers(node* &head,node* curr, node* prev){

     // base caase 

    if(curr == NULL){
        head = prev;
        return;
    }

    node* forward =curr->next;
    revers(head,forward,curr);
    curr->next =prev;


  }


 node* reverseLL(node* &head){


    node* curr =head;
    node* prev =NULL;
    revers(head,curr,prev);

    return head;

 }

 node* revers1(node* &head){

    if(head ==NULL || head->next == NULL){
        return head;
    }

    node* chotoHead =revers1(head->next);

       head->next->next =head;
       head->next =NULL;

       return chotoHead;


 }

  node* reverseLLOne(node* &head){
    revers1(head);
    return head;

 }

int main(){

    node* head=NULL;

    insertAthead(head,4);
    insertAthead(head,5);
    insertAthead(head,7);
    insertAthead(head,10);

    Print(head);
    ApprochOneReverse(head);

    Print(head);
    reverseLL(head);

    Print(head);

    reverseLLOne(head);
    Print(head);





    return 0;
}