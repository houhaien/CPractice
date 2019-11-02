/*************************************************************************
	> File Name: 5.selectsort.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月02日 星期六 11时26分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

void selectSort(int arr[],int n){
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        int j;
        // 找出最小值得元素下标
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        int tmp = arr[index];
        arr[index] = arr[i];
        arr[i] = tmp;
    }

}
void out(int arr[], int n) {
    for(int i = 0; i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
void put() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectSort(arr, n);
    out(arr, n);
}
int main() {
    put();
    return 0;
}
