#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//!利用 hash 记录需要重复使用的数据
//! 本题是记录是否被覆盖


//! 3n+1 会超过 100
bool be_over[10000] = { false };

bool cmp(int a, int b)
{
    return a > b;
}


int main()
{
    int k;
    int num;
    int be_over_num = 0;
    //! 需要记录输入的值, 否则会使得除了 be over 的数字，其他数都被要输出，明显不对
    int a[110];
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        // 当前输入不会被当做被覆盖
        scanf("%d", a + i);
        num = a[i];
        while(num != 1)
        {
            if(num % 2 == 0)
            {
                num          /= 2;
                be_over[num] = true;
                //! be_over_num++;
            }
            else
            {
                num = (3 * num + 1) / 2;
                be_over[num] = true;
                //! be_over_num++;
            }
        }
    }

    //! int key_num = k - be_over_num; 一个 n 会有不止 k 个的衍生数字, k - be_over_num ≠ key_num
    //! 记录关键数
    int key_num = 0;
    for(int i = 0; i < k; i++)
    {
        num = a[i];
        if(!be_over[num]) //! a[i] 保证了次序
        //! if(!be_over[i])  这个得遍历 be_over 全部，效率低
        {
            // key_num++;
            a[key_num++] = num; // 直接覆盖，重复利用空间
        }
    }

    sort(a, a + key_num, cmp);
    //还要从大到小输出
    for(int i = 0; i < key_num; i++)
    {
        if(i != key_num - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
    printf("\n");
}