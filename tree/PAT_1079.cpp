// https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560
#include<cstdio>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 100010;
int n;
double p, r;


//! 本题在叶子结点有权重
//! 0 就是根节点
struct node
{
    double data; // 叶子节点有货物量权值
    vector<int> childs;
} Nodes[maxn];

double ans = 0;

void DFS(int root, int depth)
{
    node n = Nodes[root];
    //! 叶子节点到了
    if(n.childs.empty())
    {
        ans += n.data * p * pow((1 + r), depth);
        return;
    }
    for(int i = 0; i < n.childs.size(); i++)
    {
        DFS(n.childs[i], depth + 1);
    }

}

int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int k_i = 0;
    int in;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k_i);
        if(k_i == 0)
        {
            scanf("%d", &in);
            Nodes[i].data = in;
        }
        else
        {
            for(int j = 0; j < k_i; j++)
            {
                scanf("%d", &in);
                Nodes[i].childs.push_back(in);
            }
        }
    }
    DFS(0, 0);
    printf("%.1f\n", ans);

}