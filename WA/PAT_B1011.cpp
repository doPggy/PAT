#include <cstdio>

int main()
{
    int t = 0;
    scanf("%d", &t);

    // int [-2^31, 2^31 - 1]
    long long a, b, c = 0;
    // for(int i = 0; i < t; i++)
    int tcase = 1;
    while(t--)
    {
        // lld
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a + b > c)
            printf("Case #%d: true\n", tcase);
        else
            printf("Case #%d: false\n", tcase);
        tcase++;
    }

    return 0;
}