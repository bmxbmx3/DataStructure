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
typedef struct t_node{
    int data;
    //p_idx指向父节点
    int p_idx;
}t_node;

/**
 * 树的链式存储：链表结构体
 */
typedef struct branch{
    //c_idx孩子结点数组下标
    int c_idx;
    //next，指向下一个链表结点指针
    struct branch *next;
}branch;

/**
 * 树的链式存储：树结构体
 */
typedef struct t_link_node{
    int data;
    //fist，指向链表的第一个孩子结点指针，链表存有多个孩子结点，链表作为元素存在数组中
    struct branch *first;
}t_link_node;

/**
 * 树的顺序存储：简化结构
 *
 * 数组的元素内容指向父节点索引
 */
void tree_init(int max_size){
    int tree[max_size];
    tree[0]=-1;
    tree[1]=0;
    tree[2]=0;
    tree[3]=1;
    tree[4]=1;
}

/**
 * 二叉树结构体
 */
typedef struct bt_node{
    int data;
    //左孩子
    struct bt_node *l_child;
    //右孩子
    struct bt_node *r_child;
}bt_node;

/**
 * 二叉链表结构体（二叉链表由树转化）
 */
typedef struct bt_link_node{
    int data;
    //左孩子
    struct bt_link_node *child;
    //右孩子
    struct bt_link_node *sibling;
}bt_link_node;

//video6-------------------------------

/**
 * 先、中、后序遍历二叉树
 * @param p 二叉树结点
 */
void r(bt_node* p){
    if(p!=NULL){
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
void visit(bt_node *p){

}

/**
 * 二叉树层次遍历
 * @param bt 根结点
 * @param max_size 存树结点的栈容量
 */
void preorder_nonrecursion(bt_node *bt,int max_size){
    if(bt!=NULL){
        /**
         * 变量定义：
         * stack[]，存结点的辅助栈
         * top，辅助栈顶指针
         * p，暂存待处理的二叉树结点
         */
        bt_node *stack[max_size];
        int top=-1;
        bt_node *p=NULL;

        top++;
        stack[top]=bt;
        while (top!=-1){
            /**
             * 出栈一个结点
             */
            p=stack[top];
            top--;
            //访问该结点
            visit(p);

            /**
             * 访问出栈结点的左右孩子结点（注意访问顺序），再入栈
             */
            if(p->r_child!=NULL){
                /**
                 * 访问右孩子，入栈
                 */
                top++;
                stack[top]=p->r_child;
            }
            if(p->l_child!=NULL){
                top++;
                stack[top]=p->l_child;
            }
        }
    }
}