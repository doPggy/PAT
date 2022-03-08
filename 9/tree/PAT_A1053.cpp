#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 110;

// 静态树
struct Node
{
    int weight;
    vector<int> child; 
}nodes[MAXN];

int n, m, S; //n node 个数, m 是非叶子结点, s 为给定的权重常数
int path[MAXN];// 保存路径

// index 当前遍历的节点编号 ,node_num, 当前 path 有几个节点了 ,sum 暂存路径长度点权和，用于判断 和 S
void DFS(int index, int node_num, int sum)
{
    if(sum > S) return;
    if(sum == S)
    {
        // 非叶子节点，不用继续了，肯定这条路不行
        if(nodes[index].child.size() != 0) return;
        // 到叶子节点了而且 sum == S，要输出
        for(int i = 0; i < node_num; i++)
        { 
            // 输出weight
            printf("%d", nodes[path[i]].weight);
            if(i < node_num - 1)//!
                printf(" ");
            else
                printf("\n");
        }
        return;
    }

    // vector<int> child = nodes[index].child;
    //DFS 核心
    for(int i = 0; i < nodes[index].child.size(); i++)
    {
        int child = nodes[index].child[i];//子节点编号
        path[node_num] = child; //! 保存路径
        //! DFS(child, node_num + 1, sum + nodes[index].weight); // 递归进下一层 不是 nodes[index] !!!!!!!!!
        // 递归进下一层 不是 nodes[index] !!!!!!!!! 从初始调用 DFS 来看，已经加了本节点的 weight 了
        DFS(child, node_num + 1, sum + nodes[child].weight); 

    }
    return;

}

// 排序的内容是 子节点编号
bool cmp(int a, int b)
{
    return nodes[a].weight > nodes[b].weight;
}

int main()
{
    scanf("%d%d%d", &n, &m, &S);
    // 输入 weight , 编号从 0 开始
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nodes[i].weight);
    }

    int id, k, child;//id 是节点编号，k 是id 的子节点个数
    // 输入非叶子节点
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            nodes[id].child.push_back(child);
        }
        //! 后头遍历子节点一定是从最大的 weight 开始
        sort(nodes[id].child.begin(), nodes[id].child.end(), cmp);
    }
    path[0] = 0; // path 用于保存遍历路径
    DFS(0, 1, nodes[0].weight);
}