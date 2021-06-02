#include <algorithm>
#include <cstdio>

// https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584`

int main()
{
    // 3x^4 + ....
    // ! 这可以合并成一个
    int multi_x[1005] = {0};
    int multi_a[1005] = {0};
    int i = 0;
    //!非零项的系数和指数
    while(scanf("%d%d", multi_a + i, multi_x + i) != EOF)
    {
        i++;
    }


    for(int j = 0; j < i; j++)
    {
        if(multi_x[j] > 0)
        {
            multi_a[j] *= multi_x[j];
            multi_x[j]--;
        }
        else i--;
    }

    //! “零多项式”的指数和系数都是 0，但是表示为 0 0。
    if(i == 0)
    {
        printf("0 0\n");
    }
    else
    {
        int j = 0;
        for(j = 0; j < i - 1; j++)
        {
            printf("%d %d ", multi_a[j], multi_x[j]);
        }
        printf("%d %d\n", multi_a[j], multi_x[j]);

    }
    return 0;
}

