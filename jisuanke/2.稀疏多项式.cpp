/*************************************************************************
	> File Name: 2.稀疏多项式.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月04日 星期五 11时31分29秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 25

int num[max_n + 5] = {0};

int main() {
    int m, c, e, x;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c >> e;
        num[e] = c;
    }
    cin >> x;
    int sum = 0;
    for (int i = 0; i < max_n; i++) {
        sum += (int)pow(x, i) * num[i];
    }
    cout << sum << endl;
    return 0;
}
