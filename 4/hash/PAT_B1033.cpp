#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool hash_table[256] = { false };

int main()
{
    // char broken[256];
    // char str[100010];
    string broken;
    string str;
    // 坏的
    // cin.getline(broken, 128);

    // getchar()
    getline(cin, broken);
    int len_b = broken.size();
    //! 提前转成小写字母 方便处理 
    for(int i = 0; i < len_b; i++)
    {
        if('A' <= broken[i] && broken[i] <= 'Z') broken[i] += 32;
        hash_table[broken[i]] = true;
    }
    // for(int i = 0; i < len_b; i++)
    //     printf("%d", hash_table[broken[i]]);
    // for(int i = 0; i < len_s; i++)
    //     printf("%c", str[i]);

    getline(cin, str);
    int len_s = str.size();
    for(int i = 0; i < len_s; i++)
    {
        char c1 = str[i];
        // 键位坏了，不输出
        //! 这样是 continue 的思路，不能这样
        // if(!hash_table[c1])
        //     printf("%c", str[i]);
        // 大写键坏了，还想输出大写
        //! 题目要求，大写能输出的要求是:字母没坏且大写键没坏
        if('A' <= c1 && c1 <= 'Z')
        {
            char low = c1 + 32;
            if(!hash_table[low] && !hash_table['+'])
                printf("%c", str[i]);
        }
        else if(!hash_table[c1])
            printf("%c", str[i]);
    }
    printf("\n");
}