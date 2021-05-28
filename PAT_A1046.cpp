#include <cstdio>

// https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424

int main()
{
    int n             = 0;
    int cycle[100005] = {0};
    // 输入可以先不用回车，输入几个后一并送入
    scanf("%d", &n);
    // 是个环路，但是其实就是两条路径，比谁距离更短，所以需要总和
    // 有环，要用 %
    int total_len = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", cycle + i);
        // cycle[i] v(i+1) -> v(i+2) 距离
        total_len += cycle[i];
    }

    int m = 0;
    scanf("%d", &m);
    int exit_1, exit_2;
    int len         = 0;
    while(m--)
    {
        scanf("%d%d", &exit_1, &exit_2);
        len       = 0;
        int steps = (exit_2 + n - exit_1) % n; // 循环队列类似的想法
        // 倒回去
        int i     = exit_1 - 1;
        // steps     = (steps > 0) ? steps : -steps;
        for(int step = 0; step < steps; step++)
        {
            len += cycle[i];
            i = (i + 1) % n;
        }
        if(len < total_len - len)
            printf("%d\n", len);
        else
            printf("%d\n", total_len - len);
    }
}