/*************************************************************************
	> File Name: 242hz.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月03日 星期日 18时53分47秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 100000

int num[max_n + 5];

int check(int m) {
    queue<int> q;
}

int main() {
    int n, m, max_num = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i], max_num = max(max_num, num[i]);
    int head = 1, tail = max_num, mid;
    while (head < tail) {
        mid = (head + tail  + 1) >> 1;
        if (check(mid) == 1) head = mid;
        else tail = mid - 1;
    }
    cout << head;
    return 0;
}
