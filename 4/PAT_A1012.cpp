#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Stu
{
    int id;//4字节 32bit
    int grade[4];
}stus[2010];

int now = 0;
int rank_[10000000][4] = {0};//为了方便查询 id - 4 个成绩

char course[5] = {'A', 'C', 'M', 'E'};

bool cmp(Stu a, Stu b)
{
    return  a.grade[now] > b.grade[now];
}


//! 用 rank 记录每个学生 4 个科目的排名, 针对每一科，sort 一次 stus,根据此将排名记录到 rank 中
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d%d%d%d",&stus[i].id, stus[i].grade + 1, stus[i].grade + 2, stus[i].grade + 3);
        // 平均分
        stus[i].grade[0] = stus[i].grade[1] + stus[i].grade[2] + stus[i].grade[3];
    }
    // 四个排行榜 排名
    for(now = 0; now < 4; now++)
    {
        sort(stus, stus + N, cmp);
        // 当前排行榜的第一位
        rank_[stus[0].id][now] = 1;
        for(int i = 1; i < N; i++)
        {
            if(stus[i].grade[now] == stus[i - 1].grade[now]) rank_[stus[i].id][now] = rank_[stus[i - 1].id][now];
            else rank_[stus[i].id][now] = i + 1;
        }
    }
    // 查询
    int query;
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &query);
        if(rank_[query][0] == 0)
            printf("N/A\n");
        else
        {
            int k = 0;
            // 找最小的
            for(int j = 1; j < 4; j++)
            {
                if(rank_[query][j] < rank_[query][k])
                    k = j;
            }
            // 最好科目的排名，对应名称
            if(i == M - 1)
                printf("%d %c", rank_[query][k], course[k]);
            else
                printf("%d %c\n", rank_[query][k], course[k]);
        }
    }
}