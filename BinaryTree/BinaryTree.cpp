//定义数据结构
//构造一个类
//创建类中功能函数
//TODO: insert() delete()

#include "BinaryTree.h"

using namespace std;

//创建二叉树
template<typename T>
void BinaryTree<T>::create_binary_tree(const T &dat)
{
    tree<T> *newNode = new tree<T>;
    newNode -> data = dat;
    newNode ->left = NULL;
    newNode ->right = NULL;

    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        tree<T> *currentNode = root;
        tree<T> *back;
        while (currentNode != NULL)
        {
            back = currentNode;
            if(currentNode -> data > dat)
            {
                currentNode = currentNode -> left;
            }
            else
            {
                currentNode = currentNode -> right;
            }
        }

        if( back -> data > dat)
        {
            back -> left = newNode;
        }
        else
        {
            back -> right = newNode;
        }
    }
}

//二叉树计数
template<typename T>
int BinaryTree<T>::count(tree<T> *temp)
{
    int num = 0;
    if(temp != NULL)
    {
        num = count(temp -> left) + count(temp -> right) + 1;
    }
    
    return num;
}

template<typename T>
tree<T>* BinaryTree<T>::find_max(tree<T> *temp)
{
    if(temp == NULL)
        return NULL;
    else if(temp ->right == NULL)
        return temp;
    else
        find_max(temp ->right);
    
}

template<typename T>
tree<T>* BinaryTree<T>::find_min(tree<T> *temp)
{
    if(temp == NULL)
        return NULL;
    else if(temp ->left == NULL)
        return temp;
    else
        find_min(temp ->left);
       
}

//这是中序遍历二叉树，采用了递归的方法.递归还是有点绕啊。。。
template<typename T>
void BinaryTree<T>::inorder(tree<T> *temp)     
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
}

//显示中序遍历结果
template<typename T>
void BinaryTree<T>::dispaly()
{
    inorder(root);
    std::cout << std::endl;
}

int main()
{
    BinaryTree<int> binarytree;
    int array[7] = { 10,2,30,4,50,8};
    
    for(int i = 0; i<7; ++i)
    {
        binarytree.create_binary_tree(array[i]);
    }

    binarytree.dispaly();
    cout << "binary tree cout:" << binarytree.count(binarytree.root) << endl;
    cout <<"find max:" << binarytree.find_max(binarytree.root)->data << endl;
    cout <<"find min:" << binarytree.find_min(binarytree.root)->data << endl;
}