#include <iostream>
#include "linkList.h"

using namespace std;
//做好初始化，根节点长度等的赋值
doublelinks::doublelinks()
{
    root = new node;
    root->prev = NULL;
    root->next = NULL;
    length = 0;
}

doublelinks::~doublelinks()
{
    delete root; //删除根节点
}
//插入
void doublelinks::doublelink_insert(doublelinks *ptr, unsigned int position, int member)
{
    node *nodeinsert = new node;
    nodeinsert->data = member;
    //如果还没有插入过元素，根节点的后指针指向第一个元素，根节点不存数据不计数。
    if (ptr->length == 0)
    {
        ptr->root->next = nodeinsert;
        nodeinsert->prev = ptr->root;
        nodeinsert->next = NULL;
    }
    else
    {
        if (position == 0) //要插入的是第 0 个位置
        {
            nodeinsert->prev = ptr->root;
            nodeinsert->next = ptr->root->next;
            ptr->root->next->prev = nodeinsert;
            ptr->root->next = nodeinsert;
        }
        else
        {
            node *current = ptr->root->next; //从根节点的下一个元素开始查找
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
            nodeinsert->next = current;
            nodeinsert->prev = current->prev;
            current->prev->next = nodeinsert;
            current->prev = nodeinsert;
        }
    }
    ptr->length++;
}
//删除
void doublelinks::doublelink_erase(doublelinks *ptr, unsigned int position)
{
    if (ptr->length == 0 || ptr->length < position)
    {
        cout << "链表为空，oop！！或者 删除长度不存在！！" << endl;
    }
    else
    {
        if (ptr->length == 1)
        {
            delete ptr->root->next;
            ptr->root->next = NULL;
        }
        else
        {
            node *deletenode = ptr->root->next;
            for (int i = 0; i < position; i++)
            {
                deletenode = deletenode->next;
            }
            deletenode->prev->next = deletenode->next;
            deletenode->next->prev = deletenode->prev;
            delete deletenode;
        }
    }
    ptr->length--;
}
int doublelinks::doublelink_getlength(doublelinks *ptr)
{
    return ptr->length;
}
void doublelinks::doublelink_display(doublelinks *ptr)
{
    node *current = ptr->root->next;
    for (int i = 0; i < ptr->length; i++)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
