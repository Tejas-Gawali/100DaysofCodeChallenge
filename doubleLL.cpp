#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this-> data = d;
        this-> prev = NULL;
        this-> next = NULL;
    }

    ~Node(){
        int value = this-> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<< "memory free for data "<<value<<endl;
    }


};

void insertAtHead(Node* &head , Node* &tail , int d){

    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp-> next = head;
        head-> prev = temp;
        head = temp;
    }
    
}

void insertAtTail(Node* &head ,Node* &tail , int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    Node* temp = new Node(d);
    tail-> next = temp;
    temp-> prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head , Node* &tail , int position , int d){

    if(position == 1){
        insertAtHead(head , tail ,  d);
    }
    Node* temp = head;
    int count = 1;

    while(count < position -1 ){
        temp = temp->next;
        count++;
    }

    if(temp-> next == NULL){
        insertAtTail(head ,tail , d);
    }

    Node* newNode = new Node(d);
    newNode-> next = temp-> next;
    temp->next->prev = newNode;
    temp-> next = newNode;
    newNode-> prev = temp;
}

void deleteNode(Node* &head , int position){

    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else{

        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr =  curr-> next;
            count++;
        }

        curr-> prev = NULL;
        prev-> next = curr-> next;
        curr-> next = NULL;

        delete curr;

    }
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp-> data<< " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtHead(head , tail , 11);
    insertAtTail(head ,tail , 13);
    insertAtPosition(head, tail , 2 , 15);
    print(head);
    cout<< getLength(head)<<endl;
    deleteNode(head , 4); 
    print(head);



  return 0;
}