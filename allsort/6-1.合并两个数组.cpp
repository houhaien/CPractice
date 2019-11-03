/*************************************************************************
	> File Name: 6-1.合并两个数组.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月03日 星期日 18时58分09秒
 ************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;


void merge(int *nums, int *nums1, int length1,
                      int *nums2, int length2) {
 	int i, j, k;

    i = j = k = 0;

    while (i < length1 || j < length2) {

        if (i == length1) {

            nums[k++] = nums2[j++];

        } else if (j == length2) {

            nums[k++] = nums1[i++];

        } else {

            nums[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];

        }

    }   
}
int main() {
    int n, m;
    scanf("%d %d",&n, &m);
    int *num = (int*)malloc((n + m) * sizeof(int));
    int *num1 = (int*)malloc(n * sizeof(int));
    int *num2 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", num1 + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", num2 + i);
    }
    for (int i = 0; i < 1000; ++i) {
        free(num);
        num = (int*)malloc((n + m) * sizeof(int));
        merge(num, num1, n, num2, m);
    }
    for (int i = 0; i < n + m; ++i) {
        printf("%d%c", num[i], i == n + m - 1? '\n' : ' ');
    }
    free(num);
    free(num1);
    free(num2);
    return 0;
}

