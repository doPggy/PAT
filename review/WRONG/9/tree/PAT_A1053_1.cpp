#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 110;

// 树
struct Node
{
    int weight;
    vector<int> child;
}nodes[maxn];


int n, m, s;
int path[maxn]; // 路径记录

bool cmp(int a, int b)
{
    return nodes[a].weight > nodes[b].weight;
}


// 找路径长度 = s 的路径 num_node, sum 已经算过了 index 节点的 weight 务必注意
void DFS(int index, int num_node, int sum)
{
    if(sum > s) return;
    else if(sum == s)
    {
        if(nodes[index].child.size() != 0) return; // 一定会超过
        for(int i = 0; i < num_node; i++)
            printf("%d%s", nodes[path[i]].weight, (i != num_node -1) ? " " : "\n");
        return;
    }
    // sum < s 还要接着找路径
    else
    {
        for(int i = 0; i < nodes[index].child.size(); i++)
        {
            int child = nodes[index].child[i];
            path[num_node] = child; // 记录路径, 有了 num_node, 也不用清除原来的数据
            // 递归到子节点
            //! DFS(child, num_node + 1, sum + nodes[index].weight); // 这里不是 index ，而是 child，index 节点的 weight 已经算在 sum 里头
            DFS(child, num_node + 1, sum + nodes[child].weight);
        }
    }
}

int main()
{
    // 0 ~ n-1 id
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nodes[i].weight);
    }

    int id, k, child;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            nodes[id].child.push_back(child);
        }
        // 给子节点按照 weight 排序
        sort(nodes[id].child.begin(), nodes[id].child.end(), cmp);
    }

    path[0] = 0; // 一开始都是根节点
    DFS(0, 1, nodes[0].weight);
}