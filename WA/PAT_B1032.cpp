#include <cstdio>

// 注意，总得分
int main()
{
    const int maxn  = 100010;
    int school[maxn] = {0};
    int N = 0;
    scanf("%d", &N);
    int id = 0;
    int score = 0;
    for(int i = 0; i < N; i++)
    {
        scanf("%d%d", &id, &score);
        school[id] += score;
    }

    // id 是 1 - N 的 
    int max_id    = 1; // 实在没有就是第一个
    int max_score = -1; // 有 0 分
    for(int i = 1; i <= N; i++)
    {
        int school_score = school[i];
        if(school_score > max_score)
        {
            max_id    = i;
            max_score = school_score;
        }
    }
    printf("%d %d\n", max_id, max_score);
    return 0;
}