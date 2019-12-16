//
// Created by Administrator on 2019/12/16 0016.
//

#include "tree.h"
#include "stdio.h"
#include "stdlib.h"

//video3----------------

/**
 * 树的顺序存储：结点结构体
 */
typedef struct t_node {
    int data;
    //p_idx指向父节点
    int p_idx;
} t_node;

/**
 * 树的链式存储：链表结构体
 */
typedef struct branch {
    //c_idx孩子结点数组下标
    int c_idx;
    //next，指向下一个链表结点的指针
    struct branch *next;
} branch;

/**
 * 树的链式存储：树结构体
 */
typedef struct t_link_node {
    int data;
    //first，指向链表的第一个孩子结点指针，链表存有多个孩子结点，链表作为元素存在数组中
    struct branch *first;
} t_link_node;

/**
 * 树的顺序存储：简化结构
 *
 * 数组的元素内容指向父节点索引
 */
void tree_init(int max_size) {
    int tree[max_size];
    tree[0] = -1;
    tree[1] = 0;
    tree[2] = 0;
    tree[3] = 1;
    tree[4] = 1;
}

/**
 * 二叉树结构体
 */
typedef struct bt_node {
    int data;
    //左孩子
    struct bt_node *l_child;
    //右孩子
    struct bt_node *r_child;
} bt_node;

/**
 * 二叉链表结构体（二叉链表由树转化）
 */
typedef struct bt_link_node {
    int data;
    //左孩子
    struct bt_link_node *child;
    //右孩子
    struct bt_link_node *sibling;
} bt_link_node;

//video6-------------------------------

/**
 * 先、中、后序遍历二叉树
 * @param p 二叉树结点
 */
void r(bt_node *p) {
    if (p != NULL) {
        //visit(p); 先序遍历
        r(p->l_child);
        //visit(p); 中序遍历
        r(p->r_child);
        //visit(p); 后序遍历
    }
}

//video7------------------------

/**
 * 访问二叉树结点
 * @param p 二叉树结点
 */
void visit(bt_node *p) {

}

/**
 * 二叉树先序遍历非递归（遍历指visit()的顺序）
 * @param bt 根结点
 * @param max_size 存树结点的栈容量
 */
void preorder_nonrecursion(bt_node *bt, int max_size) {
    //记得预先结点判空
    if (bt != NULL) {
        /**
         * 变量定义：
         * stack[]，存结点用于遍历的辅助栈
         * top，辅助栈顶指针
         * p，暂存待处理的二叉树结点
         */
        bt_node *stack[max_size];
        int top = -1;
        bt_node *p = NULL;

        top++;
        stack[top] = bt;
        while (top != -1) {
            /**
             * 出栈一个结点
             */
            p = stack[top];
            top--;
            //访问该结点
            visit(p);

            /**
             * 访问出栈结点的左右孩子结点（注意访问顺序，先右再左），再入栈
             */
            if (p->r_child != NULL) {
                /**
                 * 访问右孩子，入栈
                 */
                top++;
                stack[top] = p->r_child;
            }
            if (p->l_child != NULL) {
                top++;
                stack[top] = p->l_child;
            }
        }
    }
}

/**
 * 二叉树后序遍历非递归（遍历指visit()的顺序）
 * @param bt 根结点
 * @param max_size 存树结点的栈容量
 */
void postorder_nonrecursion(bt_node *bt, int max_size) {
    //记得预先结点判空
    if (bt != NULL) {
        /**
         * 变量定义：
         * stack1[]，存结点用于遍历的辅助栈，生成逆后序序列
         * stack2[]，让逆后序序列变成后序序列
         * top1，stack1栈栈顶记录
         * top2，stack2栈栈顶记录
         * p，暂存待处理的二叉树结点
         */
        bt_node *stack1[max_size];
        int top1 = -1;
        bt_node *stack2[max_size];
        int top2 = -1;
        bt_node *p = NULL;
        top1++;
        stack1[top1] = bt;

        /**
         * 类比层次遍历，不过这里生成逆后序序列
         */
        while (top1 != -1) {
            /**
             * stack1出栈一个元素，入栈stack2
             */
            p = stack1[top1];
            top1--;
            top2++;
            stack2[top2] = p;

            /**
             * 访问出栈结点的左右孩子结点（注意访问顺序，先左再右），再入栈
             */
            if (p->l_child != NULL) {
                /**
                 * 访问左孩子，入栈
                 */
                top1++;
                stack1[top1] = p->l_child;
            }
            if (p->r_child != NULL) {
                top1++;
                stack1[top1] = p->r_child;
            }
        }

        /**
         * stack2一直出栈并访问，逆后序变成后序序列
         */
        while (top2 != -1) {
            p = stack2[top2];
            top2--;
            visit(p);
        }
    }
}

/**
 * 二叉树中序遍历非递归（遍历指visit()的顺序）
 * @param bt 根结点
 * @param max_size 存树结点的栈容量
 */
void inorder_nonrecursion(bt_node *bt, int max_size) {
    //记得预先结点判空
    if (bt != NULL) {
        /**
         * 变量定义：
         * stack[]，存结点用于遍历的辅助栈
         * top，stack栈栈顶记录
         * p，暂存待处理的二叉树结点
         */
        bt_node *stack[max_size];
        int top = -1;
        bt_node *p = NULL;
        p = bt;

        /**
         * 这里while的判断条件是为了防止出栈导致栈空，p所指的右孩子结点不空时，再开始主循环whie时，若
         * 只判断栈空，即while(top!=-1)，会让后续遍历终止，故while (top!=-1||p!=NULL)
         */
        while (top != -1 || p != NULL) {

            /**
             * 一直向下遍历左结点，并入栈
             */
            while (p != NULL) {
                top++;
                stack[top] = p;
                p = p->l_child;
            }

            /**
             * 从栈中弹出一个结点，访问，然后向下遍历其第一个右结点
             */
            if (top != -1) {
                p = stack[top];
                top--;
                visit(p);
                p = p->r_child;
            }
        }
    }
}

//video8---------------------------------------------------------
/**
 * 二叉树层次遍历
 * @param bt
 * @param max_size
 */
void level(bt_node *bt, int max_size) {
    if (bt != NULL) {
        /**
         * 变量定义：
         * que[]，存树结点的辅助队列
         * front，que队列队头
         * rear，que队列队尾
         * p暂存处理过程中的树结点
         */
        int front, rear;
        bt_node *que[max_size];;
        front = rear = 0;
        bt_node *p;

        /**
         * 队列入队根结点
         */
        rear = (rear + 1) % max_size;
        que[rear] = bt;

        while (front != rear) {
            /**
             * 从队列取一个元素并访问
             */
            front = (front + 1) % max_size;
            p = que[front];
            visit(p);

            /**
             * 依次入队左孩子结点、右孩子结点（注意入队顺序）
             */
            if (p->l_child != NULL) {
                rear = (rear + 1) % max_size;
                que[rear] = p->l_child;
            }
            if (p->r_child != NULL) {
                rear = (rear + 1) % max_size;
                que[rear] = p->r_child;
            }
        }
    }
}

/**
 * 树的先序遍历
 * @param p 根结点
 * @param tree 结点数组
 */
void pre_order(t_link_node *p, t_link_node tree[]) {
    //预先判断根结点不为空
    if (p != NULL) {
        visit(p);
        branch *q;
        q = p->first;
        while (q != NULL) {
            pre_order(&tree[q->c_idx], tree);
            q = q->next;
        }
    }
}