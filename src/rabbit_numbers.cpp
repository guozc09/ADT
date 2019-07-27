#include <iostream>
#include "rabbit_numbers.h"

using namespace std;

/* 利用数据结构栈来实现递归运算 */

int rabbitNumbers(int months) {
    if (months <= 2) {
        return months;
    }
    return rabbitNumbers(months -1) + rabbitNumbers(months - 2);
}