#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 100010;
struct Stu
{
    int id; //准考证号
    char name[10];
    int score;
}stus[maxn];

bool cmp1(Stu a, Stu b)
{
    return a.id < b.id;
}

// C = 2 名字非减
bool cmp2(Stu a, Stu b)
{
    int s = strcmp(a.name, b.name);
    if(s != 0) return s < 0;
    else return a.id < b.id;
    
}

bool cmp3(Stu a, Stu b)
{
    if(a.score != b.score) return a.score < b.score;
    else return a.id < b.id;
}


int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d%s%d", &stus[i].id, stus[i].name, &stus[i].score);
    if(c == 1)
        sort(stus, stus + n, cmp1);
    else if(c == 2)
        sort(stus, stus + n, cmp2);
    else if(c == 3)
        sort(stus, stus + n, cmp3);
    for(int i = 0; i < n; i++)
    {
        printf("%06d %s %d\n", stus[i].id, stus[i].name, stus[i].score);
    }
}