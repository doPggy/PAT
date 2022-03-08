#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAXV = 1010;
// 用邻接表
vector<int> adj[MAXV];
int in_degree[MAXV];
int n, m; // 顶点数，边数 有向边 The vertices are numbered from 1 to N.





int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    // u->v 有边
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        in_degree[v]++;
    }

    int k = 0;
    int id = 0;
    bool is_first = true;
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        bool flag = true;
        //! vector<int> in(in_degree + 1, in_degree + n + 1);
        vector<int> in(in_degree, in_degree + n + 1);
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &id);
            if(in[id] != 0) flag = false;
            for(int it : adj[id]) in[it]--;
        }
        if(flag) continue;
        printf("%s%d", is_first ? "" : " ", i);
        is_first = false;
    }
}