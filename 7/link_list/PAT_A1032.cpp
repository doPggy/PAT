#include <cstring>
#include <cstdio>

using namespace std;

const int maxv = 100010;

// 搞静态链表 因为地址范围能确定较小
struct Node
{
    char data;
    int next;
    bool flag; // 在第一个链表出现过就为 true
} nodes[maxv];


void init()
{
    for(int i = 0; i < maxv; i++)
    {
        nodes[i].flag = false;
    }
}

int main()
{
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    // 在区域内构造两条静态链表
    int addr, next_addr;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &addr, &data, &next_addr);
        nodes[addr].data = data;
        nodes[addr].next = next_addr;
    }
    int p = 0;
    for(p = s1; p != -1; p = nodes[p].next) // 遍历第一条链表
        nodes[p].flag = true; //标记第一条链表

    // bool flag = false; 
    for(p = s2; p != -1; p = nodes[p].next)
    {
        // 找到共用的节点
        if(nodes[p].flag)
            break;
    }
    if(nodes[p].flag)
        printf("%05d\n", p);
    else
        printf("-1\n");
}