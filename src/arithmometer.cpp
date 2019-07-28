/* 四则运算
 * author： Zhichao Guo
 * date:    2019.07.27
 * 1.遇到数字，直接输出
 * 2.遇到左括号进栈
 * 3.遇到右括号执行出栈操作，直到弹出左括号，左括号和右括号不输出
 * 4.遇到其他操作符，则判断其与栈顶操作符的优先级，如果其优先级（<=）栈顶操作符，则栈顶元素依次出栈，该操作符进栈
 * 5.直到最后，将栈中的元素依次输出
 */
#include <iostream>
#include <stack>
#include <string>
#include "arithmometer.h"

using namespace std;

static bool isOperator(char op)
{
    string operatorString = "+-*/()";
    for (int idx = 0; idx < operatorString.size(); idx++)
    {
        if (op == operatorString[idx])
            return true;
    }
    return false;
}

static int getPrioraty(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

static bool prioraty(char o1, char o2)
{
    return getPrioraty(o1) <= getPrioraty(o2);
}

string middleExp2SuffixExp(string exp) //中缀表达式到后缀表达式的转换
{
    stack<char> inputtempStack;
    stack<char> inputStack;  //存放输入表达式的栈
    stack<char> outputStack; //管理操作符的入栈和出栈
    string outputQueue;      //存放最终的输出序列

    for (int i = 0; i < exp.size(); i++) //摘取出输入字符串中非空格部分然后入栈作为输入
    {
        char cur = exp[i];
        if (cur != ' ')
        {
            inputtempStack.push(cur);
        }
    }

    for (int i = 0, count = inputtempStack.size(); i < count; i++) //将栈顶调整为表达式的开始
    {
        inputStack.push(inputtempStack.top());
        inputtempStack.pop();
    }

    cout << "step one" << endl;
    while (!inputStack.empty())
    {
        char cur = inputStack.top(); //取出栈顶元素
        if (isOperator(cur))         //判断是否是操作符，然后对操作符进行操作
        {
            if (cur == '(') //遇到左括号：将其入栈
            {
                outputStack.push(cur);
            }
            else if (cur == ')') //遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，括号不输出。
            {
                char po = outputStack.top();
                while (po != '(' && !outputStack.empty())
                {
                    outputQueue += po;
                    outputStack.pop();
                    po = outputStack.top();
                }

                if (po != '(')
                {
                    cout << "error: unmatched ()" << endl;
                }
                outputStack.pop(); //将 '(' 出栈，不能将其保存到输出序列当中
            }
            else //遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
            {
                while (!outputStack.empty() && prioraty(cur, outputStack.top()))
                {
                    outputQueue += outputStack.top();
                    outputStack.pop();
                }
                outputStack.push(cur);
            }
        }
        else //遇到操作数：直接输出（添加到后缀表达式中）
        {
            outputQueue += cur;
        }
        inputStack.pop(); //栈顶元素操作完之后将其移除
    }
    cout << "step two" << endl;
    if (!outputStack.empty())
    {
        if (outputStack.top() == ')' || outputStack.top() == '(')
        {
            cout << "error: unmatched ()" << endl;
        }
        while (!outputStack.empty())
        {
            outputQueue += outputStack.top();
            outputStack.pop();
        }
    }
    cout << "step three" << endl;
    return outputQueue;
}
