#include <iostream>
#include <map>
#include <string>

using namespace std;

const int maxn = 2020; //! 想 2020

// 邻接矩阵
int G[maxn][maxn] = {0};
bool visit[maxn] = {false};

map<string, int> s_2_i;
map<int, string> i_2_s;
map<string, int> gang; // 团火


int n, k;
int num_person = 0;
int weights[maxn] = {0};

int str_2_id(string str)
{
    if(s_2_i.find(str) != s_2_i.end())
    {
        return s_2_i[str];
    }
    else
    {
        s_2_i[str]        = num_person;
        i_2_s[num_person] = str; 
        return num_person++; 
    }

}


void DFS(int now, int &head, int &num_member, int &total_value)
{
    num_member++;
    visit[now] = true;
    if(weights[now] > weights[head])
        head = now;
    //! num_person 统计了有多少人, 而且编号是从小到大的
    for(int i = 0; i < num_person; i++)
    {
        if(G[now][i] != 0)
        {
            //! 没有这一步，考虑一下是不是会又加一次, 用 G[now][i] == 0 判断
            total_value += G[now][i];
            G[now][i] = G[i][now] = 0;
            //! 没访问过才行
            if(!visit[i])
                DFS(i, head, num_member, total_value);
        }
    }
}


void DFSTra()
{
    for(int i = 0; i < n; i++)
    {
        if(!visit[i])//没有访问过的节点
        {
            visit[i] = true;
            int head = i, num_member = 0, total_value = 0;
            // 计算一个连通块中的头目，总边权，和总人数
            DFS(i, head, num_member, total_value);
            if(num_member > 2 && total_value > k)
            {
                gang[i_2_s[head]] = num_member;
            }
        }
    }
}

// 需要名字-id 绑定
int main()
{

    cin >> n >> k;
    string str1, str2;
    int w;
    // 邻接矩阵初始化完毕
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2 >> w;
        int id1 = str_2_id(str1);
        int id2 = str_2_id(str2);
        // 每个人的权值 用于判断老大
        weights[id1] += w;
        weights[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTra();
    cout << gang.size() << endl;
    map<string, int>::iterator it;
    // 遍历所有 gang
    for(it = gang.begin(); it != gang.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}