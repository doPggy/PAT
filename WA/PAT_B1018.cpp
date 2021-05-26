#include <cstdio>

// 1. 判断胜负逻辑
// 2. 怎么表述锤子剪刀布 (字母 -> 数字)
// 3. 统计

// 有序化
// 考虑到输出字典序最小的
int change(char c)
{
    if(c == 'B') return 0;
    else if(c == 'C') return 1;
    else if(c == 'J') return 2;
}


int main()
{
    // 0 - 布 1 - 锤子 2 - 剪刀 这也算一种编码

    char mp[3] = {'B', 'C', 'J'};
    // 甲乙胜平输次数
    int a_ans[3]        = {0};
    int b_ans[3]        = {0};
    // 统计胜利的手势次数 布 锤 剪
    int a_ges_count[3]  = {0};
    int b_ges_count[3]  = {0};
    int n    = 0;
    scanf("%d", &n);
    char a_ges, b_ges;
    while(n--)
    {
        // 吸收空格
        getchar();
        // 甲乙的手势
        scanf("%c %c", &a_ges, &b_ges);
        // 用数字来代替字母
        int a_change = change(a_ges);
        int b_change = change(b_ges);
        // 平局
        if(a_change == b_change)
        {
            a_ans[1]++;
            b_ans[1]++;
        }
        // 甲胜利 这里的胜负判断很关键 发现了循环，使用 %
        else if((a_change + 1) % 3 == b_change)
        {
            a_ans[0]++;
            b_ans[2]++;
            a_ges_count[a_change]++;
        }
        // 乙胜利 这里不能用 else
        else if((b_change + 1) % 3 == a_change)
        {
            b_ans[0]++;
            a_ans[2]++;
            b_ges_count[b_change]++;
        }
    }
    // 胜平输次数
    printf("%d %d %d\n", a_ans[0], a_ans[1], a_ans[2]);
    printf("%d %d %d\n", b_ans[0], b_ans[1], b_ans[2]);

    int max_a_count = -1;
    int max_a_index = 0;
    int max_b_count = -1;
    int max_b_index = 0;
    for(int i = 0; i < 3; i++)
    {
        if(b_ges_count[i] > max_b_count)
        {
            max_b_count = b_ges_count[i];
            max_b_index = i;
        }
        if(a_ges_count[i] > max_a_count)
        {
            max_a_count = a_ges_count[i];
            max_a_index = i;
        }
    }
    printf("%c %c\n", mp[max_a_index], mp[max_b_index]);

    return 0;
}