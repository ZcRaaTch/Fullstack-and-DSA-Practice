// to reverse a linked list.
// using 3 pointer approach.
#include "bits/stdc++.h"
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

// using previous made functions to create and display linked list.
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
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
// function to reverse the given linked list.
void reversal(node* &head){
    // declaring 3 pointers.
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    while(curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    // the new head will be the prev as prev is pointing at the last node of linked list. 
    head=prev;
}

int main(){
    node* head=NULL;
    insertEnd(head,1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    cout<<"Original Linked List =>"<<" ";
    display(head);
    reversal(head);
    cout<<"Reversed Linked List =>"<<" ";
    display(head);

    return 0;
}