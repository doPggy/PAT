#include <algorithm>
#include <cstdio>

// https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000

const int max_n = 1111;

int main()
{
    int k = 0;
    int count = 0; // 非零个数
    //* 更好的做法，p[n] 代表 n 次幂的系数
    // 最后遍历所有的就行
    double p[max_n] = {0};
    //! 我的想法，一条多项式存一个数组
    // double A[26] = {0};
    // double B[26] = {0};
    scanf("%d", &k);
    double a = 0;
    int p_n  = 0;
    for(int i = 0; i < k; i++)
    {
        scanf("%d %lf", &p_n, &a);
        p[p_n] += a;
    }
    //!这种方式需要判断是不是合并，同时还要看是否相加为0
    // count += k;

    scanf("%d", &k);
    // count += k;
    for(int i = 0; i < k; i++)
    {
        scanf("%d %lf", &p_n, &a);
        // if(p[p_n] != 0)
            // count--;
        p[p_n] += a;
        // if(p[p_n] == 0) count--;
    }

    for(int i = 0; i < max_n; i++)
    {
        if(p[i] != 0)
            count++;

    }

    printf("%d", count);
    // n = 0. 常数项
    for(int i = max_n - 1; i >= 0; i--)
    {
        if(p[i] != 0) printf(" %d %.1f", i, p[i]);
    }
    printf("\n");

    return 0;
}