/*************************************************************************
	> File Name: array.c
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年05月04日 星期六 16时48分48秒
 ************************************************************************/

#include <stdio.h>

int func(int *a) {
    *(a+0) = 123; // *a = 123, a[0] = 123;
    return 0;
}
int func1(int a[]) {
    return 0;
}
//   
//   *(arr + i) <==> arr[i]     代表第i个元素

int main() {
    int arr[100];
    printf("arr[0] = %p   arr = %p\n",&arr[0],&arr);
    printf("arr+1 = %p\n",arr+1);
    char *p = (char *)arr;
    printf( " p+1= %p",p+1 );
    int n = 0;
    //当我们在函数内部修改参数并传出叫传出参数
    func(&n);
    //传一位数组 ,arr代表首地址
    func(arr);

    printf("%d\n",n);
    //读字符串
    char str[1000];
    scanf("%s",str);
    printf("%s\n",str);
    /*
    for(int i = 0; i < 10; i++) {
        scanf("%d",arr + i);
        //scanf("%d",&arr[i]);
    }
    */

    return 0;
}
