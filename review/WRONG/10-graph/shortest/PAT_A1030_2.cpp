#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXV = 510;
const int INF  = 0x3fffffff;
int G[MAXV][MAXV];
int cost[MAXV][MAXV];// 第二边权
int c[MAXV]; // 记录起点到某点的最小 cost
int d[MAXV];
bool vis[MAXV] = {false};
int pre[MAXV];


int n, m, st, ed;
void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    fill(c, c + MAXV, INF);
    d[start]   = 0;
    c[start]   = 0;

    // n 次
    for(int i = 0; i < n; i++)
    {
        int min   = INF;
        int chose = -1;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && d[j] < min) // 找最小的 d[]
            {
                min   = d[j];
                chose = j;
            }
        }
        if(chose == -1) return;// 存在不连通子图
        vis[chose] = true;
        // 开放边，更新 d[]
        for(int v = 0; v < n; v++)
        {
            if(!vis[v] && G[chose][v])
            {
                if(d[chose] + G[chose][v] < d[v])
                {
                    d[v]    = d[chose] + G[chose][v];
                    c[v]    = c[chose] + cost[chose][v]; // 花费
                    pre[v]  = chose;
                }
                else if(d[chose] + G[chose][v] == d[v])
                {
                    // 更小花费，更新 c
                    if(c[chose] + cost[chose][v] < c[v])
                    {
                        c[v]    = c[chose] + cost[chose][v]; // 花费
                        pre[v]  = chose;
                    }
                }
            }
        }
    }
}

void DFS(int v)
{
    if(st == v)
    {
        printf("%d ", v);
        return;
    }
    DFS(pre[v]); // 向前回溯
    printf("%d ", v);
    return;
}


int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) pre[i] = i;
    int u, v;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u]    = G[u][v]; // 无向图
        cost[v][u] = cost [u][v]; // 无向图
    }

    dijkstra(st);
    //! DFS(n - 1);
    DFS(ed); //! 题目要求的是 shortest path from the starting point to the destination, 不是从头到尾
    printf("%d %d\n", d[ed], c[ed]);
}