#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 50;

struct Stu
{
    char name[11];
    char id[11];
    int score;
}stus[maxn];

bool cmp(Stu a, Stu b)
{
    return a.score > b.score;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s %s %d", stus[i].name, stus[i].id, &stus[i].score);
    sort(stus, stus + n, cmp);    
    int left, right;
    scanf("%d%d", &left, &right);
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        if(stus[i].score >= left && stus[i].score <= right)
        {
            printf("%s %s\n", stus[i].name, stus[i].id);
            flag = true;
        }
    }
    if(!flag) printf("NONE\n");
}