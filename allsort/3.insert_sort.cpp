/*************************************************************************
	> File Name: 3.insert_sort.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月02日 星期六 10时41分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <functional>

using namespace std;

#define MAXN 100
int arr[MAXN + 5];

int main() {
    int n, x, j;
    cin >> n;
    int k = 0;
    for (int i = 0; i  < n; i++) {
        cin >> x;
        for ( j = i; j > 0; j--) {
            if (arr[j - 1] > x) {
                arr[j] = arr[j-1];
            } else {
                break;
            }
            k++;
            cout <<"比较" << x << " :" << arr[j - 1] << endl;
            cout << "k = " << k << endl;
        }
        arr[j] = x;
    }
    int i = 0;
    while(arr[i]) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
    return 0;
}
