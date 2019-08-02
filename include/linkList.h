#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

//定义结构体指针
struct node
{
    int data;
    node *prev;
    node *next;
};
class doublelinks
{
public:
    doublelinks();
    ~doublelinks();

public:
    void doublelink_insert(doublelinks *ptr, unsigned int position, int member); //插入
    void doublelink_erase(doublelinks *ptr, unsigned int position);              //删除
    void doublelink_display(doublelinks *ptr);                                   //显示
    int doublelink_getlength(doublelinks *ptr);                                  //得到长度
private:
    int length;
    node *root;
};

#endif