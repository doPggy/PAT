#include <cstdio>
#include <algorithm>

using namespace std;

// https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424

int main()
{
    int n             = 0;
    // dis[i] 表示 1 号节点顺指针到达 i 号节点顺时针方向的下一个节点
    int dis[100005] = {0};
    //! 而我只想到了 用一个 A[i] 是到下一个(i+1)节点的距离
    int A[100005] ={0};
    // 输入可以先不用回车，输入几个后一并送入
    scanf("%d", &n);
    
    int sum = 0; // 总距离 判断顺时针逆时针哪个更短
    //! 这里预留一个 dis[0] 很关键，
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", A + i);
        sum    += A[i];
        dis[i] = sum;
    }
    int m = 0;
    scanf("%d", &m);
    int left, right;
    while(m--)
    {
        scanf("%d%d", &left , &right);
        if(left > right) swap(left, right);
        //* dis(left , right) dis[right - 1] - dis[left - 1] 
        //* right 到 1 的距离 - left 到 1 的距离, 同时 dis 是1 到 i 的下一个
        // !想一下 1 - 4 这种情况。相当于 0 - 1 的距离为 0
        int tem = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(tem, sum - tem));
    }
}

// int main()
// {
//     int n             = 0;
//     int cycle[100005] = {0};
//     // 输入可以先不用回车，输入几个后一并送入
//     scanf("%d", &n);
//     // 是个环路，但是其实就是两条路径，比谁距离更短，所以需要总和
//     // 有环，要用 %
//     int total_len = 0;
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d", cycle + i);
//         // cycle[i] v(i+1) -> v(i+2) 距离
//         total_len += cycle[i];
//     }

//     int m = 0;
//     scanf("%d", &m);
//     int exit_1, exit_2;
//     int len         = 0;
//     while(m--)
//     {
//         scanf("%d%d", &exit_1, &exit_2);
//         len       = 0;
//         int steps = (exit_2 + n - exit_1) % n; // 循环队列类似的想法
//         // 倒回去
//         int i     = exit_1 - 1;
//         // steps     = (steps > 0) ? steps : -steps;
//         for(int step = 0; step < steps; step++)
//         {
//             len += cycle[i];
//             i = (i + 1) % n;
//         }
//         if(len < total_len - len)
//             printf("%d\n", len);
//         else
//             printf("%d\n", total_len - len);
//     }
// }