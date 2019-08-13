/*************************************************************************
	> File Name: 232.二维前缀和.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年08月13日 星期二 14时09分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 5000
int M[MAXN +5][MAXN +5];
int G[MAXN +5][MAXN +5];


int main() {
    int n ,r, x, y, w;
    int maxx = 0, maxy = 0;
    cin >> n >> r;
    for (int i = 1; i <= n; i++ ) {
        cin >> x >> y >>w;
        ++x, ++y;
        maxx = max(x, maxx);
        maxy = max(y, maxy);
        M[x][y] = max(M[x][y], w);
    }
    for (int i = 1; i <= maxx; i++) {
        for (int j = 1; j <= maxy ; j++) {
            G[i][j] = G[i-1][j] + G[i][j-1] - G[i-1][j-1] + M[i][j];
        }
    }
    int ans = 0;
    for (int x = 1; x <= maxx ; x++) {
        for (int y = 1; y <= maxy; y++) {
            int q = min(x + r - 1, maxx );
            int p = min(y + r - 1, maxy);
            ans = max(ans, G[q][p] - G[x-1][p] - G[q][y-1] + G[x-1][y-1]);
        }
    }

    cout << ans <<endl;
    return 0;
}


// max 和min 都是在控制范围
