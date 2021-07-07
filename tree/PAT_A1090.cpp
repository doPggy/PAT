// https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944
#include<cstdio>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1000010;
//p , r% 不需要放在里头，算深度就行了
// 数组下标代表节点编号
vector<int> childs[maxn];
// struct node
// {
//     vector<int> childs;
// } Nodes[maxn];
double p, r;
int max_depth = 0;
int num       = 0;
int n;

// 其实还有一种，返回最大深度的代码，但是还要记录此深度的叶节点个数
// 递归式
void DFS(int root, int depth)
{
    if(childs[root].size() == 0) // 到达叶节点
    {
        if(depth > max_depth)
        {
            max_depth = depth;
            num       = 1;
        }
        // 达到最深深度，统计一个
        else if(depth == max_depth)
            num++;
        return; //!
    }

    for(int i = 0; i < childs[root].size(); i++)
    {
        DFS(childs[root][i], depth + 1);
    }

    return;
}

int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    int parent_index = 0; // Si is index of supplier for i-th member
    int root;
    r /= 100;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &parent_index);
        // 没有父节点
        if(parent_index == -1)
            root = i;
        //! 不这么做 -1 就访问越界
        else
            childs[parent_index].push_back(i);
    }
    DFS(root, 0);
    // p 为基础价格，每一层升 r% p * (1 + r)^n
    printf("%.2f %d\n", p * pow(1 + r, max_depth), num);

    return 0;
}