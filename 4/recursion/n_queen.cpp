#include <cstdio>
#include <math.h>

using namespace std;

const int maxn      = 11;
int n               = 8;
int count           = 0;

bool hash_table[maxn] = { false }; // 每列选的第几行，下标为列，内容为行
int p[maxn]           = {0}; // 当前 排列

//! 基于全排列的想法，因为 n 皇后要求不同行不同列，那么每列的行号正好是一个排列
//! 回溯法，有些情况已经不需要再递归下去了。
void gen_p(int index)
{
    // 排列结束，判断是否合法 n 皇后
    if(index == n + 1)
    {
        count++;//到这里一定合法
        return;
    }

    for(int x = 1; x <= n; x++) // 枚举行号，当前列号为 index
    {
        // 没放过排列
        if(!hash_table[x])
        {
            bool flag = true;
            // 遍历之前的列是否对角线
            for(int pre = 1; pre < index; pre++)
            {
                // 对角线，非法, x p[pre] 为行号
                if(abs(index - pre) == abs(x - p[pre]))
                {
                    flag = false;
                    break;
                }
            }
            //! 说明通过了，放一个皇后
            if(flag)
            {
                //! 这个忘了，选择行号
                p[index] = x;
                hash_table[x] = true;
                gen_p(index + 1);
                hash_table[x] = false; //用完还回去

            }
        }
    }
}


int main()
{
    gen_p(1);
    printf("%d", count);
}