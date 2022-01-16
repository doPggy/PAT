#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

//! 不是这么简单了
// int hash_4_shop[256] = {0}; // 下标 ASCII 码，内容为个数
// int hash_4_customer[256] = {0}; // 下标 ASCII 码，内容为个数

int hash_4_shop[80] = {0}; // 下标 ASCII 码，内容为个数
int miss = 0;// 缺的珠子数
//! 0~9 a~z A~Z, 需要映射到 0~9 10~35 36 ~ 61
int hash_(char c)
{
    if('0' <= c && c <= '9') return c - '0';
    if('a' <= c && c <= 'z') return c - 'a' + 10;
    if('A' <= c && c <= 'Z') return c - 'A' + 36;
}


int main()
{
    string shop;
    string customer;
    getline(cin, shop);
    int len1 = shop.size();
    for(int i = 0; i < len1; i++)
        hash_4_shop[hash_(shop[i])]++;
    
    getline(cin, customer);
    int len2 = customer.size();
    //! 等于已有配额，根据需求扣
    for(int i = 0; i < len2; i++)
    {
        int id = hash_(customer[i]);
        hash_4_shop[id]--;
        if(hash_4_shop[id] < 0)
            miss++;
    }
    if(miss > 0)
        printf("No %d", miss);
    else
        printf("Yes %d", len1 - len2);//! 如果足够，两者差就是差多少珠子 len1 >= len2
}