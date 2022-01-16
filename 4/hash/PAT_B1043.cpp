#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

//? 也可以尝试他们的 ASCII 用除留余数法
// 1 - 6 作为记录
int hash_table[7] = {0};
char i_2_c[7] = {-1, 'P', 'A', 'T', 'e', 's', 't'};
int c_2_i[128] = {0};

void init()
{
    for(int i = 1; i <= 6; i++)
    {
        int c    = i_2_c[i];
        c_2_i[c] = i;
    }
}

int PATtest_num = 0; // 有 PATtest 相关字母的个数

int main()
{
    init();
    string str;
    getline(cin, str);
    int len = str.size();
    for(int i = 0; i < len; i++)
    {
        int index = c_2_i[str[i]];
        // 说明不是 PATest 字母
        if(index == 0) continue;
        hash_table[index]++;
        PATtest_num++;
        // if(c == 'P') hash_table[0]++;
        // else if(c == 'A') hash_table[1]++;
        // else if(c == 'T') hash_table[2]++;
        // else if(c == 'e') hash_table[3]++;
        // else if(c == 's') hash_table[4]++;
        // else if(c == 't') hash_table[4]++;
    }

    while(PATtest_num > 0)
    // for(int i = 0; i < PATtest_num; i++)
    {
        //! 这样会漏
        //! int j = i % 6 + 1; // PATest 6 个字母，但 i_2_c 又是从 1 - 6
        for(int i = 1; i <= 6; i++)
        {
            if(hash_table[i] <= 0) continue;
            PATtest_num--;
            hash_table[i]--;
            printf("%c", i_2_c[i]);
        }
    }

    printf("\n");

    // for(int i = 1; i <= 6; i++)
    // {
    //     printf("%c %d ",i_2_c[i], hash_table[i]);
    // }
}