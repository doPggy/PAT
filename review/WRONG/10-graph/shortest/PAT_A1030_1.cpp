#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXV = 510;
const int INF  = 0x3fffffff;
int G[MAXV][MAXV] = {0};
int d[MAXV] = {0};
int cost[MAXV][MAXV] = {0}; // 记录开销边权
int c[MAXV] = {0}; //起点到某个点 v 最小开销
int pre[MAXV] = {0}; //用于存路径
bool vis[MAXV] = {false};


int n, m, s, ed;

void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    fill(c, c + MAXV, INF); //!
    for(int i = 0; i < n; i++) pre[i] = i; // pre 初始化
    d[start] = 0;
    c[start] = 0; // 自身花费为 0
    // n 次循环
    for(int i = 0; i < n; i++)
    {
        int min   = INF;
        int chose = -1;
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
            // 没访问过的点
            if(!vis[v] && G[chose][v])
            {
                // 更优的要更新
                if(G[chose][v] + d[chose] < d[v])
                {
                    d[v]   = G[chose][v] + d[chose];
                    c[v]   = c[chose] + cost[chose][v];
                    pre[v] = chose; // v 前驱是 u
                }
                else if(G[chose][v] + d[chose] == d[v])
                {
                    // d[v]   = G[chose][v] + d[chose];
                    if(c[chose] + cost[chose][v] < c[v])
                    {
                        c[v]   = c[chose] + cost[chose][v];
                        pre[v] = chose; // v 前驱是 u
                    }
                }
            }
        }
    }
}

void DFS(int start, int v)
{
    if(start == v)
    {
        printf("%d ", v);
        return;
    }
    DFS(start, pre[v]);
    printf("%d ", v);
    return;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &ed);
    int u, v;
    // 注意是否为无向图
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u]    = G[u][v];
        cost[v][u] = cost[u][v];
    }
    dijkstra(s);
    DFS(s, ed);
    printf("%d %d\n", d[ed], c[ed]);
    return 0;
}