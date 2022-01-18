#include <cstdio>

//! n=3, 123 132 213 231 ....
using namespace std;
const int maxn = 11;
// p 为当前排列，hash_table 记录数字是否已经在排列中
int p[maxn] = {0};
int hash_table[maxn] = {false};

int n = 3;

// 分解为 index ~ n 的排列
void gen_p(int index)
{
    // 分界条件，说明已经排列完成
    if(index == n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d", p[i]);
        }
        printf("\n");
        return;
    }
    // 在 index 位枚举可能的数字 有点像图深度遍历，同时要保证字典序
    for(int i = 1; i <= n; i++)
    {
        // i 没有进过排列
        if(!hash_table[i])
        {
            hash_table[i] = true;
            p[index] = i; //进排列
            gen_p(index + 1);
            hash_table[i] = false; //? 想一下 1 2 3  1 3 2,返回的时候，自己的位的数字就不用了
        }

    }

}


int main()
{
    gen_p(0);
}