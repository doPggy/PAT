#include <map>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//0 ~ 12 的火星文
string digit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };

// 乘 13 的火星文，例如 26 = 13 * 2 -> hel
string ten_digit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


string num_2_str[170]; // 0 ~ 169 的都要翻译, 所以把所有数字都打表出来
map<string, int> str_2_num;

void init()
{
    // 高位为 0 或者低位为 0 的初始值
    for(int i = 0; i < 13; i++)
    {
        num_2_str[i]        = digit[i];
        str_2_num[digit[i]] = i;
        num_2_str[i * 13]   = ten_digit[i];
        str_2_num[ten_digit[i]] = i * 13;
    }

    // 个位十位都不为0, 13*13 = 169 所以刚好 13 进制，只有 0 ~ 12
    for(int i = 1; i < 13; i++)
    {
        for(int j = 1; j < 13; j++)
        {
            string str   = ten_digit[i] + " " + digit[j];
            num_2_str[i * 13 + j] = str;
            str_2_num[str] = i * 13 + j;
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d%*c", &n);//吸收回车
    while(n--)
    {
        string input;
        getline(cin, input);
        // 数字
        if(input[0] >= '0' && input[0] <= '9')
        {
            // 手动转换成数字
            int num = 0;
            for(int i = 0; i < input.length(); i++)
            {
                // 想一下 29 怎么搞
                // num += num * 10 + (input[i] - '0'); //! 想复杂了
                num = num * 10 + (input[i] - '0'); //! 想复杂了, 不要 +=！！！
            }
            cout << num_2_str[num] << endl;
            // printf("%s\n", num_2_str[num]);
        }
        // 火星文
        else
        {
            printf("%d\n", str_2_num[input]);
        }
    }
}