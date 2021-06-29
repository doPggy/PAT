#include<cstdio>

int main()
{
    int n = 0;
    char c = 0;
    scanf("%d %c", &n, &c);   

    int col = n;
    int row = (col % 2 == 0) ? col / 2 : (col / 2 + 1); // 四舍五入

    // 第一行
    for(int i = 0; i < col; i++)
        printf("%c", c);
    printf("\n");

    // 2 - row - 1 中空输出
    // 行打出 row - 2 个(已经由第一行和第 row 行了)
    for(int i = 0; i < row - 2; i++)
    {
        printf("%c", c);
        for(int j = 0; j < col - 2; j++)
            printf(" ");
        printf("%c\n", c);
    }
    // 最后一行
    for(int i = 0; i < col; i++)
        printf("%c", c);
    printf("\n");
}