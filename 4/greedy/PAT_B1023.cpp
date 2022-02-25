#include <cstdio>
#include <algorithm>

//! 最高位 1 - 9 选最小，后头都是 0 - 9 选最小，循环保证

using namespace std;


int main()
{
    int count[10];//下标为数字，内容为剩余个数
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", count + i);
    }
    // 最高位
    for(int i = 1; i < 10; i++)
    {
        if(count[i] > 0)
        {
            count[i]--;
            printf("%d", i);
            break;
        }
    }
    //其余位置，穷举 0 ~ 9 最小
    int j = 0;
    for(int i = 0; i < 10; i++)
    {
        //! 直到把当前最小输出到没有为止
        for(int j = 0; j < count[i]; j++)
        {
            printf("%d", i);
            //! count[i]--; 没有必要了，输出了就当做 count[i]-- 了 不用真的 --
        }
    }
    printf("\n");
}