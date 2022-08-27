
/*
基于深度优先遍历算法的应用。
假设图G采用邻接矩阵存储：
（1）判断图G中从顶点u到v是否存在简单路径；
（2）输出图G中从顶点u到v的一条简单路径（假设至少存在一条路径）；
（3）输出从图G中从顶点u到v的所有简单路径（假设至少存在一条路径）；
（4）输出从图G中从顶点u到v的长度为s的所有简单路径；
（5）求图中通过某顶点k的所有简单回路（若存在）。
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#define MAXV 50
using namespace std;
int visited[MAXV];
//邻接表类型
typedef struct ANode
{
    int adjvex;             //该边的编号
    struct ANode* nextarc;  //指向下一条边的信息
} ArcNode;                  //边节点的类型

typedef struct Vnode
{
    ArcNode* firstarc;      //指向第一条边
} VNode;                    //邻接表头节点类型

typedef VNode AdjList[MAXV];
typedef struct
{
    AdjList adjlist;       //邻接表
    int n, e;               //图中顶点数n和边数e
} ALGraph;                 //完整的图邻接表类型

void ArrayToList(int* Arr, int n, ALGraph*& G)  //用普通数组构造图的邻接表
{
    int i, j, count = 0;  //count用于统计边数，即矩阵中非0元素个数
    ArcNode* p;
    G = (ALGraph*)malloc(sizeof(ALGraph));
    G->n = n;
    for (i = 0; i < n; i++)                 //给邻接表中所有头节点的指针域置初值
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < n; i++)                 //检查邻接矩阵中每个元素
        for (j = n - 1; j >= 0; j--)
            if (Arr[i * n + j] != 0)      //存在一条边，将Arr看作n×n的二维数组，Arr[i*n+j]即是Arr[i][j]
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));   //创建一个节点*p
                p->adjvex = j;
                p->nextarc = G->adjlist[i].firstarc;      //采用头插法插入*p
                G->adjlist[i].firstarc = p;
            }

    G->e = count;
}

void DispAdj(ALGraph* G)   //输出邻接表G
{
    int i;
    ArcNode* p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            printf("-->%d ", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}

/*
判断图G中从顶点u到v是否存在简单路径:
在深度优先遍历的基础上增加has和v两个形参，其中has表示顶点u到v是否有路径，其初值为false，
当顶点u遍历到顶点v后，置has为true并返回。
*/
void ExistPath(ALGraph* G, int u, int v, bool& has)
{
    int w;
    ArcNode* p;
    visited[u] = 1;              //置初始顶点为已访问标记
    if (u == v)                   //找到一条路径
    {
        has = true;
        return;
    }
    p = G->adjlist[u].firstarc;  //p指向顶点u的第一个邻接点
    while (p != NULL)
    {
        w = p->adjvex;           //w为u的相邻顶点
        if (visited[w] == 0)
            ExistPath(G, w, v, has);
        p = p->nextarc;          //p指向顶点u的下一个相邻点
    }
}

/*
输出图G中从顶点u到v的一条简单路径:
在深度优先遍历的基础上增加v、path和d三个形参，其中path存放顶点u到v的路径，d表示path中的路径长度，初值为-1
当顶点u遍历到顶点v后，输出path并返回。
*/
void FindaPath(ALGraph* G, int u, int v, int path[], int d)
{
    int w, i;
    ArcNode* p;
    visited[u] = 1;              //置初始顶点为已访问标记
    d++;
    path[d] = u;                 //路径长度d增1，顶点u加入到路径中
    if (u == v)                   //找到一条路径，输出并返回
    {
        cout << "输出从u到v的一条简单路径：";
        for (i = 0; i <= d; i++)
            cout << path[i];
        cout << endl;
        return;
    }
    p = G->adjlist[u].firstarc;  //p指向顶点u的第一个邻接点
    while (p != NULL)
    {
        w = p->adjvex;           //w为u的相邻顶点
        if (visited[w] == 0)
            FindaPath(G, w, v, path, d);
        p = p->nextarc;          //p指向顶点u的下一个相邻点
    }
}

/*
输出从图G中从顶点u到v的所有简单路径:
在深度优先遍历的基础上增加v、path和d三个形参，其中path存放顶点u到v的路径，d表示path中的路径长度，初值为-1
当从顶点u出发遍历时，先将visited[u]置为1，并将u加入到路径path中，若满足顶点u就是终点的v的条件时，
则找到了一个从顶点u到v的一条路径，则输出path并继续；再从顶点u找一个未访问过的相邻顶点w，若存在这样的顶点w，
则从w出发继续进行，若不存在这样的顶点w，则说明从顶点u再往下找找不到路径，所以置visited[u]为0，以便顶点u作为
其他路径上的顶点。
*/
void FindPath(ALGraph* G, int u, int v, int path[], int d)
{
    int w, i;
    ArcNode* p;
    d++;
    path[d] = u;                 //路径长度d增1，顶点u加入到路径中
    visited[u] = 1;              //置初始顶点为已访问标记
    if (u == v && d >= 1)                   //找到一条路径则输出
    {
        for (i = 0; i <= d; i++)
            cout << path[i];
        cout << endl;
    }
    p = G->adjlist[u].firstarc;  //p指向顶点u的第一个邻接点
    while (p != NULL)
    {
        w = p->adjvex;           //w为u的相邻顶点
        if (visited[w] == 0)
            FindPath(G, w, v, path, d);
        p = p->nextarc;          //p指向顶点u的下一个相邻点
    }
    visited[u] = 0;              //恢复环境，使该顶点可重新使用
}

/*
输出从图G中从顶点u到v的长度为s的所有简单路径；
只需将路径输出条件改为u==v且d==s。
*/
void PathAll(ALGraph* G, int u, int v, int s, int path[], int d)
{
    int w, i;
    ArcNode* p;
    visited[u] = 1;
    d++;
    path[d] = u;                 //路径长度d增1，顶点u加入到路径中
    if (u == v && d == s)                   //找到一条路径则输出
    {
        for (i = 0; i <= d; i++)
            cout << path[i];
        cout << endl;
    }
    p = G->adjlist[u].firstarc;  //p指向顶点u的第一个邻接点
    while (p != NULL)
    {
        w = p->adjvex;           //w为u的相邻顶点
        if (visited[w] == 0)
            PathAll(G, w, v, s, path, d);
        p = p->nextarc;          //p指向顶点u的下一个相邻点
    }
    visited[u] = 0;              //恢复环境，使该顶点可重新使用
}

/*
求图中通过某顶点k的所有简单回路（若存在）：
利用深度优先搜索方法，从顶点u开始搜索与之相邻的顶点w，若w等于顶点v（其初值为u），且路径长度大于0，表示找到了一条回路，
输出path数组，然后继续搜索顶点u的未访问的相邻点查找其它通路。
*/
void DFSPath(ALGraph* G, int u, int v, int path[], int d)
{
    int w, i;
    ArcNode* p;
    visited[u] = 1;
    d++;
    path[d] = u;                 //路径长度d增1，顶点u加入到路径中
    p = G->adjlist[u].firstarc;  //p指向顶点u的第一个邻接点
    while (p != NULL)
    {
        w = p->adjvex;             //w为顶点u的相邻点
        if (w == v && d > 0)                   //找到一条路径则输出
        {
            for (i = 0; i <= d; i++)
                cout << path[i];
            cout << v << endl;
        }
        if (visited[w] == 0)        //若w未访问，则递归访问之
            DFSPath(G, w, v, path, d);
        p = p->nextarc;          //p指向顶点u的下一个相邻点
    }
    visited[u] = 0;              //恢复环境，使该顶点可重新使用
}

int main()
{
    int i, path[MAXV];
    bool f;
    ALGraph* G, * G1, * G2;
    int A[5][5] =
    {
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1},
        {0,0,0,0,1},
        {1,0,0,0,0}
    };
    int B[5][5] =
    {
        {0,1,0,1,1},
        {1,0,1,1,0},
        {0,1,0,1,1},
        {1,1,1,0,1},
        {1,0,1,1,0}
    };
    int C[5][5] =
    {
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1},
        {0,0,0,0,1},
        {1,0,0,0,0}
    };
    ArrayToList(A[0], 5, G);
    ArrayToList(B[0], 5, G1);
    ArrayToList(C[0], 5, G2);
    for (i = 0; i < G->n; i++)
        visited[i] = 0; //访问标志数组初始化
    printf("有向图G的邻接表:\n");
    DispAdj(G);
    cout << endl;
    for (i = 0; i < G->n; i++)
        visited[i] = 0; //访问标志数组初始化
    ExistPath(G, 1, 4, f);
    cout << "是否存在一条u到v的路径？";
    if (f)
        cout << "存在" << endl;
    else
        cout << "不存在" << endl;
    for (i = 0; i < G->n; i++)
        visited[i] = 0; //访问标志数组初始化
    cout << endl;
    FindaPath(G, 1, 4, path, -1);
    cout << endl;
    for (i = 0; i < G1->n; i++)
        visited[i] = 0; //访问标志数组初始化
    printf("无向图G1的邻接表:\n");
    DispAdj(G1);
    cout << endl;
    for (i = 0; i < G1->n; i++)
        visited[i] = 0; //访问标志数组初始化
    printf("输出G1从1到4的所有简单路径:\n");
    FindPath(G1, 1, 4, path, -1);
    cout << endl;
    for (i = 0; i < G1->n; i++)
        visited[i] = 0; //访问标志数组初始化
    cout << "输出从图G中从顶点u到v的长度为s的所有简单路径：\n";
    PathAll(G1, 1, 4, 3, path, -1);
    cout << endl;
    for (i = 0; i < G1->n; i++)
        visited[i] = 0; //访问标志数组初始化
    printf("有向图G2的邻接表:\n");
    DispAdj(G2);
    cout << endl;
    for (i = 0; i < G1->n; i++)
        visited[i] = 0; //访问标志数组初始化
    cout << "经过顶点k的所有回路：\n";
    DFSPath(G2, 0, 0, path, -1);
    cout << endl;
    return 0;
}