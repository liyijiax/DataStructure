/*************************************************************************
	> File Name: 270.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月15日 星期二 19时08分40秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 300000

//全局变量默认初始化为零
int s[max_n + 5];
int q[max_n + 5], head, tail;

int main() {
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    head = tail = 0;
    q[tail++] = 0;
    ans = s[1];
    for (int i = 1; i <= n; i++) {
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[i] < s[q[tail - 1]]) tail--;
        q[tail++] = i;
    }
    cout << ans << endl;
    return 0;
} 
