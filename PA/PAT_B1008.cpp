#include <cstdio>


// https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808
int main()
{
    const int N = 100;
    int nums[N] = {0};
    int n = 0;
    int m = 0;
    int num = 0;

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        nums[i] = num;
    }

    // m = n 时，j = 0
    int j = (n - m % n) % n;
    for(int i = 0; i < n - 1; i++)
    {
        printf("%d ", nums[j]);
        j = (j + 1) % n;
    }
    printf("%d\n", nums[j]);
    return 0;
}