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



void insertNode(node* &tail,int element, int data){

    // empty list  
	if(tail ==NULL){
		node* newNode =new node(data);\
		tail=newNode;
		newNode->next =newNode;
	}else{
         
        //non-empty list 
		node* curr=tail;


		while(curr->data !=element){
			curr=curr->next;
		}

		//element found 

		node* temp =new node(data);
		temp->next=curr->next;
		curr->next= temp;

	}
}


void Print(node* &tail){
	node* temp =tail;

	do{
		cout<<tail->data<<" ";
		tail=tail->next;

	}while(tail !=temp);
	cout<<endl;
}

void deleteNode(node* &tail,int value){

	//empty list 

	if(tail==NULL){
		cout<<"List is empty,please cheack again";
		return;
	}else{
       
       //non-empty list 
	    node* prev =tail;
	    node* curr =prev->next;

	    while(curr->data !=value){
	    	prev= curr;
	    	curr=curr->next;
	    }

	    prev->next=curr->next;

	    // when one node in link list
	    if(curr == prev){
	    	tail=NULL;
	    }



	    //>= 2 node linked list
	 
	    else if(tail==curr){
	    	tail=prev;

	    }

	    curr->next=NULL;
	    delete curr;

	}



}


int main(){

node* tail=NULL;

 
insertNode(tail,5,3);
Print(tail); 

 insertNode(tail,3,5);
 Print(tail); 
insertNode(tail,5,7);
Print(tail); 
insertNode(tail,7,9);
Print(tail); 
insertNode(tail,9,10);
Print(tail);
insertNode(tail,3,4);
Print(tail); 

deleteNode(tail,3);
Print(tail); 

	return 0;
}