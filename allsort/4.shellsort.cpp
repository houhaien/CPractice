/*************************************************************************
	> File Name: 4.shellsort.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月02日 星期六 11时01分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

void ShowArr(int arr[], int length){
    if (arr == nullptr || length <= 0)
        return;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ShellSort(int arr[], int length){
    if (arr == NULL || length <= 0)
        return;
    int increment = length;
    while (increment > 1)
    {
        increment = increment / 3 + 1;
        for (int i = increment; i < length; i++)
        {
            int temp = arr[i];
            if (arr[i] < arr[i - increment])
            {
                int j;
                for (j = i - increment; j >= 0 && arr[j] > temp; j = j - increment)
                    arr[j + increment] = arr[j];
                arr[j + increment] = temp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ShellSort(arr, n);
    ShowArr(arr, n);
    return 0;
}
