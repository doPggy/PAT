#include <cstdio>

// https://pintia.cn/problem-sets/994805260223102976/problems/994805277847568384

int main() 
{
    int n = 0;
    scanf("%d", &n);
    int a_say, a_ges, b_say, b_ges;
    int a_drink = 0;
    int b_drink = 0;
    while(n--)
    {
        // 甲 喊 甲划 乙喊 乙划
        scanf("%d%d%d%d", &a_say, &a_ges, &b_say, &b_ges);



        if(a_ges == a_say + b_say
        && b_ges == a_say + b_say)
            continue;
        // b 赢了
        else if(b_ges == a_say + b_say)
            a_drink++;
        // a 赢了 不能用 else 会把其他错误情况放入
        else if(a_ges == a_say + b_say)
            b_drink++;
    }
    printf("%d %d\n", a_drink, b_drink);
}

//* 用如下的方式更简洁
// if(b_ges == a_say + b_say && a_ges != a_say + b_say)
//     a_drink++;
// else if(a_ges == a_say + b_say && b_say != a_say + b_say)
//     b_drink++;