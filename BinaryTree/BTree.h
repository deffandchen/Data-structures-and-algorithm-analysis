#ifndef BTree_H
#define BTree_H

#include<iostream>

//一个二叉树节点包含数据和左右两个子树叶
struct tree{
    int data;
    tree *left, *right;
};

class BinaryTree{
    public:
        int data;
        tree *root = NULL;
    public:
        BinaryTree()               //构造函数，前面不能加类型
        { 
            root = NULL;
        }              
        void create_binary_tree(int dat);
        void inorder(tree *temp);
        int count(tree *temp);
        void dispaly();
};

#endif