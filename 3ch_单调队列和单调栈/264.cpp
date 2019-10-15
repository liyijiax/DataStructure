/*************************************************************************
	> File Name: 264.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年10月15日 星期二 20时02分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 100000

long long h[max_n + 5];
int l[max_n + 5], r[max_n + 5];
int s[max_n + 5], top = 0;

int main() {
    int n;
    cin >> n;
    h[0] = s[n + 1] = -1;
    for (int i = 1; i <= n; i++) cin >> h[i];
    s[++top] = 0;
    for (int i = 0; i < n; i++) {
        while (h[i] <= h[s[top]] ) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (h[i] <= h[s[top]]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    cout << ans << endl;
    return 0;
}
// 注意是不是严格单调关系
