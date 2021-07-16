//https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>

using namespace std;

const int maxn = 110;
//! 统计每层的叶子节点
vector<int> childs[maxn];
int leaf_num[maxn] = {0};
int m, n;
int max_depth = 1;


void BFS(int root)
{
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

    DFS(1, 1);
    printf("%d", leaf_num[1]);
    //! 每层输出，需要知道最大层
    for(int i = 2; i <= max_depth; i++)
    {
        printf(" %d", leaf_num[i]);
    }
    printf("\n");
}