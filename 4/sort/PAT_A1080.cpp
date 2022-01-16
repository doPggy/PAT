#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
// const int maxn = 50;
struct Stu
{
    int id;//考生编号
    int ge;
    int gi;
    int sum;
    int choice[6];//志愿选择，最多 5 个
    int r;//排名
}stus[40010];

struct Sch
{
    int quota;//额度
    int stu_num;//已招生人数
    int last_admit_i; // 上一个录取的学生 index, 已经排序后
    int ids[40010];//招收的学生 id
}schs[110];

bool cmp(Stu &a, Stu &b)
{
    if(a.sum != b.sum) return a.sum > b.sum;
    //! else if(a.ge != b.ge) return a.ge > b.ge;
    //! 使用如上代码，会超时，同时要传引用
    else return a.ge > b.ge;
}

// 输出学校录取的学生id，id 要升序
bool cmp_id(int a_id, int b_id)
{
    return a_id < b_id;
}


int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &m, &k);
    // 初始化学校
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &schs[i].quota);
        schs[i].stu_num       = 0;
        schs[i].last_admit_i  = -1; //! 这里要注意 0 也是编号
    }
    // 初始化学生
    for(int i = 0; i < n; i++)
    {
        stus[i].id = i;
        scanf("%d%d", &stus[i].ge, &stus[i].gi);
        stus[i].sum = stus[i].ge + stus[i].gi;
        // 可申请学校id, 0~M-1
        for(int j = 0; j < k; j++)
            scanf("%d", stus[i].choice + j);
    }

    sort(stus, stus + n, cmp);
    // 排名
    for(int i = 0; i < n; i++)
    {
        if(i > 0
        && stus[i].sum == stus[i - 1].sum
        && stus[i].ge == stus[i - 1].ge)
            stus[i].r = stus[i - 1].r; // 排名相等
        else
            stus[i].r = i;
    }

    // 录取
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            int id            = stus[i].id; // 学生 id
            int sch_id        = stus[i].choice[j];
            int stu_num       = schs[sch_id].stu_num;
            int last_admit_i  = schs[sch_id].last_admit_i;
            // sch_   = schs[sch_id];
            // 录取 人数未满，或和上一个录取考生与当前考生排名相同
            if(stu_num < schs[sch_id].quota
            || (last_admit_i != -1 && stus[last_admit_i].r == stus[i].r))//! 不应是 stus[id]
            {
                schs[sch_id].last_admit_i = i;
                schs[sch_id].ids[stu_num] = id;
                schs[sch_id].stu_num++;
                break;//! 录取了就不需要迭代了！！！
            }
            //否则都不录取
        }
    }

    //输出
    for(int i = 0; i < m; i++)
    {
        int stu_num = schs[i].stu_num;
        if(stu_num == 0)
        {
            printf("\n");//! 没有就空行
            continue;
        }
        sort(schs[i].ids, schs[i].ids + stu_num, cmp_id);
        for(int j = 0; j < stu_num; j++)
        {
            printf("%d", schs[i].ids[j]);
            if(j != stu_num - 1) printf(" ");
        }
        printf("\n");
    }
}