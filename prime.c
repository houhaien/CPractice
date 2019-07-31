/*************************************************************************
	> File Name: prime.c
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年05月04日 星期六 14时33分07秒
 ************************************************************************/

#include <stdio.h>
#define MAX 10000
int prime[MAX + 5] = {0};

int main() {
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            prime[j] = 1;
        }
    }   
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        //printf("%d\n",i);
    }
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",prime[n]);
    }
    return 0;
}
