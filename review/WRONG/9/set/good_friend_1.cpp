#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 110;
int father[N]; // 并查集
bool is_root[N] = {false};

int find_father(int x)
{
    int a = x;
    while(x != father[x])
    {
        x = father[x];
    }

    // 压缩路径，之前的查询路径上的节点全都连到根节点
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
        father[fa_a] = fa_b;
}


void init(int n)
{
    //! for(int i = 0; i < n; i++) 1~n 不是 0~n-1！！！
    for(int i = 1; i <= n; i++)
        father[i] = i;
}


int main()
{
    // 编号 1 ~ n
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int a, b;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);// 不要背，要理解, 这两个人是好朋友，那就可以分为一个组
        union_(a, b);
    }
    //统计一下根节点，这个就是组数, 注意，编号 1~n , 所以检查范围最多到 n
    for(int i = 1; i <= n; i++)
    {
        is_root[find_father(i)] = true;
    }
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(is_root[i]) count++;
    }
    printf("%d\n", count);
}