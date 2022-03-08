#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int> word_count;

// 判断一个单词，开头要是 0-9 或英文
bool check(char c)
{
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
}

int main()
{
    string str;
    getline(cin, str);
    int i = 0;
    int len = str.length();
    while(i < len)
    {
        //! 个人想法是记录每个单词的 左右下标再 substr 这样的操作，还是复杂了
        string word;
        while(i < len && check(str[i]))
        {
            //! 注意要大写转小写，统一用小写来做单词
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            word += str[i];
            i++;
        }
        //! 有些单词以无效字符开始
        if(word == "") continue;
        if(word_count.find(word) != word_count.end()) word_count[word]++;
        else word_count[word] = 1;
        while(i < len && !check(str[i])) i++; //! 跳过非单词
    }

    string ans;
    int max = 0;
    for(map<string, int>::iterator it = word_count.begin(); it != word_count.end(); it++)
    {
        if(it->second > max)
        {
            max = it->second;
            ans = it->first;
        }
    }
    cout << ans << " " << max << endl;
    //! 可以是可以，但是判断后下标要一直后移的，用 for 不太方便
    // for(i = 0; i < str.length(); i++)
    // {
    //     j = i;
    //     while(check(str[j]))
    //     {
    //     }
    // }
}