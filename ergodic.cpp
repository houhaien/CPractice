/*************************************************************************
	> File Name: ergodic.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年07月14日 星期日 15时19分15秒
 ************************************************************************/

//根据前序队列，中序队列，推后序

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node* init(int data) {
    Node *node =(Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}
//后序遍历
void postorder(Node *node) {
    if (node->lchild != NULL) {
        postorder(node->lchild);
    }
    if (node->rchild != NULL) {
        postorder(node->rchild);
    }
    printf("%d ", node->data);
}

Node *build(char pre_str[], char in_str[], int len) {
    Node *p = init(pre_str[0] - '0');
    int pos = strchr(in_str, pre_str[0]) - in_str;
    //通过strchr找到p[0]在in_str里的位置，再减去in_str的首地址就是p[0]在in_str里第几个数
    if(pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    }
    if (len - pos -1 > 0) {
        p->rchild = build(pre_str + pos + 1, in_str + pos +1, len - pos - 1);

    }
    return p;
}

void clear(Node *node) {
    if (node->lchild != NULL) {
        clear(node->lchild);
    }
    if (node->rchild != NULL) {
        clear(node->rchild);
    }
    free(node);
}

int main() {
    char pre_str[] = "136945827";
    char in_str[] = "963548127";
    Node *root = build(pre_str, in_str, strlen(pre_str));
    postorder(root);
    printf("\n");
    clear(root);
    return 0;
}
