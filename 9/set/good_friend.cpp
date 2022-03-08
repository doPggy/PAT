#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1000;
int father[N]; //并查集
int is_root[N] = {false}; // 统计组数，看根节点就行


int find_father(int x)
{
    int a = x;
    // 溯回根节点
    while(x != father[x])
    {
        x = father[x];
    }

    // 压缩路径
    // 在溯回路径上的节点全部压缩
    while(a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x; // 指向根节点
    }

    return x;
}


void union_(int a, int b)
{
    int fa_a = find_father(a);
    int fa_b = find_father(b);
    
    if(fa_a != fa_b)
    {
        father[fa_a] = fa_b; //合并
    }
}

void init(int n)
{
    for(int i = 1; i <= n; i++)
        father[i] = i;
}

int main()
{
    int n, m; // m 为组数, 1~n 为数码宝贝编号
    scanf("%d%d", &n, &m);
    init(n);
    int a, b;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        union_(a, b);
    }

    for(int i = 1; i <= n; i++)
        is_root[find_father(i)] = true;

    int ans = 0;
    for(int i = 1; i <= n; i++) 
    {
        if(is_root[i]) ans++;
    }
    printf("%d\n", ans);
}
