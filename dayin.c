/*************************************************************************
	> File Name: dayin.c
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年05月04日 星期六 20时49分38秒
 ************************************************************************/

#include <stdio.h>
//日志打印 (正常情况下不会出现) ，若想出现，编译时为 gcc -DDEBUG dayin.c
//变参宏 变参函数，变参列表
#ifdef DEBUG // 如果有DEBUG 就允许下边的代码
#define LOG(frm,arg...){\
    printf("[%s : %s : %d]",__FILE__,__func__,__LINE__);\
    printf(frm,##arg);\
    printf("\n");\
}
#else
#define LOG(frm,args...){}
#endif

void testsscanf_sprintf() {
    char str[1502] = "123 456 789 987";
    int  a,b,c,d;
    //  sscanf(str, "%d%d%d%d",&a,&b,&c,&d);
    sscanf(str,"%d%[^$]s",&a,str);
    sscanf(str,"%d%[^$]s",&b,str);
    sscanf(str,"%d%[^$]s",&c,str);
    sscanf(str,"%d%[^$]s",&d,str);
    sprintf(str,"%d %d %d %d \n",a,b,c,d);
    int offset = 0;
    offset += sprintf(str + offset, "a = %d  ", a);
    offset += sprintf(str + offset, "b = %d  ", b);
    offset += sprintf(str + offset, "c = %d  ", c);
    offset += sprintf(str + offset, "d = %d  ", d);

    LOG("%s",str);
}
int main() {
    testsscanf_sprintf();
    LOG("%d",5);
    return 0;
}
