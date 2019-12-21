//定义数据结构
//构造一个类
//创建类中功能函数
#include<iostream>

using namespace std;

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
        void inorder(tree *);
        int count(tree *temp);
        void dispaly()
        {
            inorder(root);
            cout << endl;
        }
};

//创建二叉树
void BinaryTree::create_binary_tree(int dat)
{
    tree *newNode = new tree;
    newNode -> data = dat;
    newNode ->left = NULL;
    newNode ->right = NULL;

    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        tree *currentNode = root;
        tree *back;
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
int BinaryTree::count(tree *temp)
{
    int num = 0;
    if(temp != NULL)
    {
        num = count(temp -> left) + count(temp -> right) + 1;
    }
    
    return num;
}

//这是中序遍历二叉树，采用了递归的方法.递归还是有点绕啊。。。
void BinaryTree::inorder(tree *temp)     
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
}

int main()
{
    BinaryTree btree;
    int array[7] = { 10,2,30,4,5,8};
    for(int i = 0; i<7; ++i)
    {
        btree.create_binary_tree(array[i]);
    }

    btree.dispaly();
    cout << "btree cout:" << btree.count(btree.root) << endl;

}