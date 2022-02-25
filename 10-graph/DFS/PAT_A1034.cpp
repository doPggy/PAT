#include <iostream>
#include <map>
#include <string>


//! 计算连通块的总边权，每个人，也就是点权也要记录
//! 用 DFS 
using namespace std;

const int maxn = 2010;//总人数，记录有 1000，人最多有 2000
const int INF  = 1000000000; // 用于领接矩阵

// 用于姓名和编号绑定
map<int, string> i_2_s;// 编号-> 名字
map<string, int> s_2_i;// 名字-> 编号
map<string, int> gang;// head -> 人数

int G[maxn][maxn] = {0}; // 邻接矩阵，记录边权
int weight[maxn]  = {0}; //点权

int num_person = 0;// 一共有多少个人
int n, k;// 题目输入的总电话数，还有总边权值得阈值

bool vis[maxn] = { false };

// head num_member, total_V 需要计算得到 总边权
void DFS(int now, int & head, int & num_member, int & total_v) // depth = 1
{
    num_member++;
    vis[now] = true;// 已经访问过了
    if(weight[now] > weight[head])// 如果当前的点权更大，就是他为老大
        head = now;
    for(int i = 0; i < num_person; i++)
    {
        if(G[now][i] > 0)//有边权
        {
            total_v += G[now][i];
            G[now][i] = G[i][now] = 0;//!防止重复
            if(!vis[i]) // 没访问过就深度遍历
                DFS(i, head, num_member, total_v);
        }
    }
}


//DFS 遍历整个图，每个连通快，并计算相关的
void DFSTrave()
{
    // 枚举每个点
    for(int i = 0; i < num_person; i++)
    {
        if(!vis[i])
        {
            int head = i, num_member = 0, total_v = 0; // 头目、成员数、总边权
            DFS(i, head, num_member, total_v); 
            if(num_member > 2 && total_v > k)
                // head 代表一个 gang
                gang[i_2_s[head]] = num_member;
        }
    }

}

// 转换
int change(string name)
{
    // 如果已经存在
    if(s_2_i.find(name) != s_2_i.end())
    {
        return s_2_i[name];
    }
    else
    {
        i_2_s[num_person] = name;
        s_2_i[name]       = num_person;
        return num_person++;
    }

}

int main()
{
    string str1, str2;// 用于输入的两个人
    int w; // 通话时长
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> str1 >> str2 >> w;
        // 给每个名字绑上编号
        int id1 = change(str1);
        int id2 = change(str2);
        //! 点权都加上了
        weight[id1] += w; // 点权要加上
        weight[id2] += w; // 点权要加上
        G[id1][id2] += w; // 边权
        G[id2][id1] += w; // 边权
    }
    // 遍历计算了总权值，每个连通块 head 是谁
    DFSTrave();
    cout << gang.size() << endl;
    map<string, int>::iterator it;
    for(it = gang.begin(); it != gang.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}