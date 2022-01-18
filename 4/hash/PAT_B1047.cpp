#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

// 最多1000个队伍
int team_sum[1010] = {0};
int max_score = -1;
int max_teamer_id = -1;


int main()
{
    int n;
    scanf("%d", &n);
    int team_id;
    int teamer_id;
    int score;

    for(int i = 0; i < n; i++)
    {
        scanf("%d-%d%d", &team_id, &teamer_id, &score);
        team_sum[team_id] += score;
        if(team_sum[team_id] > max_score)
        {
            max_score     = team_sum[team_id];
            max_teamer_id = team_id;
        }
    }
    printf("%d %d\n", max_teamer_id, max_score);
}