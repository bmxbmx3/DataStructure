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
int shared_stack_s1_empty(int top[]) {
    if (top[0] == -1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 共享栈：判断s2栈空
 * @param top s1、s2栈顶位置
 * @return 判断结果
 */
int shared_stack_s2_empty(int top[]) {
    if (top[1] == -1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 共享栈：s1入栈（类比栈的入栈）
 * @param stack 共享栈
 * @param top s1、s2栈顶位置
 * @param x 入站元素
 */
void shared_stack_s1_push(int stack[], int top[], int x) {
    top[0]++;
    stack[top[0]] = x;
}

/**
 * 共享栈：s2入栈
 * @param stack 共享栈
 * @param top s1、s2栈顶位置
 * @param x 入站元素
 */
void shared_stack_s2_push(int stack[], int top[], int x) {
    top[1]++;
    stack[top[1]] = x;
}

/**
 * 共享栈：判断栈满
 * @param top s1、s2栈顶位置
 * @return 判断结果
 */
int shared_stack_full(int top[]) {
    //s1、s2栈顶位置相邻，则共享栈满
    if (top[0] + 1 == top[1]) {
        return 1;
    } else {
        return 0;
    }
}

//video10------------------------------------------------------

/**
 * 用栈求表达式值：判断运算符优先级
 * @param op 运算符，即'+''-''*''/'
 * @return 优先级
 */
int get_priority(char op) {
    /**
     * '+''-'优先级低，返0；'*''/'优先级高，返1；
     */
    if (op == '+' || op == '-') {
        return 0;
    } else {
        return 1;
    }
}

/**
 * 计算中、前、后表达式（两个操作数、一个运算符）运算结果
 * @param opand1 第一个操作数
 * @param op 运算符
 * @param opand2 第二个操作数
 * @param result 运算结果
 * @return 表达式求值结果成功标志
 */
int cal_sub(float opand1, char op, float opand2, float *result) {
    if (op == '+') {
        *result = opand1 + opand2;
    }
    if (op == '-') {
        *result = opand1 + opand2;
    }
    if (op == '*') {
        *result = opand1 + opand2;
    }
    if (op == '/') {
        /**
         * 判断除数是否为0
         */
        //由于c语言float的存储特点，用小于一个极小值1e-6来判断是否为0
        if (fabs(opand2) < 1e-6) {
            return 0;
        } else {
            *result = opand1 + opand2;
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
int cal_stack_top_two(float s1[], int *top1, char s2[], int *top2) {
    /**
     * 变量定义
     *
     * opnd1、opnd2两个操作数，从s1栈取，注意类型为float
     * result操作结果
     * op运算符,从s2栈取，注意类型为char
     * flag运算成功标志
     */
    float opnd1, opnd2, result;
    char op;
    int flag;

    /**
     * 从s1栈取两个操作数
     */
    (*top1)--;
    opnd2 = s1[*top1];
    (*top1)--;
    opnd1 = s1[*top1];

    /**
     * 从s2栈取一个操作符
     */
    (*top2)--;
    op = s2[*top2];

    /**
     * 计算结果
     */
    flag = cal_sub(opnd1, op, opnd2, &result);
    //运算错误报错
    if (flag == 0) {
        puts("error");
    }

    /**
     * 将运算结果存入s1栈
     */
    (*top1)++;
    s1[*top1] = result;
    return flag;
}

/**
 * 用栈求中缀表达式值（需要两个栈）
 * @param exp 遍历的中缀表达式字符串
 * @param max_size 中缀表达式字符串字符个数
 * @return 计算结果
 */
float cal_in_result(char exp[], int max_size) {
    /**
     * 变量定义：
     *
     * s1[]存操作数栈，s1栈，为了高精度用float
     * s2[]存运算符栈，s2栈，用char存运算字符
     * top1、top2栈顶指针
     * i记录从前往后遍历exp[]位置
     */
    float s1[max_size];
    int top1 = -1;
    char s2[max_size];
    int top2 = -1;
    int i = 0;

    while (exp[i] != '\0') {
        /**
         * 将exp[]所存字符串的数字字符变为数字，然后入栈
         */
        if ('0' <= exp[i] && exp[i] <= '9') {
            top1++;
            //数字字符变数字，注意类型转换
            s1[top1] = (float) (exp[i] - '0');
            i++;

            /**
             * exp[]中左括号直接入栈
             */
        } else if (exp[i] == '(') {
            top2++;
            s2[top2] = '(';
            i++;

            /**
             * exp[]遍历遇到运算符（除左括号）时，有两种情况：
             *
             * 1、根据栈顶元素情况入栈
             *
             * 2、求值
             */
        } else if (exp[i] == '+' ||
                   exp[i] == '-' ||
                   exp[i] == '*' ||
                   exp[i] == '/') {
            /**
             * 1、运算符入栈：
             *
             * 1.1、s2栈空
             * 1.2、s2栈顶为左括号
             * 1.3、s2栈顶运算符优先级小于exp[]遍历到的运算符优先级
             */
            if (top2 == -1 ||
                s2[top2] == '(' ||
                get_priority(exp[i]) > get_priority(s2[top2])) {
                /**
                 * 运算符入栈s2[]
                 */
                top2++;
                s2[top2] = exp[i];
                //向后遍历exp[]
                i++;

                /**
                 * 2、求值
                 */
            } else {
                /**
                 * 如果不满足s2栈顶元素的三种情况（一般是exp[]遍历到的运算符优先级小于s1栈顶运算符），s2栈弹出运算符，s1栈弹出操作数，计算结果放入s1栈
                 *
                 * 这段代码出现了三次
                 */
                //s1栈弹出操作数，s2栈弹出运算符，计算结果放入s1栈（这段代码重复了三次）
                int flag = cal_stack_top_two(s1, &top1, s2, &top2);
                //求值不成功报错
                if (flag == 0) {
                    return 0;
                }
            }

            /**
             * 碰到右括号，s2栈一直弹出运算符直到碰到左括号，同时s1栈弹出操作数求值
             */
        } else if (exp[i] == ')') {
            while (s2[top2] != '(') {
                //s1栈弹出操作数，s2栈弹出运算符，计算结果放入s1栈
                int flag = cal_stack_top_two(s1, &top1, s2, &top2);
                if (flag == 0) {
                    return 0;
                }
            }
            //弹出左括号（左括号没用），s2栈顶减一
            top2--;
            //向后遍历exp[]
            i++;
        }
    }

    /**
     * exp[]遍历完，将s1栈和s2栈剩余元素继续求值
     */
    while (top2 != -1) {
        //s1栈弹出操作数，s2栈弹出运算符，计算结果放入s1栈
        int flag = cal_stack_top_two(s1, &top1, s2, &top2);
        if (flag == 0) {
            return 0;
        }
    }
    //返回计算结果，即s1栈顶元素
    return s1[top1];
}

//video11---------------------------------------------------------

/**
 * 用栈求后缀表达式值
 * @param exp 前缀表达式字符串所存数组
 * @param max_size 前缀表达式字符个数
 * @return 表达式求值结果
 */
float cal_post_fix(char exp[], int max_size) {
    //s栈存操作数及计算结果值
    float s[max_size];
    int top = -1;
    for (int i = 0; exp[i] != '\0'; ++i) {
        /**
          * 将exp[]所存字符串的数字字符变为数字，然后入栈
          */
        if ('0' <= exp[i] && exp[i] <= '9') {
            top++;
            //数字字符变数字，注意类型转换
            s[top] = (float) (exp[i] - '0');
            i++;

            /**
             * 如果是操作符，出栈操作数求值
             */
        } else {
            /**
             * 变量定义：
             *
             * opnd1、opnd2操作数
             * result求值结果
             * op操作符
             * flag记录求值成功标志
             */
            float opnd1, opnd2, result;
            char op;
            int flag;

            opnd2 = s[top];
            top--;
            opnd1 = s[top];
            top--;

            /**
             * 获得计算结果
             */
            op = exp[i];
            flag = cal_sub(opnd1, op, opnd2, &result);
            if (flag == 0) {
                puts("error");
                break;
            }

            /**
             * 计算结果入栈
             */
            top++;
            s[top] = result;
        }
    }

    //返回求值结果（相比中缀表达式求值，因为只有一个栈，不需要遍历栈的剩余元素）
    return s[top];
}

/**
 * 用栈求前缀表达式值（跟后缀类似）
 * @param exp 前缀表达式字符串所存数组
 * @param max_size 前缀表达式字符个数
 * @param len 前缀表达式字符个数
 * @return 表达式求值结果
 */
float cal_pre_fix(char exp[], int max_size, int len) {
    //s栈存操作数及计算结果值
    float s[max_size];
    int top = -1;
    for (int i = len - 1; i >= 0; --i) {
        /**
          * 将exp[]所存字符串的数字字符变为数字，然后入栈
          */
        if ('0' <= exp[i] && exp[i] <= '9') {
            top++;
            //数字字符变数字，注意类型转换
            s[top] = (float) (exp[i] - '0');
            i++;

            /**
             * 如果是操作符，出栈操作数求值
             */
        } else {
            /**
             * 变量定义：
             *
             * opnd1、opnd2操作数
             * result求值结果
             * op操作符
             * flag记录求值成功标志
             */
            float opnd1, opnd2, result;
            char op;
            int flag;

            /**
             * 取操作数顺序与后缀表示式求值相反
             */
            opnd1 = s[top];
            top--;
            opnd2 = s[top];
            top--;

            /**
             * 获得计算结果
             */
            op = exp[i];
            flag = cal_sub(opnd1, op, opnd2, &result);
            if (flag == 0) {
                puts("error");
                break;
            }

            /**
             * 计算结果入栈
             */
            top++;
            s[top] = result;
        }
    }

    //返回求值结果（相比中缀表达式求值，因为只有一个栈，不需要遍历栈的剩余元素）
    return s[top];
}

/**
 * 中缀转后缀表达式（函数结构类比求中缀表达式值）
 * @param infix 中缀表达式所在数组
 * @param s2 存中缀表达式转换后的后缀表达式
 * @param top2 s2栈顶指针
 * @param max_size 中缀表达式字符个数
 */
void infix_to_postfix(char infix[], char s2[], int *top2, int max_size) {
    /**
      * 变量定义：
      *
      * s1[]，s1栈，用于暂存运算符，用于后续运算符优先级的比较
      * top1，s1栈顶指针
      * i，遍历中缀表达式数组索引（这里从前往后遍历）
      */
    char s1[max_size];
    int top1 = -1;
    int i = 0;

    while (infix[i] != '\0') {
        /**
         * 中缀表达式中若遇到数字直接压入s2栈中
         */
        if ('0' <= infix[i] && infix[i] <= '9') {
            (*top2)++;
            s2[*top2] = infix[i];
            i++;

            /**
             * 中缀表达式中若遇到左括号直接压入s1栈中
             */
        } else if (infix[i] == '(') {
            top1++;
            s1[top1] = '(';
            i++;

            /**
             * 如果碰到'+''-''*''/'运算符：
             *
             * 1、根据栈顶元素情况入栈
             *
             * 2、由与栈顶运算符比较优先级，s1栈弹出一个运算符加入s2栈中
             */
        } else if (infix[i] == '+' ||
                   infix[i] == '-' ||
                   infix[i] == '*' ||
                   infix[i] == '/') {
            /**
             * 1、根据s1栈顶元素情况入栈：
             *
             * 1.1、s1栈空
             * 1.2、s1栈顶
             * 1.3、s1栈顶运算符优先级小于infix[]遍历到的运算符优先级（注意优先级比较为>）
             */
            if (top1 == -1 ||
                s1[top1] == '(' ||
                get_priority(infix[i]) > get_priority(s1[top1])) {
                top1++;

                //中缀表达式运算符入栈
                s1[top1] = infix[i];
                i++;

                /**
                 * 2、由与栈顶运算符比较优先级，s1栈弹出一个运算符加入s2栈中
                 */
            } else {
                /**
                 * 如果不满足s1栈顶元素的三种情况（一般是infix[]遍历到的运算符优先级小于s1栈顶运算符），s1栈弹出运算符入栈s2
                 *
                 * 这段代码出现了三次
                 */
                top2++;
                s2[*top2] = s1[top1];
                i++;
            }

            /**
             * 碰到右括号，s1栈一直弹出运算符放入s2栈，直到碰到左括号
             */
        } else if (infix[i] == ')') {
            while (s1[top1] != '(') {
                top2++;
                s2[*top2] = s1[top1];
                top1--;
                i++;
            }
        }
    }

    /**
     * infix[]遍历完，将s1栈剩余运算符压入s2栈中
     */
    while (top1 != -1) {
        top2++;
        s2[*top2] = s1[top1];
        top1--;
    }
}

/**
 * 中缀转前缀表达式（函数结构类比求中缀表达式值）
 * @param infix 中缀表达式所在数组
 * @param len 中缀表达式所在数组长度
 * @param s2 存中缀表达式转换后的前缀表达式
 * @param top2 s2栈顶指针
 * @param max_size 中缀表达式字符个数
 */
void infix_to_prefix(char infix[], int len, char s2[], int *top2, int max_size) {
    /**
      * 变量定义：
      *
      * s1[]，s1栈，用于暂存运算符，用于后续运算符优先级的比较
      * top1，s1栈顶指针
      * i，遍历中缀表达式数组索引（这里从后往前遍历）
      */
    char s1[max_size];
    int top1 = -1;
    int i = len - 1;

    while (i >= 0) {
        /**
         * 中缀表达式中若遇到数字直接压入s2栈中
         */
        if ('0' <= infix[i] && infix[i] <= '9') {
            (*top2)++;
            s2[*top2] = infix[i];
            i--;

            /**
             * 中缀表达式中若遇到左括号直接压入s1栈中
             */
        } else if (infix[i] == ')') {
            top1++;
            s1[top1] = ')';
            i--;

            /**
             * 如果碰到'+''-''*''/'运算符：
             *
             * 1、根据栈顶元素情况入栈
             *
             * 2、由与栈顶运算符比较优先级，s1栈弹出一个运算符加入s2栈中
             */
        } else if (infix[i] == '+' ||
                   infix[i] == '-' ||
                   infix[i] == '*' ||
                   infix[i] == '/') {
            /**
             * 1、根据s1栈顶元素情况入栈：
             *
             * 1.1、s1栈空
             * 1.2、s1栈顶
             * 1.3、s1栈顶运算符优先级小于infix[]遍历到的运算符优先级（注意优先级比较为>=）
             */
            if (top1 == -1 ||
                s1[top1] == ')' ||
                get_priority(infix[i]) >= get_priority(s1[top1])) {
                top1++;

                //中缀表达式运算符入栈
                s1[top1] = infix[i];
                //向前遍历infix[]
                i--;

                /**
                 * 2、由与栈顶运算符比较优先级，s1栈弹出一个运算符加入s2栈中
                 */
            } else {
                /**
                 * 如果不满足s1栈顶元素的三种情况（一般是infix[]遍历到的运算符优先级小于s1栈顶运算符），s1栈弹出运算符入栈s2
                 *
                 * 这段代码出现了三次
                 */
                top2++;
                s2[*top2] = s1[top1];
                i--;
            }

            /**
             * 碰到右括号，s1栈一直弹出运算符放入s2栈，直到碰到左括号
             */
        } else if (infix[i] == '(') {
            while (s1[top1] != ')') {
                top2++;
                s2[*top2] = s1[top1];
                top1--;
                i--;
            }
        }
    }

    /**
     * infix[]遍历完，将s1栈剩余运算符压入s2栈中
     */
    while (top1 != -1) {
        top2++;
        s2[*top2] = s1[top1];
        top1--;
    }
}

//video12------------------------------------------------------------------------------

/**
 * 判断一对括号是否匹配
 * @param left 左括号字符
 * @param right 右括号字符
 * @return 如果匹配，返1，否则返0
 */
int is_matched(char left, char right) {
    if (left == '(' && right == ')') {
        return 1;
    } else if (left == '[' && right == ']') {
        return 1;
    } else if (left == '{' && right == '}') {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 判断字符串中所有括号是否匹配
 * @param exp 待判断的字符串
 * @param max_size 暂存待处理括号的栈的容量
 * @return
 */
int is_parentheses_balanced(char exp[], int max_size) {
    //s[]，暂存待处理括号的辅助栈
    char s[max_size];
    int top = -1;

    /**
     * 从左往右遍历exp[]字符串进行括号匹配
     */
    for (int i = 0; exp[i] != '\0'; ++i) {
        /**
         * 碰到左括号直接入栈
         */
        if (exp[i] == '(' ||
            exp[i] == '[' ||
            exp[i] == '{') {
            top++;
            s[top] = exp[i];
        }

        /**
         * 碰到右括号，弹出一个栈顶元素与之匹配
         */
        if (exp[i] == ')' ||
            exp[i] == ']' ||
            exp[i] == '}') {
            /*
             * 如果栈空，表明括号匹配失败
             */
            if (top == -1) {
                return 0;
            }

            //弹出栈顶元素
            char left = s[top];
            top--;

            /**
             * 匹配栈顶元素与右括号，如果不匹配则括号匹配失败
             */
            if (is_matched(left, exp[i]) == 0) {
                return 0;
            }
        }
    }

    /**
     * 遍历完exp[]字符串，还有未匹配的括号，则括号匹配一定失败
     */
    if (top > -1) {
        return 0;
    }
    return 1;
}

/**
 * 递归函数用栈展开求值
 *
 * 递归函数F(m)=m*F(m/3)
 * @param m 递归的入参
 * @param max_size 暂存参数m的栈的容量
 * @return 递归求值结果
 */
int cal_f(int m, int max_size) {
    int cum = 1;
    //s[]，暂存每个递归入参的栈
    int s[max_size];
    int top = -1;

    //暂存每个递归入参
    while (m != 0) {
        top++;
        s[top] = m;
        m /= 3;
    }

    //从栈中依次弹出递归的入参，相乘求出结果保存到cum中
    while (top != -1) {
        cum *= s[top];
        top--;
    }

    return cum;
}