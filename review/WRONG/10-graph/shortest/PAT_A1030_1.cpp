#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXV          = 510;
const int INF           = 0x3fffffff;
int G[MAXV][MAXV]       = {0};
int d[MAXV]             = {0};
int pre[MAXV]           = {0};
bool vis[MAXV]          = { false };
int cost[MAXV][MAXV]    = {0}; // 第二尺标 ，花费
int c[MAXV]             = {0}; // 起点到某点的花费
int n, m, st, ed; // 点数，边数，起始点，终点

void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    fill(c, c + MAXV, INF);
    d[start]   = 0;
    pre[start] = start;
    c[start]   = 0;
    for(int i = 0; i < n; i++)
    {
        int min   = INF;
        int chose = -1;
        // 找最小的 d[]
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && d[j] < min)
            {
                min   = d[j];
                chose = j;
            }
        }
        if(chose == -1) return;
        vis[chose] = true;
        for(int v = 0; v < n; v++)
        {
            if(!vis[v] && G[chose][v])
            {
                if(d[chose] + G[chose][v] < d[v])
                {
                    d[v]   = d[chose] + G[chose][v];
                    c[v]   = c[chose] + cost[chose][v];
                    pre[v] = chose;
                }
                else if(d[chose] + G[chose][v] == d[v])
                {
                    // 如果有更小的花费
                    if(c[v] > c[chose] + cost[chose][v])
                    {
                        c[v]   = c[chose] + cost[chose][v];
                        pre[v] = chose;
                    }
                }
            }

        }
    }
}

// 最开始 v 是终点 
void DFS(int v)
{
    if(st == v)
    {
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);//前驱
    printf("%d ", v);
}


int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) pre[i] = i; // 初始化
    int u, v;
    // 边权和花费
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u]    = G[u][v];
        cost[v][u] = cost[u][v];
    }

    dijkstra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);


}