//
// Created by Administrator on 2019/12/16 0016.
//

#include <sys/param.h>
#include "stack_and_queue.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

//video1----------------------------------------------------

/**
 * 链栈结构体：单链表结构体
 */
typedef struct l_node {
    int data;
    struct l_node *next;
} l_node;

/**
 * 栈：定义
 * @param max_size 栈的容量
 */
void stack_init(int max_size) {
    int stack[max_size];
    //top记录栈顶位置，-1表栈空
    int top = -1;
}

/**
 * 栈：出栈
 * @param stack 栈
 * @param top 栈顶位置
 */
void stack_pop(int stack[], int top) {
    int x = stack[top];
    top--;
}

/**
 * 栈：入栈
 * @param stack 栈
 * @param top 栈顶位置
 * @param x 入栈元素
 */
void stack_push(int stack[], int top, int x) {
    top++;
    stack[top] = x;
}

/**
 * 栈：判断栈满
 * @param max_size 栈的容量
 * @param top 栈顶位置
 * @return 判断结果
 */
int stack_full(int max_size, int top) {
    if (top == max_size - 1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 栈：判断栈空
 * @param top 栈顶位置
 * @return 判断结果
 */
int stack_empty(int top) {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 链栈：定义
 */
void link_stack_init() {
    l_node *head = (l_node *) malloc(sizeof(l_node));
    head->next = NULL;
    l_node *top = NULL;
}

/**
 * 链栈：入栈
 * @param head 头结点指针
 * @param top 栈顶指针
 */
void link_stack_push(l_node *head, l_node *top) {
    /**
     * 新建栈顶结点
     */
    top = (l_node *) malloc(sizeof(l_node));
    top->next = NULL;
    top->data = 'C';

    /**
     * 链表插入
     */
    top->next = head->next;
    head->next = top;
}

/**
 * 链栈：出栈
 * @param head 头结点指针
 * @param top 栈顶指针
 */
void link_stack_pop(l_node *head, l_node *top) {
    //取元素
    int x = top->data;
    //链表删除
    head->next = top->next;
    //记得释放结点
    free(top);
    //top指针后移
    top = head->next;
}

/**
 * 链栈：判断栈空
 * @param head 头结点指针
 * @return 判断结果
 */
int link_stack_empty(l_node *head) {
    if (head->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

//video2------------------------------------

/**
 * 链队结构体：利用链栈结构体（也是单链表结构体）
 */
typedef struct queue {
    l_node *front;
    l_node *rear;
} queue;

/**
 * 队列：定义（也是循环队列的定义）
 * @param max_size 队列容量
 */
void queue_init(int max_size) {
    int queue[max_size];
    //front队头，用于出队；rear队尾，用于入队
    int front = 0, rear = 0;
}

/**
 * 队列：出队
 * @param queue 队列
 * @param front 队头位置
 */
void queue_out(int queue[], int front) {
    front++;
    //x出队元素
    int x = queue[front];
}

/**
 * 队列：入队（注意假溢出）
 * @param queue 队列
 * @param rear 队尾位置
 * @param x 入队元素
 */
void queue_in(int queue[], int rear, int x) {
    rear++;
    queue[rear] = x;
}

/**
 * 循环队列：入队
 * @param queue 循环队列
 * @param rear 队尾位置
 * @param max_size 循环队列容量
 * @param x 入队元素
 */
void circular_queue_in(int queue[], int rear, int max_size, int x) {
    rear = (rear + 1) % max_size;
    queue[rear] = x;
}

/**
 * 循环队列：出队
 * @param queue 循环队列
 * @param front 队头位置
 * @param max_size 循环队列容量
 */
void circular_queue_out(int queue[], int front, int max_size) {
    front = (front + 1) % max_size;
    int x = queue[front];
}

/**
 * 循环队列：判断队空
 * @param queue 循环队列
 * @param front 队头位置
 * @param rear 队尾位置
 * @return 判断结果
 */
int circular_queue_empty(int queue[], int front, int rear) {
    if (front == rear) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 循环队列：判断队满
 * @param queue 循环队列
 * @param front 队头位置
 * @param rear 队尾位置
 * @param max_size 循环队列容量
 * @return 判断结果
 */
int circular_queue_full(int queue[], int front, int rear, int max_size) {
    if (front == (rear + 1) % max_size) {
        return 1;
    } else {
        return 0;
    }
}

//video9--------------------------------------------------------------

/**
 * 共享栈：定义
 * @param max_size 共享栈容量
 */
void shared_stack_init(int max_size) {
    int stack[max_size];
    //top[]记录两个栈的栈顶位置，top[0]记录第一个栈的，top[1]第二个栈
    int top[2] = {-1, max_size};
}

/**
 * 共享栈：判断s1栈空
 * @param top s1、s2栈顶位置
 * @return 判断结果
 */
int shared_stack_s1_empty(int top[]){
    if(top[0]==-1){
        return 1;
    } else{
        return 0;
    }
}

/**
 * 共享栈：判断s2栈空
 * @param top s1、s2栈顶位置
 * @return 判断结果
 */
int shared_stack_s2_empty(int top[]){
    if(top[1]==-1){
        return 1;
    } else{
        return 0;
    }
}

/**
 * 共享栈：s1入栈（类比栈的入栈）
 * @param stack 共享栈
 * @param top s1、s2栈顶位置
 * @param x 入站元素
 */
void shared_stack_s1_push(int stack[],int top[],int x){
    top[0]++;
    stack[top[0]]=x;
}

/**
 * 共享栈：s2入栈
 * @param stack 共享栈
 * @param top s1、s2栈顶位置
 * @param x 入站元素
 */
void shared_stack_s2_push(int stack[],int top[],int x){
    top[1]++;
    stack[top[1]]=x;
}

/**
 * 共享栈：判断栈满
 * @param top s1、s2栈顶位置
 * @return 判断结果
 */
int shared_stack_full(int top[]){
    //s1、s2栈顶位置相邻，则共享栈满
    if(top[0]+1==top[1]){
        return 1;
    } else{
        return 0;
    }
}

//video10------------------------------------------------------
/**
 * 用栈求表达式值：判断运算符优先级
 * @param op 运算符，即'+''-''*''/'
 * @return 优先级
 */
int get_priority(char op){
    /**
     * '+''-'优先级低，返0；'*''/'优先级高，返1；
     */
    if (op=='+'||op=='-'){
        return 0;
    } else{
        return 1;
    }
}

/**
 * 用栈求表达式值：计算表达式（两个操作数、一个运算符）运算结果
 * @param opand1 第一个操作数
 * @param op 运算符
 * @param opand2 第二个操作数
 * @param result 运算结果
 * @return 表达式求值结果成功标志
 */
int cal_sub(float opand1,char op,float opand2,float *result){
    if(op=='+'){
        *result=opand1+opand2;
    }
    if(op=='-'){
        *result=opand1+opand2;
    }
    if(op=='*'){
        *result=opand1+opand2;
    }
    if(op=='/'){
        /**
         * 判断除数是否为0
         */
        //由于c语言float的存储特点，用小于一个极小值1e-6来判断是否为0
        if(fabs(opand2)<1e-6){
            return 0;
        } else{
            *result=opand1+opand2;
        }
    }
    return 1;
}

/**
 * 用栈求表达式值：从s1栈取两个操作数，从s2栈取一个操作符，求结果
 * @param s1 存操作数的栈
 * @param top1 s1栈顶指针
 * @param s2 存操作符的栈
 * @param top2 s2栈顶指针
 * @return 运算成功标志
 */
int cal_stack_top_two(float s1[],int *top1,char s2[],int *top2){
    /**
     * 变量定义
     *
     * opnd1、opnd2两个操作数
     * result操作结果
     * op运算符
     * flag运算成功标志
     */
    float opnd1,opnd2,result;
    char op;
    int flag;

    /**
     * 从s1栈取两个操作数
     */
    (*top1)--;
    opnd2=s1[*top1];
    (*top1)--;
    opnd1=s1[*top1];

    /**
     * 从s2栈取一个操作符
     */
    (*top2)--;
    op=s2[*top2];

    /**
     * 计算结果
     */
    flag=cal_sub(opnd1,op,opnd2,&result);
    //运算错误报错
    if(flag==0){
        puts("error");
    }

    /**
     * 将运算结果存入s1栈
     */
    (*top1)++;
    s1[*top1]=result;
    return flag;
}

void cal_in_result(int exp[],int max_size){
    /**
     * 变量定义
     *
     *
     */
    float s1[max_size];
    int top1=-1;
    char s2[max_size];
    int top2=-1;
    int i=0;

    while (exp[i]!='\0'){
        if('0'<=exp[i]&&exp[i]<='9'){
            top1++;
            s1[top1]=exp[i]-'0';
            i++;
        } else if(exp[i]=='('){
            top2++;
            s2[top2]='(';
            i++;
        }
    }
}
