//
// Created by Administrator on 2019/12/14 0014.
//

#include "linear_list.h"
#include "stdio.h"
#include "stdlib.h"

int insert_elem(int *num, int max_size, int *length, int p, int e);

void print_array(int num[], int length);

int delete_elem(int num[], int *length, int p, int *e);

//----------------------------------

/**
 * 顺序存储结构：初始化
 */
void test1() {
    // 顺序结构初始化
    // max_size为数组长度
    int max_size = 5;
    int num[max_size];
    //length为存放的元素个数，初始化为0
    int length = 0;
}

/**
 * 单链表、单循环链表：初始化、判空
 */
void test2() {
    //链式结构体
    typedef struct node {
        //存数据
        int data;
        //指向下一个结点
        struct node *next;
    } node;

    //带头结点单链表初始化
    node *head1;
    head1 = (node *) malloc(sizeof(node));
    head1->next = NULL;

    //不带头结点初始化单链表
    node *head2 = NULL;

    //带头结点单循环链表初始化
    node *head3;
    head3 = (node *) malloc(sizeof(node));
    head3->next = head3;

    //带头结点单链表判空
    if (head1->next == NULL) {
        printf("带头结点单链表判空成功\n");
    }

    //带头结点单链表判空
    if (head2 == NULL) {
        printf("不带头结点单链表判空成功\n");
    }

    //带头结点单循环链表判空
    if (head3->next == head3) {
        printf("带头结点单循环链表判空成功\n");
    }
}

/**
 * 双链表、双循环链表：初始化、判空
 */
void test3() {
    //双链表、双循环链表结构体
    typedef struct node {
        //存储数据
        int data;
        //指向前驱结点
        struct node *next;
        //指向后继结点
        struct node *prior;
    } node;

    //双链表初始化
    node *head1;
    head1 = (node *) malloc(sizeof(node));
    head1->next = NULL;

    //双循环链表初始化
    node *head2;
    head2 = (node *) malloc(sizeof(node));
    head2->next = head2;
    head2->prior = head2;

    //带头结点双链表判空
    if (head1->next == NULL) {
        printf("带头结点双链表判空成功\n");
    }

    //带头结点双循环链表判空
    if (head2->next == head2 || head2->prior == head2) {
        printf("带头结点双循环链表判空成功\n");
    }
}

/**
 * 静态链表：初始化、插入
 */
void test4() {
    //静态链表结构体
    typedef struct node {
        //存数据
        int data;
        //存下一个结点的索引
        int next;
    } node;

    //静态链表初始化
    int max_size = 5;
    node num[max_size];
    //定义一个指针p
    int p = 1;
    //取p指针指向的结点值，类比p->data
    num[p].data = 1;
    //取p后继结点指针，类比p->next，这里-1类比NULL
    num[p].next = -1;

    //静态链表插入
    int q = 2;
    num[q].data = 3;
    num[q].next = -1;
    //在p后插入结点q
    //类比q->next=p->next；p->next=q；
    num[q].next = num[p].next;
    num[p].next = q;
}

//-----------------------------------------

/**
 * 顺序表：初始化、插入、删除
 */
void test5() {
    //max_size为数组长度
    int max_size = 5;
    int num[max_size];
    //length记录顺序表存储元素个数
    int length = 3;

    //顺序表初始化
    for (int i = 0; i < length; ++i) {
        num[i] = i;
    }

    //顺序表插入：在第p个位置插入数字e
    printf("原数组为：\n");
    print_array(num, length);
    int sign1 = insert_elem(num, max_size, &length, 1, 3);
    if (sign1 == 0) {
        printf("插入失败");
    } else {
        printf("插入后数组为:\n");
        print_array(num, length);
    }

    //顺序表删除：在第p个位置删除，返回删除后的元素e
    printf("原数组为：\n");
    print_array(num, length);
    //e记录删除的元素
    int *e;
    int sign2 = delete_elem(num, &length, 1, &e);
    if (sign2 == 0) {
        printf("删除失败");
    } else {
        printf("删除后数组为:\n");
        print_array(num, length);
    }
}

int insert_elem(int *num, int max_size, int *length, int p, int e) {
    /*检查是否满足插入条件：
     * 1、元素个数小于数组长度
     * 2、插入的位置在 0-数组长度 的范围内
     */
    if (p < 0 || p > *length || *length == max_size) {
        return 0;
    }

    //为了插入元素，p-length-1 位置上的数依次往后挪一位
    for (int i = *length - 1; i >= p; --i) {
        num[i + 1] = num[i];
    }

    //在数组第p个位置插入元素e
    num[p] = e;

    //数组元素长度改变
    (*length)++;
    return 1;
}

int delete_elem(int num[], int *length, int p, int *e) {
    if (p < 0 || p > (*length) - 1) {
        return 0;
    }

    //返回删除的元素
    *e = num[p];

    //为了删除元素，p-length-1 位置上的数依次往前挪一位
    for (int i = p; i < (*length) - 1; ++i) {
        num[i] = num[i + 1];
    }

    //数组元素长度改变
    (*length)--;
    return 1;
}
//------------------------

/**
 * 链表插入：头插、尾插
 */
void test6() {
    //单链表结构体
    typedef struct node {
        int data;
        struct node *next;
    } node;

    //尾插法
    {
        //初始化单链表头结点
        node *head1 = (node *) malloc(sizeof(node));
        head1->next = NULL;

        //p为新建结点，r始终指向head头结点
        node *p = NULL, *r = head1;
        for (int i = 0; i < 5; ++i) {
            //初始化结点
            p = (node *) malloc(sizeof(node));
            p->next = NULL;
            p->data = i;

            //尾插法，最后一个结点后插入，r始终指向最后一个结点
            p->next = r->next;
            r->next = p;
            r = p;
        }
    }

    //头插法
    {
        //初始化单链表头结点
        node *head2 = (node *) malloc(sizeof(node));
        head2->next = NULL;

        //p为新建结点
        node *p = NULL;
        for (int i = 0; i < 5; ++i) {
            //初始化结点
            p = (node *) malloc(sizeof(node));
            p->next = NULL;
            p->data = i;

            //头插法，在head2与第一个结点之间插入
            p->next = head2->next;
            head2->next = p;
        }
    }
}

/**
 * 顺序表逆置
 */
void test7() {
    int num[5] = {1, 2, 3, 4, 5};
    int left = 1;
    int right = 4;
    int temp;
    for (int i = left, j = right; i < j; ++i, --j) {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    print_array(num, 5);
}

/**
 * 单链表逆置
 */
void test8() {
    typedef struct node {
        int data;
        struct node *next;
    } node;

    node *head = (node *) malloc(sizeof(node));
    head->next = NULL;

    //新建的结点
    node *p = NULL;
    //头插法构造链表
    for (int i = 0; i < 4; ++i) {
        p = (node *) malloc(sizeof(node));
        p->data = i;
        p->next = NULL;

        //头插法加入新建结点
        p->next = head->next;
        head->next = p;
    }

    //输出单链表内容
    printf("单链表内容：\n");
    node *temp1 = head->next;
    while (temp1 != NULL) {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");

    //单链表从头结点一直往下遍历,a1、a2为交换位置
    node *r = head, *a1, *a2;
    for (int j = 0; j < 4; ++j) {
        if (j == 0) {
            a1 = r;
        }
        if (j == 3) {
            a2 = r;
        }
        r = r->next;
    }

    //交换a1与a2位置链表结点，t指向a1下一个结点
    node *t;
    while (1) {
        //类似a1后删除一个结点
        t = a1->next;
        a1->next = t->next;

        //类似a2后插入一个结点
        t->next = a2->next;
        a2->next = t;

        //a1下一个结点为a2，表明交换完毕
        if (a1->next == a2) {
            break;
        }
    }

    //输出单链表内容
    printf("单链表内容：\n");
    node *temp2 = head->next;
    while (temp2 != NULL) {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
    printf("\n");

}

/**
 * 顺序表找最值
 */
void test9() {
    int num[4] = {2, 4, 1, 3};
    //max记录最大值，min记录最小值
    int max = num[0], min = num[0];
    for (int i = 0; i < 4; ++i) {
        //找最大值
        if (max < num[i]) {
            max = num[i];
        }

        //找最小值
        if (min > num[i]) {
            min = num[i];
        }
    }

    printf("最小值为%d，最大值为%d",min,max);
}

void test10(){

}
//--------------------------------
/**
 * 输出数组
 * @param num 待输出数组
 * @param length 数组长度
 */
void print_array(int num[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
