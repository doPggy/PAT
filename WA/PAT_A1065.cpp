#include <cstdio>
#include <algorithm>

using namespace std;

//https://pintia.cn/problem-sets/994805342720868352/problems/994805406352654336

//! A B C long long [-2^63, 2^63],
//! 利用正负溢出，这个需要看一下，408 反而还不搞这个
int main()
{

    int t = 0;
    long long A;
    long long B;
    long long C;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld", &A, &B, &C);
        long long A_plus_B = A + B;
        int flag = 0;
        //! 发生正溢出 [-2^64 , -2] A + B > C
        if(A > 0 && B > 0 && A_plus_B < 0) flag = 1; 
        //! 发生负溢出 [0, 2^63) A + B < C (2^64 % 2^64) 得到左边界
        else if(A < 0 && B < 0 && A_plus_B >= 0) flag = 0; // >=0
        else if(A_plus_B > C) flag = 1;
        else flag = 0;
        if(flag)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
}