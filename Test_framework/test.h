/*************************************************************************
	> File Name: test.h
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年05月18日 星期六 18时25分39秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define __COLOR(a,b) "\033[" #b "m" a "\033[0m"
#define COLOR(a,b) __COLOR(a,b)

#define RED(a) COLOR(a,31)
#define YELLOW(a) COLOR(a,33)
#define GREEN(a) COLOR(a,32)

#define __funname(a,c) a##b
#define funname(a,b) __funname(a,b)
#define STR(a) #a

//函数执行之前存地址
#define TEST(a,b) \
void funname(a,funname(_,funname(b,funname(_,Test)))) ();\
__attribute__((constructor))  void funname(add_Test, __COUNTER__) (){\
    pfundata p = (pfundata) malloc(sizeof(fundata));\
    p->func = funname(a,funname(_,funname(b,funname(_,Test))));\
    p->name_part1 = STR(a);\
    p->name_part2 = STR(b);\
    tail->next = p;\
    tail = p;\
 }\
void funname(a,funname(_,funname(b,funname(_,Test))))()

#define TYPE_STR(a) _Generic((a), \
    int : "%d",\
    double : "%lf",\
    float: "%f", \
    char : "%c",\
    const char *: "%s"\
)
#define P(a,color){ char frm[100];sprintf(frm,color("%s"),TYPE_STR(a));printf(frm,a); }
#define EXPECT(a,b,c) { \
    __typeof(a) __temp_a = a, __temp_b = b;\
    if(__temp_a c __temp_b) addsuccess();\
    else{  addfailed(__FILE__,__LINE__,"expect:" #a " " #c " " #b);\
        printf(YELLOW("actual: "));\
        P(__temp_a,YELLOW);\
        P("vs",YELLOW);\
        P(__temp_b,YELLOW);\
        printf("\n\n");\
    }\
    printf("%s %s %s %s\n",STR(a),STR(c), STR(b), __temp_a c __temp_b ? "TRUE" :"FALSE");\
}

#define EXPECT_EQ(a,b) EXPECT(a,b, ==)
#define EXPECT_GT(a,b) EXPECT(a,b, >)
#define EXPECT_LT(a,b) EXPECT(a,b, <)
#define EXPECT_NE(a,b) EXPECT(a,b, !=)

typedef void (*funtype) ();

typedef struct fundata {
    funtype func;
    const char *name_part1;
    const char *name_part2;
    struct fundata *next;
} fundata,*pfundata;

static pfundata head , *tail = &head;
typedef struct totaldata {
    int succ,fail;
}totaldata;

static totaldata info;

void cleartotaldata() {
    info.succ = info.fail = 0;
}
void addsuccess() {
    info.succ += 1;
}
void addfailed(const char *file,int line,const char *msg) {
    printf(YELLOW("%s:%d: Failure\n"),file,line);
    printf(YELLOW("%s\n"), msg);
    info.fail+=1;
}

int RUN_ALL_TESTS() {
    pfundata p = head->next;
    while(p != NULL){
        printf("\n[ " GREEN("RUN") " ] %s.%s\n", p->name_part1,p->name_part2);
        cleartotaldata();
        p->func();
        p = p->next;
        double rate = 1.0 * info.succ/(info.succ+info.fail);
        const char *outputstr = NULL;
        char outputfrm[100];
        if(info.fail == 0) outputstr = YELLOW("%6.2lf%%");
        else outputstr = RED("%6.2lf%%");
        sprintf(outputfrm,"[ %s ] total : %%3d expect : %%3d\n", outputstr);
        printf(outputfrm , rate * 100, info.succ+info.fail,info.fail);
    }
    return 0;
}
#endif
