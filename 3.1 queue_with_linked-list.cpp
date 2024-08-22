#include <iostream>
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

// Declaring a class to create queue.
class queue{
    node* front;
    node* back;

    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    // function to push an element in the queue.
    void push(int val){
        node* n = new node(val);
        // if queue is empty
        if(front==NULL){
            front =n;
            back = n;
            return;
        }
        back->next=n;
        back=n;
    }
    // function to pop an element.
    void pop(){
        // to check whether the queue is empty.
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        node* toDelete=front;
        front=front->next;
        delete toDelete;
    }
    // function to display the front element i.e. peek function.
    int peek(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return front->data;
    }
    // function to check if the queue is empty.
    bool empty(){
        if(front == NULL)
            return true;
        return false;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.peek()<<' ';
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    cout<<q.empty()<<endl;
    q.pop();
    return 0;
}