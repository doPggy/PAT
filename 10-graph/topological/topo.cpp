#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXV = 1010;
vector<int> adj[MAXV];// 邻接表
int in_degree[MAXV]; // 入度表
int n, m; 


// vector<int> topo;

bool topo_sort()
{
    int num = 0;
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        // 把入度为 0 的入队
        if(in_degree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        printf("%d ", v);
        // topo.push_back(v);
        num++;
        // for(int it : adj[v]) in_degree[it]--; // 把入度全部减了
        for(int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];// 邻接点
            in_degree[u]--;
            if(in_degree[u] == 0) q.push(i);// 把入度为 0 的加入
        }
    }
    // 是否有环
    if(num == n) return false;
    else return true;
}

int main()
{
    // 建图
    scanf("%d%d", &n, &m);
    int u, v;
    // 建有向图
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        in_degree[v]++;
    }
    topo_sort();
    // printf("%d\n", topo_sort());
    // for(int v : topo)
    //     printf("%d", v);
}