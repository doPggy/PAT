#include <cstdio>
#include <algorithm>

//! 把单价高的先卖了，看是否能满足需求量
using namespace std;

struct MoonCake
{
    double sell; // 总售价 只说了正数，而非正整数
    double store; //只说了正数，而非正整数
    double price; //单价

}moon_cakes[1010];

// 高往低排列
bool cmp(MoonCake &a, MoonCake &b)
{
    return a.price > b.price;
}

int main()
{
    int n;//种类数
    double d;//市场最大需求量 为了方便
    scanf("%d%lf", &n, &d);
    for(int i = 0; i < n; i++)
        scanf("%lf", &moon_cakes[i].store);

    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &moon_cakes[i].sell);
        moon_cakes[i].price = moon_cakes[i].sell / moon_cakes[i].store;// 求单价
    }

    sort(moon_cakes, moon_cakes + n, cmp);
    double profit = 0.0;
    for(int i = 0; i < n; i++)
    {
        if(moon_cakes[i].store >= d)
        {
            profit += d * moon_cakes[i].price;
            break;
        }
        else
        {
            profit += moon_cakes[i].sell;
            d      -= moon_cakes[i].store;
        }
    }
    printf("%.2lf\n", profit);
}

