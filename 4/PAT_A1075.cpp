#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 10010;

struct Stu
{
    int id;
    bool flag; // 是否要输出(都没有提交，不用输出)
    int score_all; //总分
    int score[6]; // 每个科成绩, 可以初值为 -1 用来区分不同情况
    int solve; // 完美解题数
}stus[maxn];

bool cmp(Stu a, Stu b)
{
    // if(a.flag != b.flag) return a.flag > b.flag;
    // 总分下降排列
    if(a.score_all != b.score_all) return a.score_all > b.score_all;
    else if(a.solve != b.solve) return a.solve > b.solve;
    else if(a.id != b.id) return a.id < b.id;
}
int n, k, m;
int full[6];//每道题的满分

void init()
{
    for(int i = 1; i <= n; i++)
    {
        stus[i].id = i;
        stus[i].score_all = 0;
        stus[i].flag = false;
        stus[i].solve = 0;
        memset(stus[i].score, -1, sizeof(stus[i].score));
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    // 初始化
    init();
    // 设置每道题的满分
    for(int i = 1; i <= k; i++)
        scanf("%d", full + i);
    int u_id, problem_id, score_obtained;
    // 提交记录
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u_id, &problem_id, &score_obtained);
        if(score_obtained != -1) // 编译通过，可能可以提交
            stus[u_id].flag = true;
        if(score_obtained == -1 && stus[u_id].score[problem_id] == -1) //未提交过，但编译不通过
            stus[u_id].score[problem_id] = 0;
        // 第一次满分
        if(score_obtained == full[problem_id]
        && stus[u_id].score[problem_id] < full[problem_id])
        // {
            stus[u_id].solve++; //完美 + 1
            // stus[u_id].score[problem_id] = score_obtained;
        // }
        // 分数比之前的高 ,不能放在前头，满分逻辑会进不去
        if(score_obtained > stus[u_id].score[problem_id])
            stus[u_id].score[problem_id] = score_obtained;
    }
    //计算每个人的总分
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(stus[i].score[j] != -1)
                stus[i].score_all += stus[i].score[j];
        }
    }
    //! 排序 stus + 1 ~ n + 1
    sort(stus + 1, stus + n + 1, cmp);
    int rank = 1;
    for(int i = 1; i <= n && stus[i].flag; i++)
    {
        // 和前一个不同分，就当前排名，否则和前一个人同排名
        if(i > 1 && stus[i].score_all != stus[i - 1].score_all)
            rank = i;
        printf("%d %05d %d", rank, stus[i].id, stus[i].score_all);
        for(int j = 1; j <= k; j++)
        {
            if(stus[i].score[j] == -1)
                printf(" -");
            else
                printf(" %d", stus[i].score[j]);
        }
        printf("\n");
    }
}