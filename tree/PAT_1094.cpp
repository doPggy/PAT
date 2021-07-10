// https://pintia.cn/problem-sets/994805342720868352/problems/994805372601090048
#include<cstdio>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

//! 本题主要是统计最多节点的层, 而且还是 DFS/BFS
const int maxn = 110;
int n, m;
vector<int> childs[maxn];

//!记录每一层的节点数量
int hash_table[maxn] = {0};

void DFS(int root, int depth)
{
    //! 这里不应该把叶子节点排除
    // if(childs[root].size() == 0)
    //     return;

    hash_table[depth]++;
    for(int i = 0; i < childs[root].size(); i++)
    {
        DFS(childs[root][i], depth + 1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int child_id = 0;
    int num      = 0;
    int id       = 0;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &num);
        for(int j = 0; j < num; j++)
        {
            scanf("%d", &child_id);
            childs[id].push_back(child_id);
        }
    }
    DFS(1, 1);
    int max_level = -1;
    int max_num   = -1;
    for(int i = 1; i < maxn; i++)
    {
        if(hash_table[i] > max_num)
        {
            max_num   = hash_table[i];
            max_level = i;
        }
    }
    printf("%d %d\n",  max_num, max_level);
}