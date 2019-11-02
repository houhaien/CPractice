/*************************************************************************
	> File Name: 7.Heap.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月02日 星期六 12时03分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    //默认大顶堆
    priority_queue<int> a;
    //小顶堆
    priority_queue<int , vector<int>, greater<int>> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a.push(i);
        s.push(i);
    }
    cout << "大 :" << endl;
    while(!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
    cout << "小：　"<< endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
