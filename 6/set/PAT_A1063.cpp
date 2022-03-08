#include <cstdio>
#include <set>

using namespace std;

const int N = 51;

set<int> st[N];


void cmp(int st1, int st2)
{
    int total = st[st2].size(); // 并集
    int same = 0; // 交集元素个数
    // 迭代器
    for(set<int>::iterator it = st[st1].begin(); it != st[st1].end(); it++)
    {
        if(st[st2].find(*it) != st[st2].end()) // 找到:
            same++;
        else total++;// 并集元素增加，因为total 初始是 st2 的个数，若 st1 中的元素 st2 没有，那要增加
    }

    printf(".1f%%\n", same * 100.0 / total);//!
}

int main()
{
    int n, m, k; // n 为个数，m 为集合内个数，k 为查询次数
    int data;
    // 1 ~ n 编号
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &data);
            st[i].insert(data); // 加入集合
        }
    }

    scanf("%d", &k);
    int st1, st2;
    for(int i = 0; i < k; i++)
    {
        scanf("%d%d", &st1, &st2);
        cmp(st1, st2);
    }
}