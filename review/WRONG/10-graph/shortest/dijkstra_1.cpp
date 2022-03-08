#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 1010;
const int INF  = 0x3fffffff;


int G[MAXV][MAXV] = {0};
int d[MAXV]       = {0}; // 起点到节点 u 的最短距离
int pre[MAXV]     = {0}; // 某个节点在最短路径上的前驱
bool vis[MAXV]    = {false};// 是否访问过
int n, m, s; // n 顶点个数 , m 边个数, s 为起始节点



void dijkstra(int start)
{
    fill(d, d + MAXV, INF); // 一开始默认都不可达
    d[start] = 0;
    // 循环 n 次
    for(int i = 0; i < n; i++)
    {
        // 找最小 d[u]
        int min     = INF;
        int chose_v = -1; // 0 也是有编号的
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && d[j] < min)
            {
                min     = d[j];
                chose_v = j;
            }
        }
        if(chose_v == -1) return; //说明有不联通的子图
        vis[chose_v] = true; // 记录访问
        // chose_v 加入集合后，它相关的边点开放，更新 d[]
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && G[chose_v][j] && d[chose_v] + G[chose_v][j] < d[j])
            {
                d[j]    = d[chose_v] + G[chose_v][j];
                pre[j]  = chose_v;
            }
        }
    }
}

// v 为当前遍历, start 为起始点, 不断往前递归
void DFS(int start, int v)
{
    if(start == v)
    {
        printf("%d\n", v);
        return;
    }
    DFS(start, pre[v]);
    printf("%d\n", v);
}

int main()
{
    int u, v, w;// 节点u，节点 v, u -> v 边权
    for(int i = 0; i < MAXV; i++) pre[i] = i;
    // 建图
    scanf("%d%d%d", &n, &m, &s); // 
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
    }
    // 最短路径
    dijkstra(s);
    DFS(s, n - 1);
}