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




 node* FoundMiddle(node* &head){

    int nodeLenght =0;

    node* curr =head;

    while(curr !=NULL){
     nodeLenght++;
     curr=curr->next;

    }

    int getLen=nodeLenght/2;

    int cnt=0;
    
     node* temp =head;
    while(cnt<getLen){
        temp=temp->next;
        cnt++;

    }

    

    return temp;
 }

int main(){

    node* head=NULL;

    insertAthead(head,4);
    insertAthead(head,5);
    insertAthead(head,7);
    insertAthead(head,10);

    Print(head);
    

     FoundMiddle(head);





    return 0;
}