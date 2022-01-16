#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
//! ，只统计英文字母, 统计时不区分大小写
int hash_table[30] = { 0 }; // 下标为  0 ~ 26 代表英文字母

int main()
{
    string str;
    getline(cin, str);
    int len = str.size();
    for(int i = 0; i < len; i++)
    {
        char c  = str[i];
        int num = 0;
        if('a' <= c && c <= 'z')
        {
            num = c - 'a';
            hash_table[num]++;
        }
        else if('A' <= c && c <= 'Z') 
        {
            num = c - 'A';
            hash_table[num]++;
        }

        // else continue;

        // if(hash_table[num] > max_num) 
        // {
        //     freq_c     = c;
        //     max_num    = hash_table[num];
        // }
    }
    char freq_c = 0;
    int max_num = 0;
    //! 要求输出小写字母，如果有并列，输出字母序小的那个
    //! 正好 hash_table 的下标含义保证了字母序递增
    for(int i = 0; i < 26; i++)
    {
        if(hash_table[i] > max_num)
        {
            freq_c = i + 'a';
            max_num = hash_table[i];
        }
    }
    printf("%c %d\n", freq_c, max_num);
}