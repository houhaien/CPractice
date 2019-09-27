/*************************************************************************
	> File Name: t1.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年05月18日 星期六 16时49分13秒
 ************************************************************************/

#include "test.h"
#include <stdio.h>

int add(int a,int b){
    return a+b;
}

TEST(test, add_func){
    EXPECT_EQ(add(2,3),5);
    EXPECT_GT(add(3,3),4);
    EXPECT_EQ(add(4,3),7);
    EXPECT_EQ(add(5,3),8);
    EXPECT_NE(add(6,3),10);
}

int main(){
    
    return RUN_ALL_TESTS();
    
}
