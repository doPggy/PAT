#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1010;
int toll[25]; // 资费，0-1,1-2 2-3 ...

struct Record
{
    char name[25];
    int month, dd, hh, mm;//月份 天，小时，分
    bool status; // true online
} rec[maxn], temp;

// 记录要先排序，用于找配对
bool cmp(Record a, Record b)
{
    int s = strcmp(a.name, b.name);
    if(s != 0) return s < 0; // 字典序排序
    else if(a.month != b.month) return a.month < b.month;
    else if(a.dd != b.dd) return a.dd < b.dd;
    else if(a.hh != b.hh) return a.hh < b.hh;
    else if(a.mm != b.mm) return a.mm < b.mm;
}

// on index , off index
// time money 要返回
void get_ans(int on, int off, int & time, int & money)
{
    temp = rec[on];
    time = 0;
    money = 0;
    // 计算时间, 统计分钟
    while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm)
    {
        temp.mm++;
        time++;
        money += toll[temp.hh]; //卧槽，bin! , 在某个时段内一分钟一分钟算资费
        if(temp.mm >= 60)
        {
            temp.hh++;
            temp.mm = 0;
        }
        if(temp.hh >= 24)
        {
            temp.hh = 0;
            temp.dd++;
        }
    }
}

int main()
{
    for(int i = 0; i < 24; i++)
        scanf("%d", toll + i);
    int n; // 记录数
    scanf("%d", &n);
    char line[10];// off-line，on-line
    for(int i = 0; i < n; i++)
    {
        // 输入记录
        scanf("%s", rec[i].name);
        scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
        scanf("%s", line);
        if(strcmp(line, "on-line") == 0)
            rec[i].status = true;
        else
            rec[i].status = false;
    }
    // 排序,一定是按照字典序排列，一段是同一个人的
    sort(rec, rec + n, cmp);
    // next 遍历每个用户
    int on = 0, off, next;
    int need_print = 0;
    // 每个用户遍历他的
    while(on < n)
    {
        next       = on;
        need_print = 0;
        // 不超过总数，且是同一个用户
        while(next < n && strcmp(rec[next].name, rec[on].name) == 0)
        {
            if(need_print == 0 && rec[next].status) // on - line 还未配对
            {
                need_print = 1;
            }
            else if(need_print == 1 && !rec[next].status) // 已经有 on - line，遇到 off，配对
            {
                need_print = 2;
            }
            next++;
        }
        if(need_print < 2)
        {
            on = next; // 下一个用户
            continue;  //没找到有效配对
        }
        // 开始计算
        int all_money = 0;
        printf("%s %02d\n", rec[on].name, rec[on].month); // 名字，月份
        while(on < next)// 这个用户开始计算
        {
            //有效配对一定是 i 和 i + 1
            while(on < next - 1 && !(rec[on].status && !rec[on + 1].status))
                on++;
            off = on + 1;
            if(off == next)// off 已经到了 下一个用户，输出完毕
            {
                on = next;
                break;
            }
            int money = 0;
            int time  = 0;
            get_ans(on, off, time, money);
            printf("%02d:%02d:%02d %02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm, 
            rec[off].dd, rec[off].hh, rec[off].mm);
            all_money += money;
            printf("%d $%.2f\n", time, money / 100.0);
            on = off + 1; //完成一个配对，接下去找
        }
        printf("Total amount: $%.2f\n", all_money / 100.0);
    }
}