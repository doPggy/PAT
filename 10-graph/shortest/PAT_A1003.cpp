#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int MAXV = 510;
const int INF  = 0x3fffffff;
int G[MAXV][MAXV] = {0};
int d[MAXV]       = {0};
int num[MAXV]     = {0}; // 统计起点到某点 v 最短路径的个数
int weight[MAXV]  = {0}; // 每个节点的点权
int w[MAXV]       = {0};//! 最大点权之和
bool vis[MAXV]    = {false};
int n, m, st, ed;


void dijkstra(int start)
{
    //初始化
    fill(d, d + MAXV, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
    d[start]   = 0;
    num[start] = 1; //! 起始点刚开始时，就一个最短路径，就是单独起始点
    w[start]   = weight[start]; //! 最大点权之和一开始也是起始点的点权

    for(int i = 0; i < n; i++)
    {
        int min = INF;
        int chose_v = -1;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && d[j] < min)
            {
                min     = d[j];
                chose_v = j;
            }
        }
        if(chose_v == -1) return;
        vis[chose_v] = true;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && G[chose_v][j] != 0)
            {
                if(d[chose_v] + G[chose_v][j] < d[j])
                {
                    d[j]    = d[chose_v] + G[chose_v][j];// 距离更新了
                    num[j]  = num[chose_v]; // 直接继承最短路径个数
                    //! w[j]    += weight[chose_v];
                    w[j]    = w[chose_v] + weight[j];//! 中介点的点权加上原来的点权，因为是更新了
                }
                else if(d[chose_v] + G[chose_v][j] == d[j])
                {
                    if(w[j] < w[chose_v] + weight[j]) //! 要选择最大的点权和,
                        w[j] = w[chose_v] + weight[j];//! 中介点的点权加上原来的点权，因为是更新了
                    num[j] += num[chose_v]; // 要加上
                }
            }
        }
    }

}

int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", weight + i);
    }
    int u, v;
    // fill(G[0], G[0] + MAXV * MAXV, INF);//! 一定要用 inf
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        //无向边
        G[v][u] = G[u][v];
    }
    dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
}