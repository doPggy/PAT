#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;


const int MAXV = 510;
// 用邻接表
vector<int> adj[MAXV];
int in_degree[MAXV];
int n, m; // 顶点数，边数 有向边


bool topo()
{
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        //入度为0
        if(in_degree[i] == 0)
            q.push(i);
    }
    int num = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        num++;
        printf("%d ", v);
        for(int it : adj[v]) // v 的所有邻接点
        {
            // 入度减少
            in_degree[it]--;
            if(in_degree[it] == 0)
                q.push(it);
        }
    }

    if(num == n) return true;
    else return false; //有环，失败拓扑排序

}

int main()
{
    // 建图 默认 00 ~ n-1 编号
    scanf("%d%d", &n, &m);
    int u, v
    // u->v 有边
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        in_degree[v]++;
    }
}