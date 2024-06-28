// To create, insert, delete and display nodes from a linked list.
#include "bits/stdc++.h"
using namespace std;
// Declaring a class to create a node with the help of def constructor 
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};
// A function to insert at the head of linked list
void insertHead(node* &head, int val){       //accepting head by reference
    node* n = new node(val);
    n->next=head;
    head=n;
}
// A function to insert at the end of linked list
void insertEnd(node* &head,int val){         //accepting head by reference
    node* n=new node(val);
    // checking if the head send to us is null or not
    if(head==NULL){
        head=n;                             //We can also call insertHead here insted of doing it again  
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
// Deleting from linked list
void deleteHead(node* &head, int val){
    node* n=head;
    head=head->next;
    delete n;
}

void deleteL(node* &head, int val){
    node* temp=head;
    if(head->data==val){
        deleteHead(head,val);                //if the to delete value is at head
        return;
    }
    while(temp->next->data!=val){            //checking for the data value of the next node
        temp=temp->next;
    }
    node* n = temp->next;                    //node to delete
    temp->next=temp->next->next;             //pointing the next of current node to the next of the node to delete
    delete n;
}
// Displaying linked list
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main(){
    
    node* head=NULL;
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    display(head);
    insertHead(head,1);
    display(head);
    deleteL(head,3);
    display(head);
    return 0;
}