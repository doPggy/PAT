#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;// 1~n 编号
int father[N];
int n;
int course[N]; //1~1000 下标是爱好编号，对应内容为喜欢此爱好的人的编号(一个就好，反正会合并的)
int is_root[N];


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
    for(int i = 1; i <= n; i++)
        father[i] = i;
}

int main()
{
    scanf("%d", &n);
    init(n);
    int hobby_num;
    int hobby;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d:", &hobby_num);
        // 输入每一种爱好，每个爱好的人就要合并
        for(int j = 0; j < hobby_num; j++)
        {
            scanf("%d", &hobby);
            if(course[hobby] == 0) course[hobby] = i;
            // course[hobby] 对应喜欢此爱好的人，找到他的集合，然后合并
            union_(i, find_father(course[hobby]));
        }
    }

    //统计
    for(int i = 1; i <= n; i++)
        is_root[find_father(i)]++;
    int count = 0;
    for(int i = 1; i <= n; i++)
        if(is_root[i] != 0) count++;
    printf("%d\n", count);
    sort(is_root + 1, is_root + n + 1, cmp); //! 注意 sort 的起始，因为编号为 1 开始
    for(int i = 1; i <= count; i++)
    {
        if(i != count)
            printf("%d ", is_root[i]);
        else
            printf("%d\n", is_root[i]);
    }
}