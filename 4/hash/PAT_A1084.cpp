#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;




bool hash_table[128] = { false };



int main()
{
    char str1[100];
    char str2[100];
    //! gets PAT 编译器不支持了
    // gets(str1);
    // gets(str2);
    cin.getline(str1, 100);
    cin.getline(str2, 100);
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char c1;
    char c2;
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            c1 = str1[i];
            c2 = str2[j];
            // 转大写
            if('a' <= c1 && c1 <= 'z') c1 -= 32;
            if('a' <= c2 && c2 <= 'z') c2 -= 32;
            if(c1 == c2)
            {
                // hash_table[c1] = true;
                break;
            }
        }
        // hash_table 用于记录是否输出过
        if(c1 != c2 && !hash_table[c1])
        {
            hash_table[c1] = true;
            printf("%c", c1);
        }
    }
    printf("\n");
}