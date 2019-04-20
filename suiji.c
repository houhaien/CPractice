/*************************************************************************
	> File Name: suiji.c
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年04月20日 星期六 19时27分03秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int cnt = 0;
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        i == 0 || printf(" ");
        printf("%d", rand() % 100);
        //求偶数
        //cnt += !(i & 1);
        //cnt += (i % 2 == 0);
        //cnt += !(i % 2);
        cnt += !((rand() % 100) % 2);
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}
