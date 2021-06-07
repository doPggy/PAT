#include <algorithm>
#include <cstdio>

struct Poly
{
    int exp; //指数
    double eco; //系数
} poly[1001];

double ans[2001]; //答案，下标代表指数，内容代表系数
// 2001 是因为，最高次幂是 1000.
int main()
{
    int n = 0;
    scanf("%d", &n);
    int exp;
    double eco;
    // 记录到 poly 用于第二次的边读边计算
    for(int i = 0; i < n; i++)
    {
        scanf("%d%lf", &poly[i].exp, &poly[i].eco);
        // poly[i].exp = exp;
        // poly[i].eco = eco;
    }
    int k = 0;
    scanf("%d", &k);
    // 第二个多项式
    for(int i = 0; i < k; i++)
    {
        scanf("%d%lf", &exp, &eco);
        // 指数相加，系数相乘后加到对应次数
        for(int j = 0; j < n; j++)
        {
            ans[poly[j].exp + exp] += poly[j].eco * eco;
        }
    }

    int count = 0;
    //! 2000 个，不然可能会其他情况
    for(int i = 0; i < 2001; i++)
    {
        if(ans[i] != 0)
            count++;
    }

    printf("%d", count);
    // 大到小
    for(int i = 2000 ; i >= 0; i--)
    {
        if(ans[i] != 0)
            printf(" %d %.1f", i, ans[i]);
    }
    printf("\n");
}