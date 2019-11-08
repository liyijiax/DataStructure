/*************************************************************************
	> File Name: 242hahu.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月03日 星期日 19时02分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define max_n 100000
long long arr[max_n + 5];
long long b[max_n + 5];

bool check(long long *arr, long long n, long long m, long long val) {
    long long num = 0, sum = 0, pre_sum = 0;
    //for (long long i = 1; i <= n; i++) b[i] = arr[i] - val;
    //for (long long i = 1; i <= n; i++) b[i] += b[i - 1];
    for (long long i = 1; i <= n; i++) {
        sum += arr[i] - val;
        if (i < m) continue;
        num = min(num, pre_sum);
        if (sum - num >= 0) return true;
        pre_sum += arr[i - m + 1] - val;
    }
    return false;
}

long long binary_search(long long *arr, long long l, long long r, long long n, long long m) {
    if (l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if (check(arr, n, m, mid)) return binary_search(arr, mid, r, n, m);
    return binary_search(arr, l, mid - 1, n, m);
}

int main() {
    long long n, m, min_num, max_num;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] *= 1000;
        if (i == 1) min_num = max_num = arr[i];
        min_num = min(min_num, arr[i]);
        max_num = max(max_num, arr[i]);
    }
    cout << binary_search(arr, min_num, max_num, n, m);
    return 0;
}















//写到什么位置思考什么位置，该干什么干什么有条不紊
