//定义数据结构
//构造一个类
//创建类中功能函数
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
    cout << "btree cout:" << binarytree.count(binarytree.root) << endl;
}