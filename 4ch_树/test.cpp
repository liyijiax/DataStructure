/*************************************************************************
	> File Name: test.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月19日 星期六 14时15分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

static int i = 0;

void f() {
    cout << i << endl;
    i++;
    f();
}

int main() {
    f();
    return 0;
}
