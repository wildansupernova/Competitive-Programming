//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
//Lowest common ancestor
//Function problem

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
/*you are required to 
complete this function */

#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

bool cari(Node* root, int x){
    if(root == NULL){
        return false;
    } else if(root->data== x){
        return true;
    } else{
        return cari(root->left,x) || cari(root->right,x);
    }
}

Node * LCA(Node* root ,int n1 ,int n2 )
{
   bool hasiln1kiri = cari(root->left,n1);
   bool hasiln1kanan = cari(root->right,n1);
   bool hasiln2kiri = cari(root->left,n2);
   bool hasiln2kanan = cari(root->right,n2);


   if(root->data==n1 && root->data==n2){
    return root;
   } else if(root->data==n1 && (hasiln2kiri || hasiln2kanan)){
    return root;
   } else if(root->data==n2 && (hasiln1kiri || hasiln1kanan)){
    return root;
   }else  if(hasiln1kiri && hasiln2kanan){
    return root;
   }else if(hasiln2kiri && hasiln1kanan){
    return root;
   } else if(hasiln1kiri &&hasiln2kiri){
    return LCA(root->left,n1,n2);
   } else if((hasiln1kanan &&hasiln2kanan)){
    return LCA(root->right,n1,n2);
   }






}