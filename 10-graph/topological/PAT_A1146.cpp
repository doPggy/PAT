#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXV = 1010;
vector<int> adj[MAXV];// 邻接表
int in_degree[MAXV] = {0};
// queue<int> q; // 存放无入度节点


int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i = 0; i < m; i++) //! 不是 i<n!!!
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        in_degree[v]++;
    }

    int k;
    scanf("%d", &k);

    // 输入 k 个序列 判断是否为拓扑
    // 如果遍历的点入度不为 0, 则不是拓扑
    int a    = 0;
    int flag = 0;
    for(int i = 0; i < k; i++)
    {
        int judge = 1;
        vector<int> t_in(in_degree, in_degree + n + 1); // 复制一份
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a);
            // 不直接 break 是因为一个一个输入保持完整
            if(t_in[a] != 0) judge = 0;
            // 如果能去掉，相关的入度都要减去
            for(int it : adj[a]) t_in[it]--;
        }
        if(judge) continue; // 说明是拓扑，就不用输出
        printf("%s%d", flag ? " " : "", i); // 不是拓扑输出编号
        flag = 1;
    }
    printf("\n");
}