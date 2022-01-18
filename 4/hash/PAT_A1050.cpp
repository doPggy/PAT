#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

//! 本题虽然说删除，但其实略过部分字母，打印出来即可
bool need_d[128] = { false };

int main()
{
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    int len1 = s1.size();
    int len2 = s2.size();

    for(int i = 0; i < len2; i++)
        need_d[s2[i]] = true;
    for(int i = 0; i < len1; i++)
    {
        if(!need_d[s1[i]])
            printf("%c", s1[i]);
    }
    printf("\n");
}