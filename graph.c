//
// Created by Administrator on 2019/12/17 0017.
//

#include "graph.h"
#include "stdlib.h"
#include "stdio.h"

//video1----------------------------------------------------------
/**
 * 邻接矩阵：初始化（注意结点为数字和非数字两种情况）
 */
void init_m_graph() {
    //如果图的结点为非数字，加上如char vertex[5]={'a','b','c','d','e'}

    //max，表示无穷大，图的结点之间没有连接就会表示无穷大
    float max = 99999;
    float m_graph[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            m_graph[i][j] = max;
        }
    }
}

//video2--------------------------------------------------------

/**
 * 图的邻接顶点结构体（类比链表数组）
 */
typedef struct arc_node {
    //adj_v，领接顶点的下标
    int adj_v;
    //next，指向下一个邻接顶点
    struct arc_node *next;
} arc_node;

/**
 * 图的链表头结点结构体（类比链表数组）
 */
typedef struct v_node {
    //data，存顶点内容
    int data;
    //first，指向链表第一个顶点（为邻接顶点的类型）
    struct arc_node *first;
} v_node;

/**
 * 图结构体
 */
typedef struct a_graph {
    //adj_list[]，存储图的链表数组
    v_node adj_list[10];
    //n，边的个数；e，顶点个数
    int n, e;
} a_graph;

//video3----------------------------------------------------------

/**
 * 访问图的顶点
 * @param v 图的顶点
 */
void visit_v(int v) {

}

/**
 * 图的深度优先遍历（代码类似树的先序遍历，在此基础上加了visit[]）
 * @param v 遍历的顶点的下标
 * @param g 图的结构体
 * @param visit 存顶点的访问记录（初始化为0），没访问过为0，访问过为1（visit[]存顶点下标）
 */
void dfs(int v, a_graph *g, int visit[]) {
    //记录访问过的顶点
    visit[v] = 1;
    //访问顶点
    visit_v(v);
    //取顶点v第一个邻接顶点
    arc_node *q = g->adj_list[v].first;
    while (q != NULL) {
        /**
         * 如果顶点q的邻接顶点没有访问过，则访问它，并再从链表数组取一条以它为起点的链表，
         * 并访问以它为起点的邻接顶点。
         *
         * 同时访问该顶点q的所有邻接顶点
         */
        if (visit[q->adj_v] == 0) {
            dfs(q->adj_v, g, visit);
            //访问顶点q的所有邻接顶点
            q = q->next;
        }
    }
}

//video4----------------------------------------------

/**
 * 图的广度优先遍历（代码类比树的广度优先遍历，在此基础上加了visit[]）
 * @param g 图
 * @param v 待访问的顶点
 * @param visit 存顶点的访问记录（初始化为0），没访问过为0，访问过为1
 * @param max_size 辅助队列的容量
 */
void bfs(a_graph *g, int v, int visit[], int max_size) {
    //p，暂存待处理的顶点
    arc_node *p;
    //存待处理顶点的辅助队列，注意存的是顶点下标
    int que[max_size], front = 0, rear = 0;
    int j;
    visit_v(v);
    visit[v] = 1;
    rear = (rear + 1) % max_size;
    que[rear] = v;
    while (front != rear) {
        /**
         * 出队一个顶点，访问其第一个邻接顶点p
         */
        front = (front + 1) % max_size;
        j = que[front];
        p = g->adj_list[j].first;

        /**
         * 如果顶点p没有访问过
         */
        while (p != NULL) {
            if (visit[p->adj_v] == 0) {
                visit_v(p->adj_v);
                //记录访问过的顶点
                visit[p->adj_v] = 1;
                rear = (rear + 1) % max_size;
                que[rear] = p->adj_v;
            }
            p = p->next;
        }
    }
}