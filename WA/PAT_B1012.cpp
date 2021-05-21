#include <cstdio>

// https://pintia.cn/problem-sets/994805260223102976/problems/994805311146147840
int main()
{
    int n = 0;
    scanf("%d", &n);

    // 用 count[5] ans[5] 更好一些
    int count[5] = {0};
    int ans[5] = {0};
    int A_1 = 0;
    int A_2 = 0;
    int A_3 = 0;
    int A_4 = 0;
    int A_5 = 0;
    int num = 0;
    int is_neg = 0;
    int A_4_num = 0;
    while(n--)
    {
        scanf("%d", &num);
        if(num % 5 == 0)
        {
            ans[0] += (num % 2 == 0) ? num : 0;
            // 这里易错
            count[0] += (num % 2 == 0) ? 1 : 0;
        }
        else if(num % 5 == 1)
        {
            ans[1] += is_neg ? -num : num;
            is_neg = is_neg ? 0 : 1;
            count[1]++;
        }
        else if(num % 5 == 2)
        {
            count[2]++;
        }
        else if(num % 5 == 3)
        {
            ans[3] += num;
            count[3]++;
        }
        else if(num % 5 == 4 && num > ans[4])
        {
            ans[4] = num;
            count[4]++;
        }
    }

    if(count[0] == 0) printf("N ");
    else printf("%d ",ans[0]);

    if(count[1] == 0) printf("N ");
    else printf("%d ", ans[1]);
    
    if(count[2] == 0) printf("N ");
    else printf("%d ",count[2]);
        
    if(count[3] == 0) printf("N ");
    else printf("%.1f ", (double)ans[3] / count[3]);

    if(count[4] == 0) printf("N");
    else printf("%d", ans[4]);
}