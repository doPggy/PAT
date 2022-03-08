#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 100010;

struct Node
{
    char data;
    int  next;
    bool is_s1;
}nodes[maxn];

int s1, s2, n;

int main()
{
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    int addr, next;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &addr, &data, &next);
        //! 这里没有赋值!!!!!
        nodes[addr].next = next;
        nodes[addr].data = data;
    }

    // 遍历 s1， 另一个是 s2
    int p = s1;
    while(p != -1)
    {
        nodes[p].is_s1 = true;
        p = nodes[p].next;
    }

    p = s2;
    while(p != -1)
    {
        if(nodes[p].is_s1) break;
        p = nodes[p].next;
    }

    if(p != -1)
    {
        printf("%05d\n", p); //! 05 格式！！！
    }
    else
    {
        printf("-1\n");
    }
}