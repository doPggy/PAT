//https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<queue>

using namespace std;

const int maxn = 110;
//! 统计每层的叶子节点
vector<int> childs[maxn];
int h[maxn] = {0,1};// 记录每个节点的层数, 从 1 开始
int leaf_num[maxn] = {0,0};// 统计每层叶子节点数量
int m, n;
int max_depth = 1;


void BFS(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int cur_id = q.front();
        q.pop();
        vector<int> cur_node = childs[cur_id];
        // 更新最大深度,在弹出一个节点的时候, 此节点对应的深度在上一层已经被计算
        //!所以 max_depth 放这里
        max_depth = max(max_depth, h[cur_id]);
        //! 叶子节点
        if(cur_node.size() == 0) 
        {
            leaf_num[h[cur_id]]++;
            continue;
        }
        else
        {
            // 把所有子节点的层数计算好，同时子节点入队
            for(int i = 0; i < cur_node.size(); i++)
            {
                h[cur_node[i]] = h[cur_id] + 1;
                q.push(cur_node[i]);
            }
        }
    }
    
}


void DFS(int root, int depth)
{
    max_depth = max(max_depth, depth);
    if(childs[root].size() == 0)
    {

        leaf_num[depth]++;
        return;
    }

    for(int i = 0; i < childs[root].size(); i++)
    {
        DFS(childs[root][i], depth + 1);
    }
}


int main()
{
    scanf("%d%d", &n, &m);
    int num;
    int child_id;
    int parent_id;
    for(int i = 0; i < m; i++)
    {
        //! 题目 ID K ID[1] ....
        scanf("%d%d", &parent_id, &num);
        for(int j = 0; j < num; j++)
        {
            scanf("%d", &child_id);
            childs[parent_id].push_back(child_id);
        }
    }

    BFS(1);
    printf("%d", leaf_num[1]);
    //! 每层输出，需要知道最大层
    for(int i = 2; i <= max_depth; i++)
    {
        printf(" %d", leaf_num[i]);
    }
    printf("\n");
}