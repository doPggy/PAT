#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

// 输入的是正数，0 就可以当初始值
//! 输入的是 10^5 个数字， 范围是 1~10^4
int bets[10010] = {0};
// 次序，谁先输入谁后输入
int order[100010] = {0};

// 本质，找第一个不重复的数字
int main()
{
    int n;
    scanf("%d", &n);
    int bet;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &bet);
        bets[bet]++;
        order[i] = bet;
    }

    int i;
    for(i = 0; i < n; i++)
    {
        int bet = order[i];
        if(bets[bet] <= 0) continue;
        if(bets[bet] == 1) break;
    }
    if(bets[order[i]] == 1)
        printf("%d\n", order[i]);
    else
        printf("None\n");
}