#include<cstdio>
#include <cmath>
// https://pintia.cn/problem-sets/994805260223102976/problems/994805294251491328

//! 还是没有把规律归纳成数学公式，等差数列求和 + 不等式
int main()
{
    int n = 0;
    char c = 0;
    scanf("%d %c", &n, &c);
    int bottom = (int)sqrt(2.0 * (1 + n)) - 1; // 最外层的字符数
    if(bottom % 2 == 0) bottom --; //为奇数
    int left = n - (1 + bottom) * (1 + bottom) / 2 + 1;

    // 倒三角
    for(int i = bottom; i > 0; i -= 2)
    {
        for(int j = 0; j < (bottom - i) / 2; j++)
            printf(" ");
        for(int k = 0; k < i; k++)
            printf("%c", c);
            // ! 这里输出了干嘛？
        // for(int j = 0; j < (bottom - i) / 2; j++)
        //     printf(" ");
        printf("\n");
    }

    // 正三角
    for(int i = 3; i <= bottom ; i += 2)
    {
        for(int j = 0; j < (bottom - i) / 2; j++)
            printf(" ");
        for(int k = 0; k < i; k++)
            printf("%c", c);
        // for(int j = 0; j < (bottom - i) / 2; j++)
        //     printf(" ");
        printf("\n");
    }

    printf("%d\n", left);



}