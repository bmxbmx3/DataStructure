//
// Created by Administrator on 2019/12/14 0014.
//

#include "linear_list.h"
#include "stdio.h"
#include "stdlib.h"

//----------------------

//链式结构体
typedef struct node1 {
    //存数据
    int data;
    //指向下一个结点
    struct node1 *next;
} node1;

//双链表、双循环链表结构体
typedef struct node2 {
    //存储数据
    int data;
    //指向前驱结点
    struct node2 *next;
    //指向后继结点
    struct node2 *prior;
} node2;

//静态链表结构体
typedef struct node3 {
    //存数据
    int data;
    //存下一个结点的索引
    int next;
} node3;

//声明----------------------------

void print_list(node1 *a);

int insert_elem(int *num, int max_size, int *length, int p, int e);

void print_array(int num[], int length);

int delete_elem(int num[], int *length, int p, int *e);

void init_node(node1 **head);

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
 * 单链表、单循环链表：判空
 */
void test2() {
    //带头结点单链表初始化
    node1 *head1;
    head1 = (node1 *) malloc(sizeof(node1));
    head1->next = NULL;

    //不带头结点初始化单链表
    node1 *head2 = NULL;

    //带头结点单循环链表初始化
    node1 *head3;
    head3 = (node1 *) malloc(sizeof(node1));
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
 * 双链表、双循环链表：判空
 */
void test3() {

    //双链表初始化
    node2 *head1;
    head1 = (node2 *) malloc(sizeof(node2));
    head1->next = NULL;

    //双循环链表初始化
    node2 *head2;
    head2 = (node2 *) malloc(sizeof(node2));
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
    //静态链表初始化
    int max_size = 5;
    node3 num[max_size];
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
    //尾插法
    {
        //初始化单链表头结点
        node1 *head1 = (node1 *) malloc(sizeof(node1));
        head1->next = NULL;

        //p为新建结点，r始终指向head头结点
        node1 *p = NULL, *r = head1;
        for (int i = 0; i < 5; ++i) {
            //初始化结点
            p = (node1 *) malloc(sizeof(node1));
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
        node1 *head2 = (node1 *) malloc(sizeof(node1));
        head2->next = NULL;

        //p为新建结点
        node1 *p = NULL;
        for (int i = 0; i < 5; ++i) {
            //初始化结点
            p = (node1 *) malloc(sizeof(node1));
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
    node1 *head = (node1 *) malloc(sizeof(node1));
    head->next = NULL;

    //新建的结点
    node1 *p = NULL;
    //头插法构造链表
    for (int i = 0; i < 4; ++i) {
        p = (node1 *) malloc(sizeof(node1));
        p->data = i;
        p->next = NULL;

        //头插法加入新建结点
        p->next = head->next;
        head->next = p;
    }

    //输出单链表内容
    printf("单链表内容：\n");
    node1 *temp1 = head->next;
    while (temp1 != NULL) {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");

    //单链表从头结点一直往下遍历,a1、a2为交换位置
    node1 *r = head, *a1, *a2;
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
    node1 *t;
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
    node1 *temp2 = head->next;
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
        //擂台赛找最大值
        if (max < num[i]) {
            max = num[i];
        }

        //擂台赛找最小值
        if (min > num[i]) {
            min = num[i];
        }
    }

    printf("最小值为%d，最大值为%d", min, max);
}

/**
 * 单链表找最值
 */
void test10() {
    //num[]给单链表赋值
    int num[4] = {2, 4, 1, 3};
    node1 *head = (node1 *) malloc(sizeof(node1));
    head->next = NULL;

    //单链表尾插法初始化
    node1 *p, *r = head;
    for (int i = 0; i < 4; ++i) {
        p = (node1 *) malloc(sizeof(node1));
        p->data = num[i];
        p->next = NULL;

        p->next = r->next;
        r->next = p;
        r = p;
    }

    //找最值
    int min = head->next->data;
    int max = head->next->data;
    node1 *temp = head->next;
    while (temp != NULL) {
        //擂台赛找最小值
        if (min > temp->data) {
            min = temp->data;
        }

        //擂台赛找最大值
        if (max < temp->data) {
            max = temp->data;
        }

        temp = temp->next;
    }

    //输出单链表内容
    printf("最大值%d，最小值%d", max, min);
}

/**
 * 顺序表归并
 */
void test11() {
    //a[]、b[]分别为待合并的有序数组
    int a[] = {1, 4, 6};
    int b[] = {2, 5};
    //a_length记录a[]数组长度，b_length同理
    int a_length = 3, b_length = 2;
    //c[]为排序好的数组
    int c[5] = {};

    //i、j、k分别记录遍历a[]、b[]、c[]的位置
    int i = 0, j = 0, k = 0;
    while (i < a_length && j < b_length) {
        //比较a[]、b[]，将二者中最小的元素扫进c[]
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = b[j];
            k++;
            j++;
        }
    }

    //将a[]剩余未比较的元素扫入c[]
    while (i < a_length) {
        c[k] = a[i];
        k++;
        i++;
    }

    //将b[]剩余未比较的元素扫入c[]
    while (j < b_length) {
        c[k] = b[j];
        k++;
        j++;
    }

    print_array(c, a_length + b_length);
}

//------------------------
/**
 * 初始化结点
 * @param head 头结点指针
 */
void init_node(node1 **head) {
    (*head) = (node1 *) malloc(sizeof(node1));
    (*head)->next = NULL;
}

/**
 * 链表归并
 */
void test12() {
    int a[] = {1, 2, 3};
    int a_length = 3;
    int b[] = {4, 6};
    int b_length = 2;

    //初始两个单链表，p、q指向a_head、b_head单链表头结点，c_head、d_head存合并后的单链表，temp为待插入的新建结点
    node1 *a_head, *b_head, *c_head, *d_head, *p, *q, *temp;
    init_node(&a_head);
    init_node(&b_head);
    init_node(&c_head);
    init_node(&d_head);

    p = a_head;
    for (int i = 0; i < a_length; ++i) {
        temp = (node1 *) malloc(sizeof(node1));
        temp->data = a[i];
        temp->next = NULL;

        //尾插法
        temp->next = p->next;
        p->next = temp;
        p = temp;
    }

    q = b_head;
    for (int i = 0; i < b_length; ++i) {
        init_node(&temp);
        temp->data = b[i];

        //尾插法
        temp->next = q->next;
        q->next = temp;
        q = temp;
    }

    //链表正序合并-------------------------------------------------
    p = a_head->next;
    q = b_head->next;
    temp = c_head;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            //尾插法，跟尾插法还有点区别，p要向后移动，不然p被并入到新链表后不知道下一个并入的结点是什么
            temp->next = p;
            p = p->next;
            temp = temp->next;
        } else {
            temp->next = q;
            q = q->next;
            //类比顺序表k++
            temp = temp->next;
        }

        //链接剩余未并入的链表
        if (p != NULL) {
            temp->next = p;
        }
        if (q != NULL) {
            temp->next = q;
        }
    }

    //链表逆序合并------------------------------------------------------------
    p = a_head->next;
    q = b_head->next;
    temp = d_head;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            /*头插法，跟头插法还有点区别，p要向后移动，不然p被并入到新链表后不知道下一个并入的结点是什么
             * 注意将一个结点卸下后，再头结点插入d_head链表
             */
            temp = p;
            p = p->next;
            temp->next = d_head->next;
            d_head->next = temp;
        } else {
            temp = q;
            q = q->next;
            temp->next = d_head->next;
            d_head->next = temp;
        }
    }

    while (p != NULL) {
        temp = p;
        p = p->next;
        temp->next = d_head->next;
        d_head->next = temp;
    }

    while (q != NULL) {
        temp = q;
        q = q->next;
        temp->next = d_head->next;
        d_head->next = temp;
    }

    print_list(d_head);
}

//-------------------------------

/**
 * 顺序表划分：以第一个元素为枢纽
 * @param arr 顺序表
 * @param n 顺序表长
 */
void partition_1(int arr[], int n) {
    int temp;
    int i = 0, j = n - 1;
    temp = arr[i];
    while (i < j) {
        //j向左遍历，找到比temp所指位置小的数
        while (i < j && arr[j] >= temp) {
            j--;
        }

        //找到比temp所指位置小的数后，将j所指位置的数给i位置
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }

        //i遍历与j同理，不过i找的比temp位置的数大
        while (i < j && arr[i] >= temp) {
            i--;
        }

        //i赋值与j同理
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }
    }
    //最后i=j，两者相遇的地方就是比较的枢纽所放位置
    arr[i] = temp;
}

/**
 * 顺序表划分：以第一个元素为枢纽+比较元素
 * @param arr 顺序表
 * @param n 顺序表长
 * @param comp 所参照比较的元素
 */
void partition_2(int arr[], int n, int comp) {
    int temp;
    int i = 0, j = n - 1;
    temp = arr[i];
    while (i < j) {
        //j向左遍历，找到比comp小的数
        while (i < j && arr[j] >= comp) {
            j--;
        }

        //找到比temp所指位置小的数后，将j所指位置的数给i位置
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }

        //i遍历与j同理，不过i找的比temp位置的数大
        while (i < j && arr[i] >= comp) {
            i--;
        }

        //i赋值与j同理
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }
    }
    //最后i=j，两者相遇的地方就是比较的枢纽所放位置
    arr[i] = temp;
}

/**
 * 顺序表划分：以第k个元素为枢纽
 * @param arr 顺序表
 * @param n 顺序表长
 * @param k 第k个元素作枢纽
 */
void partition_3(int arr[], int n, int k) {
    int temp;
    int i = 0, j = n - 1;

    //将第k个位置与第0个位置的数交换
    temp = arr[0];
    arr[0] = arr[k];
    arr[k] = temp;
    while (i < j) {
        //j向左遍历，找到比comp小的数
        while (i < j && arr[j] >= temp) {
            j--;
        }

        //找到比temp所指位置小的数后，将j所指位置的数给i位置
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }

        //i遍历与j同理，不过i找的比temp位置的数大
        while (i < j && arr[i] >= temp) {
            i--;
        }

        //i赋值与j同理
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }
    }

    //最后i=j，两者相遇的地方就是比较的枢纽所放位置
    arr[i] = temp;
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

/**
 * 输出单链表
 * @param num 待输出单链表
 * @param length 数组长度
 */
void print_list(node1 *a) {
    while (a->next != NULL) {
        a = a->next;
        printf("%d", a->data);
    }

    printf("\n");
}