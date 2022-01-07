#include<cstdio>
#include<cstring>
#include <string>
#include<algorithm>
#include <map>

using namespace std;
// 查询类型

const int maxn = 10010;
struct Car_Record
{
    char id[8]; //车牌号
    int time;// 记录时刻 换算成 s，
    char status[4];// in, out
}all[maxn], valid[maxn]; //

int valid_num = 0; //有效记录的个数
map<string, int> park_time;// 每辆车停留的时间

// 车牌号按字典序排，然后按时间小到大排，方便找有效记录对
bool cmp(Car_Record &a, Car_Record &b)
{
    int s = strcmp(a.id, b.id);
    if(s != 0) return s < 0;
    else return a.time < b.time;
}

bool cmp_time(Car_Record &a, Car_Record &b)
{
    return a.time < b.time; // 保证了不会同一时间 in or out
}

// 从 0 点开始算即可
int time_2_sec(int hh, int mm, int ss)
{
    return hh * 3600 + mm * 60 + ss;
}


int main()
{
    int n, k, hh, mm, ss; // 时分秒 
    scanf("%d%d", &n, &k);//记录数，查询数
    // 输入车的记录    
    for(int i = 0; i < n; i++)
    {
        //! 输入格式
        scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
        all[i].time = time_2_sec(hh, mm, ss);
    }

    sort(all, all + n, cmp);

    // 找配对 //! i + 2 需要吗
    int max_time = -1;
    for(int i = 0; i < n - 1; i++)
    {
        // 同一辆车 且配对
        if(!strcmp(all[i].id, all[i + 1].id)
        && !strcmp(all[i].status, "in")
        && !strcmp(all[i + 1].status, "out"))
        {
            //! 两个记录都要进入
            valid[valid_num++] = all[i];
            valid[valid_num++] = all[i + 1];
            int park_time_len  = all[i + 1].time - all[i].time;
            if(park_time.count(all[i].id) == 0)// 首次
                park_time[all[i].id] = 0;
            //! else 加这个就是臭傻逼
            park_time[all[i].id] += park_time_len;
            max_time = max(max_time, park_time[all[i].id]);//存最大停留时间
        }
    }

    // 将有效记录按照时间小到大排序一遍，方便查询(查询时间也是小到大)
    sort(valid, valid + valid_num, cmp_time);

    //查询
    int now   = 0; //! 查询时间递增，故可以保留
    int count = 0; //! 不能放在循环体内
    for(int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int query_time = time_2_sec(hh, mm, ss);
        while(now < valid_num && query_time >= valid[now].time)
        {
            // 有车进，校内车数量增加,反之减少
            if(!strcmp(valid[now].status, "in"))
                count++;
            //! else if(!strcmp(valid[now].status, "out")) 还是太浪费了这样写
            else
                count--;
            now++;
        }
        printf("%d\n", count);
    }

    // 找 max_time  对应车牌
    map<string, int>::iterator it;
    for(it = park_time.begin(); it != park_time.end(); it++)
    {
        if(it->second == max_time)
            printf("%s ", it->first.c_str());
    }
    //! 这个也不会 1234 / 100 % 10 = 2 就是 60 进制
    printf("%02d:%02d:%02d\n", max_time / 3600, max_time % 3600 / 60, max_time % 60);
}