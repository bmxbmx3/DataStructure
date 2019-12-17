//
// Created by Administrator on 2019/12/16 0016.
//

#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

//video3----------------

/**
 * 树的顺序存储：结点结构体
 */
typedef struct t_node {
    int data;
    //p_idx指向父节点
    int p_idx;
} t_node;

//链表数组常用的两个结构体---------------------------------

/**
 * 树的链式存储：链表结构体
 */
typedef struct branch {
    //c_idx，链表数组每个元素所存链表中各孩子结点的下标
    int c_idx;
    //next，指向下一个链表结点的指针
    struct branch *next;
} branch;

/**
 * 树的链式存储：树的结点数组用链表数组表示的结构体
 */
typedef struct t_link_node {
    //data，存父结点的内容
    int data;
    //first，指向链表数组每个元素所存链表的第一个孩子结点（链表存有多个孩子结点，链表作为元素存在数组中）
    struct branch *first;
} t_link_node;

//----------------------------------------------------------------

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
 * 二叉树层次遍历（借助队列）
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
 * 树的先序遍历（后序遍历在此基础上修改）
 * @param p 根结点
 * @param tree 链表数组，数组每个元素存一个链表
 */
void pre_order(t_link_node *p, t_link_node tree[]) {
    //预先判断根结点不为空
    if (p != NULL) {
        //树的后序遍历visit(p);这里消除
        visit(p);
        branch *q;
        //q指向p的第一个孩子结点
        q = p->first;
        while (q != NULL) {
            //由遍历的结点下标在链表数组中找到对应索引的结点，然后往下遍历
            pre_order(&tree[q->c_idx], tree);
            //q顺着链表遍历它的兄弟结点
            q = q->next;
        }
        //树的后序遍历visit(p);放这里
    }
}

/**
 * 树的层次遍历
 * @param tn 根结点
 * @param tree 链表数组
 * @param max_size 树的结点个数，也即队列的容量
 */
void tree_level(t_link_node *tn, t_link_node tree[], int max_size) {
    /**
     * 变量定义：
     *
     * que[]，暂存层次遍历所需结点的辅助队列
     * front，que队队头
     * rear,que队队尾
     * p，用于暂存待处理的结点
     */
    int front, rear;
    t_link_node *que[max_size];
    front = rear = 0;
    t_link_node *p;

    if (tn != NULL) {
        /**
         * 入队根结点
         */
        rear = (rear + 1) % max_size;
        que[rear] = tn;

        /*
         * 开始层次遍历
         */
        while (front != rear) {
            /**
             * 出队一个结点p并访问，然后q暂存其第一个孩子结点
             */
            front = (front + 1) % max_size;
            p = que[front];
            visit(p);
            branch *q = p->first;

            /**
             * 依次遍历结点p的所有孩子结点，并按c_idx结点下标搜索对应链表数组中的结点，存入队列que[]中
             */
            while (q != NULL) {
                rear = (rear + 1) % max_size;
                que[rear] = &tree[q->c_idx];
                q = q->next;
            }
        }
    }
}

//video9-------------------------------------------------------------------------

typedef struct t_bt_node {
    /**
     * 变量定义：
     * data，存数据
     * l_tag（r_tag），为0，表示l_child（r_child）指向左（右）孩子；为1，表示l_child指向前驱（后继）
     * l_child，指向左孩子
     * r_child，指向右孩子
     */
    int data;
    int l_tag;
    int r_tag;
    struct t_bt_node *l_child;
    struct t_bt_node *r_child;
} t_bt_node;

/**
 * 中序线索二叉树
 * @param p 用来遍历结点的指针
 * @param pre 指向p指针所指结点的前驱结点
 */
void in_thread(t_bt_node *p, t_bt_node *pre) {
    /**
     * 函数体的结构类似r(bt_node *p)中序遍历结构，线索连接过程看作visit(p)
     */
    if (p != NULL) {
        //递归遍历左孩子
        in_thread(p->l_child, pre);

        /**
         * 线索连接过程：通过p、pre所指结点的相对位置，连接线索：p是pre的后继，pre是p的前驱
         */
        if (p->l_child == NULL) {
            p->l_child = pre;
            //l_tag置1，表示l_child为前驱
            p->l_tag = 1;
        }
        /**
         * 因为p赋值给pre的右孩子时，必须保证pre不为NULL才能成功，故条件判断pre!=NULL
         */
        if (pre != NULL && pre->r_child == NULL) {
            pre->r_child = p;
            pre->r_tag = 1;
        }
        //线索化后，将pre指向p所在结点，为下一步线索化做准备（这个线索化的过程类似走路的方式）
        pre = p;

        //递归遍历右孩子
        in_thread(p->r_child, pre);
    }
}

//video10-----------------------------------------------------
/**
 * 前序线索二叉树
 * @param p 用来遍历结点的指针
 * @param pre 指向p指针所指结点的前驱结点
 */
void pre_thread(t_bt_node *p, t_bt_node *pre) {
    /**
     * 函数体的结构类似r(bt_node *p)中序遍历结构，线索连接过程看作visit(p)
     */
    if (p != NULL) {
        /**
         * 线索连接过程：通过p、pre所指结点的相对位置，连接线索：p是pre的后继，pre是p的前驱
         */
        if (p->l_child == NULL) {
            p->l_child = pre;
            //l_tag置1，表示l_child为前驱
            p->l_tag = 1;
        }
        /**
         * 因为p赋值给pre的右孩子时，必须保证pre不为NULL才能成功，故条件判断pre!=NULL
         */
        if (pre != NULL && pre->r_child == NULL) {
            pre->r_child = p;
            pre->r_tag = 1;
        }
        //线索化后，将pre指向p所在结点，为下一步线索化做准备（这个线索化的过程类似走路的方式）
        pre = p;

        //递归遍历左孩子
        pre_thread(p->l_child, pre);
        //递归遍历右孩子
        pre_thread(p->r_child, pre);
    }
}

//video11------------------------------------------------------------
/**
 * 后序线索二叉树
 * @param p 用来遍历结点的指针
 * @param pre 指向p指针所指结点的前驱结点
 */
void post_thread(t_bt_node *p, t_bt_node *pre) {
    /**
     * 函数体的结构类似r(bt_node *p)中序遍历结构，线索连接过程看作visit(p)
     */
    if (p != NULL) {
        //递归遍历左孩子
        post_thread(p->l_child, pre);
        //递归遍历右孩子
        post_thread(p->r_child, pre);

        /**
         * 线索连接过程：通过p、pre所指结点的相对位置，连接线索：p是pre的后继，pre是p的前驱
         */
        if (p->l_child == NULL) {
            p->l_child = pre;
            //l_tag置1，表示l_child为前驱
            p->l_tag = 1;
        }
        /**
         * 因为p赋值给pre的右孩子时，必须保证pre不为NULL才能成功，故条件判断pre!=NULL
         */
        if (pre != NULL && pre->r_child == NULL) {
            pre->r_child = p;
            pre->r_tag = 1;
        }
        //线索化后，将pre指向p所在结点，为下一步线索化做准备（这个线索化的过程类似走路的方式）
        pre = p;
    }
}

//video13----------------------------------------------------------------------
/**
 * 由先序和中序序列建一棵树
 * @param pre 先序序列
 * @param in 中序序列
 * @param l1 先序序列子树控制范围左边界
 * @param r1 先序序列子树控制范围右边界
 * @param l2 中序序列子树控制范围左边界
 * @param r2 中序序列子树控制范围右边界
 * @return 根结点
 */
bt_node *create_bt(char pre[], char in[], int l1, int r1, int l2, int r2) {
    /**
     * 如果l1所指结点位置大于r1，那么说明前序序列所有结点全部扫完，则遍历停止
     */
    if (l1 > r1) {
        return NULL;
    }

    /**
     * 取前序序列的根结点s（最开始第一个根结点在最左边）
     */
    bt_node *s = (bt_node *) malloc(sizeof(bt_node));
    s->l_child = s->r_child = NULL;
    s->data = pre[l1];

    /**
     * 用i记录前序序列根结点在中序序列中的位置，为了便于划分后面的左右子树序列范围
     */
    int i;
    for (int i = l2; i <= r2; ++i) {
        if (in[i] == pre[l1]) {
            break;
        }
    }

    /**
     * 以i所指结点为中间点（根结点），划分左右子树（这里注意前序序列、中序序列相应的左右子树序列范围的划分），
     * 继续遍历子树根结点，再递归划分子树
     */
    //确定左子树序列范围，中序左子树序列范围l2-(i-1)，先序左子树序列范围根据中序确定
    s->l_child = create_bt(pre, in, l1 + 1, l1 + i - l2, l2, i - 1);
    //确定右子树序列范围，中序右子树序列范围（i+1）-r2，先序右子树序列范围根据中序确定
    s->r_child = create_bt(pre, in, l1 + i - l2 + i, r1, i + 1, r2);
    return s;
}

//video14----------------------------------------------------------------
/**
 * 由后序和中序序列建一棵树
 * @param post 后序序列
 * @param in 中序序列
 * @param l1 后序序列子树控制范围左边界
 * @param r1 后序序列子树控制范围右边界
 * @param l2 中序序列子树控制范围左边界
 * @param r2 中序序列子树控制范围右边界
 * @return 根结点
 */
bt_node *create_bt2(char post[], char in[], int l1, int r1, int l2, int r2) {
    /**
     * 如果l1所指结点位置大于r1，那么说明后序序列所有结点全部扫完，则遍历停止
     */
    if (l1 > r1) {
        return NULL;
    }

    /**
     * 取后序序列的根结点s（最开始第一个根结点在最右边）
     */
    bt_node *s = (bt_node *) malloc(sizeof(bt_node));
    s->l_child = s->r_child = NULL;
    s->data = post[r1];

    /**
     * 用i记录h后序序列根结点在中序序列中的位置，为了便于划分后面的左右子树序列范围
     */
    int i;
    for (int i = l2; i <= r2; ++i) {
        if (in[i] == post[r1]) {
            break;
        }
    }

    /**
     * 以i所指结点为中间点（根结点），划分左右子树（这里注意后序序列、中序序列相应的左右子树序列范围的划分），
     * 继续遍历子树根结点，再递归划分子树
     */
    //确定左子树序列范围，中序左子树序列范围l2-(i-1)，后序左子树序列范围根据中序确定
    s->l_child = create_bt2(post, in, l1, l1 + i - l2 - 1, l2, i - 1);
    //确定右子树序列范围，中序右子树序列范围（i+1）-r2，后序右子树序列范围根据中序确定
    s->r_child = create_bt2(post, in, l1 + i - l2, r1 - 1, i + 1, r2);
    return s;
}

/**
 * 查找元素key在数组arr[]（在遍历序列中的一段范围的数组）的位置
 * @param arr 待查找数组
 * @param key 待查找元素
 * @param l arr[]在遍历序列的左边界
 * @param r arr[]在遍历序列的右边界
 * @return 查找成功的位置idx或查找失败的标志-1
 */
int search(char arr[], char key, int l, int r) {
    //idx，获取元素key在arr[]中的位置
    int idx;
    //顺序遍历直到找到key在arr[]的位置
    for (int idx = l; idx < r; ++idx) {
        if (arr[idx] == key) {
            return idx;
        }
    }
    return -1;
}

/**
 * 从层次序列level[]分离出子层次序列sub_level[]（对层次序列中的左右子树序列重新聚集成sub_level[]）
 * @param sub_level 子层次序列
 * @param level 层次序列
 * @param in 中序序列
 * @param n 层次序列level[]的长度
 * @param l in[]取元素范围的左边界
 * @param r in[]取元素范围的右边界
 */
void get_sub_level(char sub_level[], char level[], char in[], int n, int l, int r) {
    //sub_level[]记录元素的索引
    int k = 0;

    /**
     * 从左向右遍历层次序列level[]，找出其每个元素对应中序序列in[]的l-r范围中的元素是否存在，
     * 如果存在将对应的到的元素记录在sub_level[]中
     */
    for (int i = 0; i < n; ++i) {
        if (search(in, level[i], l, r) != -1) {
            //level[]找到对应in[]的l-r范围的元素存在，将该元素存入sub_level[]
            sub_level[k] = level[i];
            k++;
        }
    }
}

/**
 * 由层次和中序序列建一棵树
 * @param level 层次序列
 * @param in 中序序列
 * @param n level[]长度
 * @param l 层次序列在in[]中序序列查询的左边界
 * @param r 层次序列在in[]中序序列查询的右边界
 * @return 根结点
 */
bt_node *create_bt3(char level[], char in[], int n, int l, int r) {
    /**
     * 如果l1所指结点位置大于r1，那么说明中序序列所有结点全部扫完，则遍历停止
     */
    if (l > r) {
        return NULL;
    }

    /**
     * 取层次序列的根结点s（最开始第一个根结点在最左边）
     */
    bt_node *s = (bt_node *) malloc(sizeof(bt_node));
    s->l_child = s->r_child = NULL;
    s->data = level[0];


    //i，找到层次序列根结点在中序序列的位置
    int i = search(in, level[0], l, r);
    int ln = i - l;
    //l_level[]存储层次序列中左子树序列的辅助空间
    char l_level[ln];
    int rn = r - i;
    //r_level[]存储层次序列中右子树序列的辅助空间
    char r_level[rn];

    //重新聚集（分离出）层次序列的左子树序列l_level[]
    get_sub_level(l_level, level, in, n, l, i - 1);
    //重新聚集（分离出）层次序列的右子树序列r_level[]
    get_sub_level(r_level, level, in, n, i + 1, r);

    /**
     * 以i所指结点为中间点（根结点），对中序序列划分左右子树序列，
     * 继续遍历层次序列子树根结点，再递归划分子树
     */
    //中序左子树序列范围1-(i-1)
    s->l_child = create_bt3(l_level, in, ln, l, i - 1);
    //中序右子树序列范围（i+1）-r
    s->r_child = create_bt3(r_level, in, rn, i + 1, r);
    return s;
}

//video15----------------------------------------------------------------
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
 * 计算由中缀表达式所建树的值（利用后序遍历框架）
 * @param root 二叉树根结点
 * @return
 */
float cal(bt_node *root) {
    //如果遇到了叶子结点（只有叶子结点存数字，其他结点存的符号），返回该值（由数字字符减去'0'字符转化得相应数字）
    if (root->l_child == NULL && root->r_child == NULL) {
        return (float) (root->data - '0');
    } else {
        //opand1，获取左子树计算值
        float opand1 = cal(root->l_child);
        //opand2，获取右子树计算值
        float opand2 = cal(root->r_child);

        //result，存计算结果
        float result;
        //由根结点运算符、左子树计算值、右子树计算值计算结果
        cal_sub(opand1, root->data, opand2, &result);
        return result;
    }
}