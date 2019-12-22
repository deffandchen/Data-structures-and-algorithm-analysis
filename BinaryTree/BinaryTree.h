#ifndef BinaryTree_H
#define BinaryTree_H

#include<iostream>

//一个二叉树节点包含数据和左右两个子树叶
template <typename T>
struct tree{
    T data;
    tree *left, *right;
};

//构造一个二叉搜索树类模板
template<typename T>
class BinaryTree{
    public:
        T data;
        tree<T> *root = NULL;
    public:
        BinaryTree()               //构造函数，前面不能加类型
        { 
            root = NULL;
        }              
        void create_binary_tree(const T &dat);
        void inorder(tree<T> *temp);
        int count(tree<T> *temp);
        void dispaly();
        tree<T>* find_max(tree<T> *temp);
        tree<T>* find_min(tree<T> *temp);

};

#endif