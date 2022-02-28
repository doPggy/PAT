#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAXV = 510;
const int INF  = 0x3fffffff;
int G[MAXV][MAXV] = {0};
int d[MAXV] = {0};
int cost[MAXV][MAXV] = {0};
bool vis[MAXV] = { false };
vector<int> pre[MAXV];
vector<int> temp_path, path;// 临时，最优路径
int temp_cost, opt_cost = INF;//! opt_cost 应该是初始化为 INF 不是 0

int n, m, st, ed;

void dijkstra(int start)
{
    fill(d, d + MAXV, INF);
    d[start] = 0;
    //循环 n 次
    for(int i = 0; i < n; i++)
    {
        // 找最小 d[]
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
        vis[chose] = true; // 记录为访问过
        for(int v = 0; v < n; v++) // 开放 chose 的边，优化 d[]
        {
            // 只要看距离这一尺标，是否访问过且有边
            if(!vis[v] && G[chose][v])
            {
                if(d[chose] + G[chose][v] < d[v])
                {
                    d[v] = d[chose] + G[chose][v];
                    pre[v].clear();// 全新，要clear
                    pre[v].push_back(chose);// 前驱之一
                }
                else if(d[chose] + G[chose][v] == d[v])
                {
                    pre[v].push_back(chose);// 因为距离相同，又一个前驱要加上
                }
            }
        }
    }
}

// 关键之一, 其他指标的计算
void DFS(int start, int v)
{
    // 当递归到叶子节点，计算第二尺标
    if(start == v)
    {
        temp_path.push_back(v); //? 把起始点加进去，方便计算路径边权
        //! 算路径上的边权, 
        temp_cost = 0;
        for(int i = temp_path.size() - 1; i > 0; i--)
        {
            int id = temp_path[i];
            int next = temp_path[i - 1]; //! id -> next 的边权计算
            temp_cost += cost[id][next];
        }
        if(temp_cost < opt_cost)
        {
            path     = temp_path;
            opt_cost = temp_cost;
        }
        temp_path.pop_back();//?
        return;
    }
    temp_path.push_back(v);//?
    // 找 v 的前驱们
    for(int i = 0; i < pre[v].size(); i++)
    {
        DFS(start, pre[v][i]);
    }
    temp_path.pop_back();//?
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u]    = G[u][v];
        cost[v][u] = cost[u][v];
    }
    dijkstra(st);
    DFS(st, ed); //! 从最后一个开始, 获取最优
    // 输出路径
    for(int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[ed], opt_cost); //! 最短距离和最短路径上的最小话费
}