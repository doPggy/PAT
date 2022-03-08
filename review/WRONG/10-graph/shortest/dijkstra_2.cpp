#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 1010;
const int INF  = 0x3fffffff;
int G[MAXV][MAXV];
int d[MAXV];
int pre[MAXV];
bool vis[MAXV] = { false };
int n, m, s; // 点个数，边个数


void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    d[start] = 0;
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
        for(int v = 0; v < n; i++)
        {
            if(!vis[v] && G[chose][v])
            {
                if(d[chose] + G[chose][v] < d[v])
                {
                    d[v]    = d[chose] + G[chose][v];
                    pre[v]  = chose;
                }
                else if(d[chose] + G[chose][v] == d[v])
                {
                    //....
                }
            }
        }
    }
}


// start 已经在全局
void DFS(int v)
{
    // 到了起点
    if(s == v)
    {
        printf("%d ", v)
        return;
    }

    DFS(pre[v]);
    printf("%d ", v);
}


int main()
{
    // 默认编号 0 ~ n -1
    scanf("%d%d%d" &n, &m, &s);
    for(int i = 0; i < n; i++) pre[i] = i;
    // 建图
    int u, v, w;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
    }
    dijkstra(s);
    DFS(n - 1); //!
}