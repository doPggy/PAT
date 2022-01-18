#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// 下标为数字，内容为出现次数
//! 虽然范围 1~500，但是 m - i 可能大于 500，m 是1~1000
int hash_table[1001] = {0};

//! 找到最小的一对 a b 使得 a+b = m
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int num;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        ++hash_table[num];
    }

    //! 输出最小一对，由循环遍历控制了
    //! for(int i = 0; i < n; i++) 正整数，从 1 开始，而且只要遍历 1 ~ m - 1 就行
    for(int i = 1; i < m; i++)
    {
        if(hash_table[i] && hash_table[m - i])
        {
            if(i == m - i && hash_table[i] <= 1) continue;
            // 找到 a+b=m
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }

    printf("No Solution\n");
    return 0;
}