#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

// 下标代表分数，内容代表获得分数的人数
int hash_table[110] = {0};

int main()
{

    int n, k;
    scanf("%d", &n);
    int score = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &score);
        hash_table[score]++;
    }

    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &score);
        printf("%d", hash_table[score]);
        if(i != k - 1) printf(" ");
    }
    printf("\n");

}