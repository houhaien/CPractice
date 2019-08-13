/*************************************************************************
	> File Name: 170.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年06月28日 星期五 20时46分37秒
 ************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

void string_replace( string &strBig,  const string &strsrc,  const string &strdst)
{
    string::size_type pos = 0; //替换字符串的位置
    string::size_type srclen = strsrc.size();//替换字符串的长度
    string::size_type dstlen = strdst.size();//目的字符串的长度
    
    while( (pos=strBig.find(strsrc, pos)) != string::npos )
    {
        strBig.replace( pos, srclen, strdst );
        pos += dstlen;
    }
}

int main(){
    int n;
    cin >> n;
    int m = n;
    string s[n + 5];
    int cnt = 0;
    while (n--) {
        string strContent;
        cin >> strContent;
        string_replace(strContent, "Ban_smoking", "No_smoking");
        //cout << strContent << endl;
        s[cnt] = strContent;
        cnt++;
    }
    
    //cout << s[0] << endl;
    //cout << s[1] << endl;
    for (int i = 0; i < m; i++) {
        cout << s[i] << endl;
    }

    return 0;
}
