// https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<queue>

using namespace std;

const int maxn = 110;
int weight[maxn] = {0};
struct node
{
    int weight;
    vector<int> childs;
} Nodes[maxn];


int m, n, s;

void BFS(int root)
{

}


int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", weight + i);
    }
    int id, k, child_id;//k is number of children
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &id, &k);
        Nodes[id].weight = weight[id];
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &child_id);
            Nodes[id].childs.push_back(child_id);
        }
    }
}