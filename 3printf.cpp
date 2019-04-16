/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月11日 星期四 22时18分35秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    char s[100];
    FILE *fout = fopen("/dev/null", "w");
    //把文件写入回收站，不在占用output空间
    printf("%d\n", fprintf(fout , "%d",n));

    int num = sprintf(s,"%d",n);
    printf("\n");
    printf("%d\n",num);
    return 0;
}
