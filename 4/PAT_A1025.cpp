#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdio.h>

using namespace std;

struct Stu
{
    char id[15];
    int location_id;
    int local_rank;
    int final_rank;
    int score;
}stus[30013];

bool cmp(Stu a, Stu b)
{
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}


int main()
{
    int N, k = 0; // N location num
    int num  = 0; //! 总人数
    scanf("%d", &N);
    for(int j = 0; j < N; j++)
    {
        // 输入
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
        {
            // num 会不断增加，不能用 num+i 的形势
            scanf("%s %d", stus[num].id, &stus[num].score);
            stus[num].location_id = j + 1;
            num++;
        }

        // 考场内排序 sort() num - k  ~ num 划分考场
        sort(stus + num - k, stus + num, cmp);
        stus[num - k].local_rank = 1;
        // 算考场内排名
        for(int i = num - k + 1; i < num; i++)
        {
            if(stus[i].score == stus[i - 1].score)
                stus[i].local_rank = stus[i - 1].local_rank;
            else
                stus[i].local_rank = i - (num - k) + 1;
        }
    }
    // 全体排序
    sort(stus, stus + num, cmp);
    // stus[0].final_rank = 1;
    int r = 1;
    printf("%d\n", num);
    printf("%s %d %d %d", stus[0].id, r, stus[0].location_id, stus[0].local_rank);
    for(int i = 1; i < num; i++)
    {
        if(stus[i].score != stus[i - 1].score)
            r = i + 1;
        // else
        // {
        //     printf("%s %d %d %d", stus[i].id, r, stus[i].local_rank);
        // }
        printf("\n%s %d %d %d", stus[i].id, r, stus[i].location_id, stus[i].local_rank);
    }
}