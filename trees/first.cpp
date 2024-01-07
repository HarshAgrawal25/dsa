//creation/building binary tree
// there 2 ways to create a tree
// 1. Level order traversal
// 2. simple by recursion
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
node* buildTree(node* root){
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;
    root=new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data in left "<<data<<" ";
    root->left=buildTree(root->left);
    cout<<"Enter the data in right "<<data<<" ";
    root->right=buildTree(root->right);
    return root;
    
}
int main(){
    node* root=NULL;
    root=buildTree(root);
    return 0;
}
