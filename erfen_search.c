/*************************************************************************
	> File Name: erfen_search.c
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年05月04日 星期六 15时18分20秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int binary_search(int *arr, int n,int x) {
    int head = 0; 
    int tail = n-1;
    int mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}
int arr[100];
double mysqrt(double y) {
    #define EXP 1e-7
    double head = 0, tail = y, mid;
    while(tail - head >= EXP) {
        mid = (head + tail) / 2.0;
        if (mid * mid < y) {
            head = mid;
        } else {
            tail = mid;
        }
    }
    return head;
}

double f(double x, double y) {
    return x * x-y;
}
double fdao(double x) {
    return 2*x;
}
double newtonsqrt(double y) {
    #define EXP 1e-7
    double x = 0;
    while (fabs(f(x,y)) > EXP) {
        x = x- (f(x,y))/fdao(x);
    }
    return x;
}
int main() {
    
    printf("%lf\n",mysqrt(2.0));
    printf("%lf\n",newtonsqrt(5.0));
    int n ,m;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    printf("%d\n", binary_search(arr, n,m));
    
    return 0;
}
