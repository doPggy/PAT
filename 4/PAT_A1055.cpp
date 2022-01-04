#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 100010;
int age[maxn];// 某年龄的人数

struct Person
{
    int age;
    int worths;
    char name[10];
}ps[maxn], valid[maxn];// 所与人， 在各自年龄中前 100 的

bool cmp(Person a, Person b)
{
    if(a.worths != b.worths) return a.worths > b.worths; // 从大到小
    else if(a.age != b.age) return a.age < b.age;//年龄从小到大
    else return strcmp(a.name, b.name) < 0; // 字典序从小到大
}

int main()
{
    int n, k;//人数 n，查询 k 次
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%s%d%d", ps[i].name, &ps[i].age, &ps[i].worths);
    
    sort(ps, ps + n, cmp);
    // 经过排序，可以根据年龄来统计
    int valid_num = 0;
    //!预处理，后头都对此进行排序，否则复杂度过高
    for(int i = 0; i < n; i++)
    {
        // 在百名内
        if(age[ps[i].age] < 100)
        {
            age[ps[i].age]++;
            valid[valid_num++] = ps[i]; //?
        }
    }

    int m, age_l, age_r;
    //查询 k 次
    for(int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &m, &age_l, &age_r);
        printf("Case #%d:\n", i);
        int print_num = 0;
        // 在区间内输出 m 个人
        for(int j = 0; j < valid_num && print_num < m; j++)
        {
            // 年龄在区间内
            if(valid[j].age >= age_l && valid[j].age <= age_r)
            {
                printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worths);
                print_num++;
            }
        }
        if(print_num == 0)
            printf("None\n");
    }
}
