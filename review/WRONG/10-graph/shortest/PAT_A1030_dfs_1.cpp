#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXV = 510;
const int INF  = 0x3fffffff;

int G[MAXV][MAXV]     = {0};
int d[MAXV]           = {0};
int cost[MAXV][MAXV]  = {0};
bool vis[MAXV] = { false };
vector<int> pre[MAXV];
int n, m, st, ed;

vector<int> temp_path, path;
int opt_v = INF;


// 只求最短路径和 pre
void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    d[start] = 0;
    // 循环 n 次，有 n 个点
    for(int i = 0; i < n; i++)
    {
        // 找最小的 d
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
        vis[chose] = true; //将 choose 加入最短路径集合
        // 开放出 chose 连接的边，更新 d
        for(int v = 0; v < n; v++)
        {
            if(!vis[v] && G[chose][v])
            {
                //更小的距离
                if(d[chose] + G[chose][v] < d[v])
                {
                    d[v]    = d[chose] + G[chose][v];
                    pre[v].clear();
                    pre[v].push_back(chose);
                }
                else if(d[chose] + G[chose][v] == d[v])
                {
                    pre[v].push_back(chose);
                }
            }
        }
    }
}

// 利用 DFS 求解第二尺标
void DFS(int v)
{
    int temp_value = 0;
    // 到递归边界，也就是到起点了
    if(st == v)
    {
        temp_path.push_back(v);
        for(int i = temp_path.size() - 1; i > 0 ; i--)
        {
            int id     = temp_path[i];
            int next   = temp_path[i - 1];
            temp_value += cost[id][next]; // 算花费
        }
        if(temp_value < opt_v)
        {
            path  = temp_path;
            opt_v = temp_value;
        }
        temp_path.pop_back();
        return;
    }
    temp_path.push_back(v);
    // 找前驱
    for(int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    temp_path.pop_back();
    return;
}



// 利用 dfs 做第二尺标衡量
int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;
    // 建图
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u]    = G[u][v];
        cost[v][u] = cost[u][v];
    }
    dijkstra(st);
    DFS(ed);
    for(int i = path.size() - 1; i >= 0 ; i--)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[ed], opt_v);
}