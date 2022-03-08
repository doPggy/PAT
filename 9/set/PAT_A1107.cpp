#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;


const int N = 1010;
int father[N];
int course[N] = {0}; // 兴趣下标 -> 喜欢此兴趣的人的编号
int is_root[N] = {0}; // 根节点下标 -> 对应集合的人数

bool cmp(int a, int b)
{
    return a > b;
}


int find_father(int x)
{
    int a = x;
    while(x != father[x])
    {
        x = father[x];
    }
    // 压缩路径
    while(a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void union_(int a, int b)
{
    int fa_a = find_father(a);
    int fa_b = find_father(b);
    if(fa_a != fa_b)
    {
        father[fa_a] = fa_b; // fa_b 为 fa_a 的父节点
    }
}


void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    int k;
    int h;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &h);
            if(course[h] == 0)
                course[h] = i;
            // 和喜欢的每一个爱好对应的人合并就行 
            union_(i, find_father(course[h]));
        }
        //! 这个方法不对，为了 union, 
        // for(int j = 0; j < k; j++)
        // {
        //     scanf("%d", &c);
        // }
    }
    for(int i = 1; i <= n; i++)
        is_root[find_father(i)]++;

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(is_root[i] != 0)
            ans++;
    }
    printf("%d\n", ans);
    //! 题目要求非增序列
    sort(is_root + 1, is_root + n + 1, cmp);
    for(int i = 1; i <= ans; i++)
    {
        if(i != ans)
            printf("%d ", is_root[i]);
        else
            printf("%d\n", is_root[i]);
    }
}