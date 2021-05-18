#include <cstdio>

// 先考虑算法
// 范围 10^9
int main()
{  
    long long A, B;
    int Da, Db;
    scanf("%ld%d%ld%d", &A, &Da, &B, &Db);

    long Pa = 0, Pb = 0;
    while(A || B)
    {
        if(A % 10 == Da)
            Pa = (Pa * 10) + Da;
        if(B % 10 == Db)
            Pb = (Pb * 10) + Db;
        A /= 10;
        B /= 10;
    }
    printf("%d\n", Pa + Pb);
    return 0;
}