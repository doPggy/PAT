//https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448
#include <cstdio>

typedef struct Stu
{
    char name[11]; // 10 个字符，外加 \0 所以起码 11 个
    char id[11];
    int score;
} STU;


int main()
{
    STU ans_max = {"", "", -1};
    STU ans_min = {"", "", 101};
    STU input;
    int n = 0;
    scanf("%d", &n);
    // 边输入边判断，没必要数组
    while(n--)
    {
        scanf("%s%s%d", input.name, input.id, &input.score);
        if(input.score > ans_max.score) ans_max = input;
        if(input.score < ans_min.score) ans_min = input;
    }
    printf("%s %s\n", ans_max.name, ans_max.id);
    printf("%s %s\n", ans_min.name, ans_min.id);
}