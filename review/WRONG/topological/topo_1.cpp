#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXV = 1000;
vector<int> adj[MAXV];
int in_degree[MAXV] = {0};
int n, m;

bool topo_sort()
{
    queue<int> q;
    int num = 0;
    // 入度为 0 全部放入队列
    for(int i = 0; i < n; i++)
    {
        if(in_degree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        printf("%d ", u);
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            in_degree[v]--;
            if(in_degree[v] == 0)
                q.push(v);
        }
        num++;
    }
    if(num == n) return true;
    else return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    //建图
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v); // u -> v
        adj[u].push_back(v);
        in_degree[v]++;
    }
    topo_sort();
}