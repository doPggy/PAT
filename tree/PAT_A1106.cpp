// https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464
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
int min_depth = 100010;
int count_min     = 0;

vector<int> childs[maxn];

void DFS(int root, int depth)
{
    // 子节点
    if(childs[root].size() == 0)
    {
        if(depth < min_depth)
        {
            min_depth = depth;
            count_min = 1;
        }
        else if(depth == min_depth)
            count_min++;
        return;
    }

    for(int i = 0; i < childs[root].size(); i++)
    {
        DFS(childs[root][i], depth + 1);
    }
}

int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    int num;
    int child_id;
    r /= 100; //! 这里注意，传入的是 percentage r%
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        for(int j = 0; j < num; j++)
        {
            scanf("%d", &child_id);
            childs[i].push_back(child_id);
        }
    }
    DFS(0, 0);
    printf("%.4f %d\n", p * pow(1 + r, min_depth), count_min);
}