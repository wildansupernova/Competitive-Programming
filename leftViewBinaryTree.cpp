//Left View of Binary Tree (Function Problem)
//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
//Type Function Problem



/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// A wrapper over leftViewUtil()

#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

void leftView2(Node *root,int level,int *max){
    if(root!=NULL){
        if(level>*max){
            cout<<root->data<<" ";
            *max=level;
        }
        leftView2(root->left,level+1,max);
        leftView2(root->right,level+1,max);
    }
    

}
void leftView(Node *root)
{

    int maxnya = 0;
    leftView2(root,1,&maxnya);
}