#include <cstdio>
#include <map>

using namespace std;

// [0, 2^24] 应该是够的
// color -> 出现次数
map<int, int> color;


int main()
{
    int n, m; // n * m
    int c;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &c);
            if(color.find(c) != color.end()) color[c]++;
            else color[c] = 1;
        }
    }

    // 找最多个数的数字
    int k   = 0;
    int MAX = 0;
    for(map<int, int>::iterator it = color.begin(); it != color.end(); it++)
    {
        //! sb 了，color 就是用来统计出现次数的
        if(it->second > MAX)
        {
            k = it->first;
            MAX = it->second;
        }
    }
    //! if(MAX > map.size()) 题目有解，不用判断是否超过半数
    printf("%d\n", k);
}