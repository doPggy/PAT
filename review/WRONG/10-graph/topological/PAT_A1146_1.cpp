#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAXV = 1010;
vector<int> adj[MAXV];// 领接表
int in_degree[MAXV] = {0}; // 入度统计

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    //建图
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v); // u -> v
        adj[u].push_back(v);
        in_degree[v]++;
    }

    // query
    int k;
    int a;
    bool flag = true;
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        vector<int> in(in_degree, in_degree + n + 1); //?
        bool is_topo = true;
        // 输入序列
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a);
            if(in[a] != 0) is_topo = false;
            for(int it : adj[a]) in[it]--; // 入度减少
        }
        if(is_topo) continue;
        printf("%s%d\n", flag ? "" : " ", i); // 输出不是拓扑排序的序列编号哦
        flag = false;
    }
    printf("\n");
}