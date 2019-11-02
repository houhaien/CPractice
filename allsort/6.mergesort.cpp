/*************************************************************************
	> File Name: 6.mergesort.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月02日 星期六 11时41分29秒
 ************************************************************************/
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void merge(int arr[], int left, int mid, int right){   
    std::vector<int> *result = new std::vector<int>();
    int l = left;
    int m = mid;
    while(l <= mid -1 && m <= right)
    {  
        if( arr[l] <= arr[m] ){
            result->push_back(arr[l++]);
        }           
        else {
            result->push_back(arr[m++]);
        }   
    }  
    while(l <= mid -1){
        result->push_back(arr[l++]);
    }  
    while(m <= right){
        result->push_back(arr[m++]);
    }
    for(auto item : *result)
    {                                                      
        arr[left++] = item;
    }
}   
    
void mergeSort(int arr[], int left, int right){   
    if( right - left < 2) 
    {
        if( arr[left] > arr[right])
        {
            std::swap(arr[left], arr[right]);
        }
        return ;
    }
    int m = (right + left)/ 2 ;
    mergeSort(arr, left, m);
    mergeSort(arr, m+1, right);
    merge(arr, left, m+1, right);
}   
    
int main(){   
    int test[10];
    for(int i = 0; i < 10; ++i){
        cin >> test[i];
    }
    std::cout <<"排序前"<< std::endl;
    for(int i = 0; i < 10; ++i){
        std::cout << test[i]<<" " ;
    }
    std::cout << std::endl;
    mergeSort(test,0,9);
    std::cout <<"排序后"<< std::endl;                                                   
    for(int i = 0; i < 10; ++i)
    {
        std::cout << test[i]<<" " ;
    }
    std::cout << std::endl;
    return 0;
} 

