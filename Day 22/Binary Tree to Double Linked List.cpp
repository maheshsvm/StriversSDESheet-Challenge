#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* prev = nullptr;
    BinaryTreeNode<int>* cur = root , *newHead;
    while(cur){
        if(cur->left){
            BinaryTreeNode<int>* temp = cur->left;
            while(temp->right && temp->right != cur) temp = temp->right;
            if(temp->right == cur){
                cur->left = prev;
                prev = cur;
                cur = cur->right;
            }
            else{
                temp->right = cur;
                BinaryTreeNode<int>* tempLeft = cur->left;
                cur->left = temp;
                cur = tempLeft;
            }
        }
        else{
            if(prev == nullptr) newHead = cur;
            cur->left = prev;
            if(prev) prev->right = cur;
            prev = cur;
            cur = cur->right;
        }
    }

    return newHead;
}