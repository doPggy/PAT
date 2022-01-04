#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdio.h>

using namespace std;

struct Stu
{
    char id[10];
    int moral = 0;
    int abi   = 0;
    int type  = 0;
}stus[100010];


bool cmp(Stu a, Stu b)
{
    if(a.type != b.type) return a.type < b.type; // 类型不同，
    else if(a.abi + a.moral != b.abi + b.moral) return a.abi + a.moral > b.abi + b.moral; // 类型同，总分不同，总分降序
    else if(a.moral != b.moral) return a.moral > b.moral; // 总分同，德分降序
    else return strcmp(a.id, b.id) < 0;// 德分相同, 准考证升序
}


int select_type(int L, int H, int moral, int abi)
{
    // 德才有一个低于 L，就不及格
    if(moral < L || abi < L)
        return 5;
    // 均达到高分数线
    else if(moral >= H && abi >= H)
        return 1;
    // 德达到高分数线，才没有
    else if(moral >= H && abi < H)
        return 2;
    // 达标 德 >= 才
    else if(moral < H && abi < H && moral >= abi)
        return 3;
    // 德<才 (才到高分数，德没有，德才均没有达高分，但才>德)
    else
        return 4;

}

int main()
{
    int N = 0;
    int L = 0;
    int H = 0;
    scanf("%d%d%d", &N, &L, &H);
    int num = N;// 合格人数
    for(int i = 0; i < N; i++)
    {
        scanf("%s%d%d", stus[i].id, &stus[i].moral, &stus[i].abi);
        int type = 0;
        type = select_type(L, H, stus[i].moral, stus[i].abi);
        stus[i].type = type;
        if(type == 5) num--;

    }

    sort(stus, stus + N, cmp);
    printf("%d\n", num);
    int i = 0;
    for(i = 0; i < num - 1; i++)
    {
        printf("%s %d %d\n", stus[i].id, stus[i].moral, stus[i].abi);
    }
    //! 0 个及格，不应该输出
    if(num != 0)
        printf("%s %d %d", stus[i].id, stus[i].moral, stus[i].abi);
}