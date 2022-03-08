#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// 用 dfs 搞

const int MAXV = 510;
const int INF  = 0x3fffffff;
int G[MAXV][MAXV];
int cost[MAXV][MAXV];// 第二边权
int c[MAXV]; // 记录起点到某点的最小 cost
int d[MAXV];
bool vis[MAXV] = {false};
vector<int> pre[MAXV]; //
vector<int> temp, path;// 记录最短路径
int opt_v = INF;


int n, m, st, ed;
// 只更新 d 和 pre
void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    fill(c, c + MAXV, INF);
    d[start]   = 0;
    // c[start]   = 0;

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


void DFS(int v)
{
    // 到达起点，开始计算
    int temp_val = 0;
    if(st == v)
    {
        temp.push_back(v); // 把起点放进来，才能计算
        for(int i = 0; i < temp.size() - 1; i++)
        {
            int id = temp[i];
            int next = temp[i + 1];
            temp_val += cost[id][next];
        }
        if(temp_val < opt_v)
        {
            path  = temp;
            opt_v = temp_val;
        }
        temp.pop_back();
        return;
    }
    // 加入路径，用于计算
    temp.push_back(v);
    // 遍历所有的前驱
    for(int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    // 以 v 为中继的已经计算结束，可以弹出了
    temp.pop_back();
}


int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
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
    //! for(int it : path)
    for(int i = path.size() - 1; i >= 0; i--) //倒序输出才是从起点开始
        printf("%d ", path[i]);
    printf("%d %d\n", d[ed], opt_v);

}