#ifndef _List_H
#define _List_H

#include<iostream>
//链表数据结构由数据和指向下一个数据的指针组成
template<typename T>
struct node
{
    T data;
    node<T> *next;
};

//构造一个链表类，包含查找删除插入等函数
template<typename T>
class List
{
    private:
        /* data */
        node<T> *head, *tail;      //定义链表的头部指针和尾部指针
        int position;

    public:
        List()
        {
            head = tail = NULL;
        }
        ~List()
        {
            delete head;
            delete tail;
        }

        void insert(T data);           //向链表中插入数据
        void print();
};

#endif