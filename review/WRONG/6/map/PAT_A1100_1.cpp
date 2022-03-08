#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

// 下标为数字，对应相应的火星文
//0 ~ 12 的火星文
string digit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };

// 乘 13 的火星文，例如 26 = 13 * 2 -> hel
string ten_digit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

map<string, int> str_2_num; // 火星文转为数字
string num_2_str[170];

//! 13 进制
void init()
{
    // 个位| 或者个位为 0，但十位非0，也就是 13 倍数
    for(int i = 0; i < 13; i++)
    {
        num_2_str[i]        = digit[i];
        str_2_num[digit[i]] = i;
        num_2_str[i * 13]   = ten_digit[i];
        str_2_num[ten_digit[i]] = i * 13;
    }

    // i 十位，j 个位
    for(int i = 1; i < 13; i++)
    {
        for(int j = 1; j < 13; j++)
        {
            string str = ten_digit[i] + " " + digit[j];
            num_2_str[i * 13 + j] = str;
            str_2_num[str] = i * 13 + j;
        }
    }

}

int main()
{
    init();
    int n;
    //! scanf("%d", &n);
    scanf("%d%*c", &n);//吸收回车
    string str;
    for(int i = 0; i < n; i++)
    {
        getline(cin, str);
        // 数字
        if(str[0] >= '0' && str[0] <= '9')
        {
            int num = 0;
            // 手动转数字
            for(int j = 0; j < str.length(); j++)
                num = num * 10 + (str[j] - '0');
            cout << num_2_str[num] << endl;
        }
        // 火星
        else
        {
            cout << str_2_num[str] << endl;
        }
    }
}