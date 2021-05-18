#include <cstdio>
// 关键是 % 的用法
int main()
{   
    // int 就可以了
    long long c1, c2;
    long long sub;
    scanf("%lld%lld", &c1, &c2);
    // 123298 / 100 2.98  0.98 四舍五入
    sub = (c2 - c1) / 100;
    if((c2 - c1) % 100 >= 50)
        sub += 1;
    long long h, m, s;
    h = sub / 3600;
    sub = sub % 3600;
    m = sub / 60;
    sub = sub % 60;
    printf("%02lld:%02lld:%02lld\n", h, m, sub);
    // printf("%02lld:%02lld:%02lld\n", sub / 3600, sub % 3600 / 60, sub % 60 );
    return 0;
}