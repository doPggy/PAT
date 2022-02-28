#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 1000;// 顶点个数上限
const int INF  = 0x3fffffff; //设为无穷大

int G[MAXV][MAXV] = {0};
int d[MAXV]       = {0};//! 从起点到某个点的最短距离
bool vis[MAXV] = { false }; //默认没有访问过
int n, m, s; // 点数，边数，起始点编号

int pre[MAXV] = {0}; //pre[v] 记录 v 的前驱节点编号，用于输出最短路径