#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV    = 510;
const int INF     = 0x3fffffff;
int G[MAXV][MAXV] = {0};
int d[MAXV]       = {0};// 某点到起始点最短距离
int num[MAXV]     = {0};// 起始点到某点的最短路径个数
int w[MAXV]       = {0}; // 起始点到某点的最大点权
int weight[MAXV]  = {0}; // 点权集合
bool vis[MAXV]    = { false };
int n, m, st, ed; // 点数，边数，起始点，终点


void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    // fill(w, w + MAXV, INF);
    d[start]    = 0;
    num[start]  = 1; // 起始起码一条
    w[start]    = weight[start];   
    for(int i = 0; i < n; i++)//循环 n 次
    {
        int min = INF;
        int chose = -1;
        for(int j = 0; j < n; j++)
        {
            // 找最小的 d 对应的节点
            if(!vis[j] && d[j] < min)
            {
                min = d[j];
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
                    d[v]    = d[chose] + G[chose][v];
                    num[v]  = num[chose]; // 继承了数量
                    w[v]    = w[chose] + weight[v]; // 点权和
                }
                else if(d[chose] + G[chose][v] == d[v])
                {
                    // 如果比目前到 v 的最大的点权和还要大
                    if(w[chose] + weight[v] > w[v])
                        w[v] = w[chose] + weight[v];
                    num[v] += num[chose];
                }
            }
        }
    }

}

int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    // 点权
    for(int i = 0; i < n; i++)
    {
        scanf("%d", weight + i);
    }
    int u, v;
    // 边权建图 注意是无向图
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }

    dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
}