#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int MAXV = 510;
const int INF  = 0x3fffffff;
int G[MAXV][MAXV];
int weight[MAXV];// 点权
int w[MAXV]; // 记录起点到某点的最大点权和
int d[MAXV];
int num[MAXV] = {0}; // 起点到某点的最短路径个数
bool vis[MAXV] = {false};


int n, m, st, ed;


void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    d[start]   = 0;
    w[start]   = weight[start];
    num[start] = 1;

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
                    num[v]  = num[chose]; // 集成
                    w[v]    = w[chose] + weight[v];
                    // pre[v]  = chose;
                }
                else if(d[chose] + G[chose][v] == d[v])
                {
                    if(w[chose] + weight[v] > w[v])
                        w[v]    = w[chose] + weight[v];
                    num[v] += num[chose]; // 相同的，就要加了
                }
            }
        }
    }
}


int main()
{
    // 编号 0 ~ n-1
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", weight + i);
    }
    int u, v;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v]; // 无向图
    }
    dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
}