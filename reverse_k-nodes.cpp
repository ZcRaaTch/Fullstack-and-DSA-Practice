// to rever k nodes in a linked list
// taking k=2.
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

// function to reverse the k nodes.
// using iterative 3 pointer approach to reverse first k nodes.
// using recursion to reverse remaining k nodes.
node* reverseKNodes(node* &head,int k){
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    int c=1;
    while(curr!=NULL && c<=k ){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        c++;
    }
    // recursive call
    if(nextptr!=NULL)
        head->next=reverseKNodes(nextptr,k);
    return prev;
}

int main(){
    node* head=NULL;
    insertEnd(head,1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    insertEnd(head,5);
    insertEnd(head,6);
    cout<<"Original Linked List =>"<<" ";
    display(head);
    node* newhead=reverseKNodes(head,2);
    cout<<"Reversed Linked List =>"<<" ";
    display(newhead);

    return 0;
}