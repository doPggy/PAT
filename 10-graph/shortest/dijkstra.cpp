#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 1000;// 顶点个数上限
const int INF  = 0x3fffffff; //设为无穷大

int G[MAXV][MAXV] = {0};
int d[MAXV]       = {0};//! 从起点到某个点的最短距离
bool vis[MAXV] = { false }; //默认没有访问过
int n, m, s; // 点数，边数，起始点编号

int pre[MAXV] = {0}; //pre[v] 记录 v 的前驱节点编号，用于输出最短路径


void Dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    d[start]   = 0;
    for(int i = 0; i < n; i++) pre[i] = i; //! 初始化
    //! vis[start] = true;
    // 循环 n 次
    for(int i = 0; i < n; i++)
    {
        int min     = INF;
        int chose_v = -1;
        // 每次循环一遍找最小 d 的顶点
        for(int j = 0; j < MAXV; j++)
        {
            if(!vis[j] && d[j] < min)
            {
                min     = d[j];
                chose_v = j;
            }
        }
        if(chose_v == -1) return; //和起点不连通了
        vis[chose_v] = true; // 标记 chose 已经被访问,同时开放他的相关边
        // 优化 d[]
        for(int k = 0; k < n; k++)
        {
            // 未被访问过，且能使得最短距离优化的
            if(!vis[k] && G[chose_v][k] != 0 && d[chose_v] + G[chose_v][k] < d[k])
            {
                d[k] = d[chose_v] + G[chose_v][k];
                // chose_v 是作为中介点
                pre[k] = chose_v;
            }
        }
    }
}


// v 为节点(终点开始递归), s 为起始
//! void DFS(int v)
void DFS(int s, int v)
{
    // 找到起点
    //! if(pre[v] == s)
    if(v == s)
    {
        printf("%d\n", pre[v]);
        return;//!
    }
    DFS(s, pre[v]);
    //! printf("%d\n", pre[v]);
    printf("%d\n", v);
}


// 邻接矩阵版本
int main()
{
    int u, v, w;
    // 建图
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);// u, v u->v 的边权
        G[u][v] = w;
    }
    Dijkstra(s);
    DFS(s, n);
}