#include "List.h"

using namespace std;

template<typename T>
void List<T>::insert(T data)
{
    if(head == NULL)
    {
        head = tail = new node<T>;
        head ->data = data;
        tail ->data = data;
        head ->next =  tail ->next = NULL;         //永远不要忘记将链表的下一个节点置为NULL
    }
    else
    {
        node<T> *_node = new node<T>;
        _node ->data = data;
        tail ->next = _node;  //将新的节点放到原链表的尾部
        tail = _node;         //更新链表尾部
        tail ->next = NULL;
    }
    
}

template<typename T>
void List<T>::print()
{
    node<T> *_node = head;
    cout << "print list:" << endl;
    while (_node != NULL)
    {
        cout << _node ->data << ' ';
        _node = _node ->next;
    }
    cout << endl;
}

int main()
{
    int array[7] = {10,2,30,4,50,8,9};
    List<int> list;

    for(int i = 0; i<7; ++i)
    {    
        list.insert(array[i]);
    }

    list.print();

    return 0;
}