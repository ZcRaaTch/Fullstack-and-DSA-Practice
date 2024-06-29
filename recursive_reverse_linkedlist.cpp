// to reverse a linked list.
// using recursive approach.
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
// reversing the given linked list using recursion.
// we send the next of the given head and use recursion to get remaining list in reversed.
node* reversal(node* &head){
    // base case of No node or single node linked list.
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* temp=reversal(head->next);
    // the reversed linkedlist we will get will be reversed till head->next.
    // then we will reverse the remaining list.
    head->next->next=head;
    head->next=NULL;
    return temp;
}

int main(){
    node* head=NULL;
    insertEnd(head,1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    cout<<"Original Linked List =>"<<" ";
    display(head);
    node* newhead=reversal(head);
    cout<<"Reversed Linked List =>"<<" ";
    display(newhead);

    return 0;
}