#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this-> data  = data;
        this-> next = 0;
    }

    ~Node(){
        if(this-> next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void InsertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp-> next = head;
    head = temp;
}

void InsertAttail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail-> next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &head , Node* &tail , int position , int d){

    if(position==1){
        InsertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count< position-1){
        temp = temp-> next;
        count++;
    }

    if(temp-> next == NULL){
        InsertAttail(tail , d);
        return;
    }

    Node* newNode = new Node(d);
    newNode-> next = temp-> next;
    temp->next = newNode;

}

void deleteNode(Node* &head , int position){

    if(position == 1){
        Node* temp = head;
        head = head-> next;
        temp-> next =NULL;
        delete temp;
    }
    else{
        Node* current = head;
        Node* prev = NULL;

        int count =1;
        while(count< position){
            prev = current;
            current = current->next;
            count++;
        }

        prev-> next = current-> next;
        current-> next = NULL;
        delete current;
    }
}

void print(Node* &head ){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    // cout << node1-> data<<endl;
    
    Node* head = node1;
    Node* tail = node1;


    print(head);
    InsertAttail(tail ,12);
    InsertAttail(tail ,15);
    print(head);
    InsertAtPosition(head,tail,3,22);
    print(head);

    cout<<"After deleting"<<endl;
    deleteNode(head, 3);
    print(head);


    return 0;
}