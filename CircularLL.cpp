#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int d){
        this-> data = d;
        this-> next = NULL;
    }

    ~Node(){
        int val = this-> data;
        if(this-> next != NULL){
            delete next;
            next = NULL;
        }
        cout<< "Memory free for data "<< val<< endl;
    }
};

void insertNode(Node* &tail , int element , int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        newNode-> next = newNode;
        tail = newNode;
    }
    else{

        Node* curr = tail;

        while(curr-> data != element){
            curr = curr-> next;
        }

        Node* temp = new Node(d);
        temp-> next = curr-> next;
        curr-> next = temp;
    }
}

void deleteNode(Node* &tail , int value){

    if(tail == NULL){
        cout<< "this circular linked list is empty ";
        return;
    }
    else{

        Node* prev = tail;
        Node* curr = prev-> next;

        while(curr-> data != value){
            prev = curr;
            curr = curr-> next;
        }

        prev-> next = curr-> next;

        // 1 node cll
        if(curr == prev){
            tail = NULL;
        }
        // >=2 node cll
        if(tail == curr){
            tail = prev;
        }
        curr-> next = NULL;
        delete curr;
    }
}

void print(Node* tail){

    if(tail == NULL){
        cout<<"List is empty";
        return;
    }
    Node* temp = tail;
    do{
        cout<<tail-> data<<" ";
        tail = tail-> next;
    }
    while(tail != temp);
    cout<<endl;
}

int main(){



    Node* tail = NULL;

    insertNode(tail, 5 , 3);
    insertNode(tail, 3 , 5);
    insertNode(tail, 3 , 7);
    insertNode(tail, 5 , 10);
    print(tail);
    deleteNode(tail , 7);
    print(tail);

  return 0;
}