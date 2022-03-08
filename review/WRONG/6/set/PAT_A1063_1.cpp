#include <cstdio>
#include <set>


using namespace std;

const int MAX = 51;
set<int> count[MAX]; // the sets are numbered from 1 to N


void cmp(int st1, int st2)
{
    int total = count[st2].size();// 计算并集的数量
    int share = 0; // 计算交集的数量
    for(set<int>::iterator it = count[st1].begin(); it != count[st1].end(); it++)
    {
        // 找到了
        if(count[st2].find(*it) != count[st2].end())
            share++;
        else
            total++;
    }
    printf("%.1f%%\n", share * 100.0 / total);
}

int main()
{
    int n, m, k;
    int data;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &data);
            count[i].insert(data);
            // if(count.find(data) != count.end()) count[data]++;
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