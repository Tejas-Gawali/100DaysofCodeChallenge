#include <iostream>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this-> data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
    
};

node* buildTree(node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left node of "<<data<<":"<<endl;
    root->left = buildTree(root-> left);
    cout<<"Enter data for right node of "<<data<<":"<<endl;
    root->right = buildTree(root-> right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp-> data<<" ";

            if(temp-> left){
                q.push(temp->left);
            }

            if(temp-> right){
                q.push(temp->right);
            }
        }

        
    }
}

void inOrder(node* root){

    // L N R
    if(root == NULL){
        return;
    }

    inOrder(root-> left);
    cout<<root-> data<<" ";
    inOrder(root-> right);
}

void preOrder(node* root){

    // N L R
    if(root == NULL){
        return;
    }

    cout<<root-> data<<" ";
    preOrder(root-> left);
    preOrder(root-> right);
}

void postOrder(node* root){

    // L R N
    if(root == NULL){
        return;
    }

    postOrder(root-> right);
    cout<<root-> data<<" ";
    postOrder(root-> left);
}

void buildfromlevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root node"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node*temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp-> left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp-> right = new node(rightdata);
            q.push(temp->right);
        }

        
    }
}

int main(){

    node* root = NULL;

    buildfromlevelOrder(root);
    levelOrderTraversal(root);

    // root = buildTree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout<<"Printing in level order traversal"<<endl;
    // levelOrderTraversal(root);

    // cout<<"In Order traversal"<<endl;
    // inOrder(root);
    // cout<<endl;

    // cout<<"Pre Order traversal"<<endl;
    // preOrder(root);
    // cout<<endl;

    // cout<<"Post Order traversal"<<endl;
    // postOrder(root);



  return 0;
}