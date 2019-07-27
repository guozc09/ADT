#include <iostream>
#include <stack>
#include <vector>
#include <deque>

#include "rabbit_numbers.h"

using namespace std;

int main()
{
    stack<int> first; //构造一个用于存放int类型的空栈(默认底层容器为deque)，size=0。

    deque<int> mydeque(3, 100); //构造一个包含3个int元素的双端队列
    stack<int> second(mydeque); //用自己的双端队列构造一个栈（size=3）

    stack<int, vector<int>> third; //指明用vector实现一个栈（存放int），空栈size=0

    vector<int> myvector(2, 200);             //构造一个存放2个元素的vector
    stack<int, vector<int>> fourth(myvector); //用自己的vector构造一个栈，size=2

    //输出四个栈的大小
    cout << "size of first: " << first.size() << endl;
    cout << "size of second: " << second.size() << endl;
    cout << "size of third: " << third.size() << endl;
    cout << "size of fourth: " << fourth.size() << endl;

    stack<int> mystack;

    for (int i = 0; i < 5; ++i)
    {
        mystack.push(i); //push函数将参数元素加入栈中，没有返回值（例如这里循环将0,1,2,3,4加入栈中，注意栈顶元素是4）
    }
    cout << "size: " << mystack.size() << endl; //size函数返回栈的大小（此时有5个元素，size=5）

    while (!mystack.empty()) //empty函数返回一个bool值，栈为空时返回true，否则返回false
    {
        cout << ' ' << mystack.top(); //top函数的返回值是栈顶元素（注意并没有删掉栈顶元素）
        mystack.pop();                //pop函数将栈顶元素删掉，没有返回值
    }
    cout << endl;

    int rabbits =  rabbitNumbers(10);

    cout << "兔子数量为：" << rabbits << endl;

    return 0;
}

