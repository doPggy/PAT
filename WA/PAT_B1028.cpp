// https://pintia.cn/problem-sets/994805260223102976/problems/994805293282607104
#include <cstdio>

struct Brith
{
    char name[6];
    //! 这样日期比对其实很麻烦
    int yy, mm, dd;
    // char date[13];
} input, ans_old, ans_young, left, right;

typedef struct Brith B;


void init()
{
    //2014.9.6 为截止 超过两百岁无效，
    //! 最年轻的初始值，是最老时间，这种思想要有
    ans_young.yy = left.yy = 1814;
    ans_young.mm = left.mm = 9;
    ans_young.dd = left.dd = 6;

    ans_old.yy = right.yy = 2014;
    ans_old.mm = right.mm = 9;
    ans_old.dd = right.dd = 6;
}

bool brith_is_older_than(struct Brith a, struct Brith b)
{
    if(a.yy != b.yy) return a.yy <= b.yy;
    else if(a.mm != b.mm) return a.mm <= b.mm;
    else if(a.dd != b.dd) return a.dd <= b.dd;
}

bool birth_is_younger_than(B a, B b)
{
    if(a.yy != b.yy) return a.yy >= b.yy;
    else if(a.mm != b.mm) return a.mm >= b.mm;
    else if(a.dd != b.dd) return a.dd >= b.dd;
}

//! 我写的实在是脑瘫版本
// int brith_is_older_than(struct Brith a, struct Brith b)
// {
//     if(a.yy < b.yy)
//         return 1;
//     else if(a.yy == b.yy
//     && a.mm < b.mm)
//         return 1;
//     else if(a.yy == b.yy
//     && a.mm == b.mm
//     && a.dd < b.dd)
//         return 1;
//     else
//         return 0;
// }

// int brith_is_younger_than(struct Brith a, struct Brith b)
// {
//     if(a.yy > b.yy)
//         return 1;
//     else if(a.yy == b.yy
//     && a.mm > b.mm)
//         return 1;
//     else if(a.yy == b.yy
//     && a.mm == b.mm
//     && a.dd > b.dd)
//         return 1;
//     else
//         return 0;
// }

bool brith_is_lawful(B a)
{
    return brith_is_older_than(a, right) && birth_is_younger_than(a, left);
}

int main()
{
    init();
    int n = 0;
    int lawful_count = 0;
    scanf("%d", &n);

    while(n--)
    {
        scanf("%s%d/%d/%d", input.name, &input.yy, &input.mm, &input.dd);
        if(!brith_is_lawful(input)) continue;
        lawful_count++;
        // 合法，不超过 200
        if(brith_is_older_than(input, ans_old))
            ans_old = input;
        if(birth_is_younger_than(input, ans_young))
            ans_young = input;
    }
    //! 没有一个合法的
    if(lawful_count == 0)
        printf("0\n");
    else
        printf("%d %s %s\n", lawful_count, ans_old.name, ans_young.name);

}