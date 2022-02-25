#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Node
{
    int id;
    int layer; // 层数，注意层数的理解
};

const int MAXV = 1010;
// 邻接表
vector<Node> adj[MAXV];

bool vis[MAXV] = { false }; // 只能转发一次(只能访问一次)


int BFS(int start_id, int L)
{
    int num_forward = 0;
    queue<Node> q;
    // 定义起始节点
    Node start;
    start.id    = start_id;
    start.layer = 0; // 起始层号为 0
    q.push(start);
    vis[start_id] = true;//! 写成了 start_id
    while(!q.empty())
    {
        Node top_node = q.front();
        q.pop();
        //!vis[top_id] = true 只写在这，双向边的两个节点遍历就有多酸
        int top_id  = top_node.id;
        for(int i = 0; i < adj[top_id].size(); i++)
        {
            Node next      = adj[top_id][i];
            next.layer     = top_node.layer + 1;
            int next_layer = next.layer;
            // 在超过转发层数后，就不统计了
            if(!vis[next.id] && next_layer <= L)
            {
                // 层数 + 1
                // vis[top_id] = true;
                vis[next.id] = true;//! 写成了 start_id
                q.push(next);
                num_forward++;
            }
        }
    }
    return num_forward;
}

int main()
{
    Node user;
    int N, L, user_num, id_follow;
    scanf("%d%d", &N, &L);
    for(int i = 1; i <= N; i++)
    {
        user.id = i;
        scanf("%d", &user_num);
        for(int j = 0; j < user_num; j++)
        {
            scanf("%d", &id_follow);
            //! adj[i] 是错的, 输入的是 i 关注的人，而且是邻接表
            adj[id_follow].push_back(user);
        }
    }
    int num_query = 0;
    int start_id;
    scanf("%d", &num_query);
    for(int i = 0; i < num_query; i++)
    {
        memset(vis, false, sizeof(vis));//! 每一次都要清一次
        scanf("%d", &start_id);
        int num_forward = BFS(start_id, L);
        printf("%d\n", num_forward);
    }
}