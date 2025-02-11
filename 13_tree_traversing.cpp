#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node *right;
};
node* createnode(int data){
    node* n=new node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preorder(node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main(){
    node *p=createnode(4);
    node* p1=createnode(1);
    node* p2=createnode(6);
    node* p3=createnode(5);
    node* p4=createnode(2);
    //form tree
     // Constructing the tree:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    preorder(p);
    cout<<endl;
    postorder(p);
    cout<<endl;
    inorder(p);
    cout<<endl;
}