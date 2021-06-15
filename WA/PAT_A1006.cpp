#include <cstdio>
// https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928

typedef struct Sign
{
    char id[16];
    //! 这是我想的，有丶复杂
    // int in_hh, in_mm, in_ss;
    // int out_hh, out_mm, out_ss;
    int hh, mm, ss;
} S;

S temp, ans_earliest, ans_latest;

// bool is_earlier_than(S s1, S s2)
// {
//     if(s1.in_hh != s2.in_hh) return s1.in_hh <= s2.in_hh;
//     else if(s1.in_mm != s2.in_mm) return s1.in_mm <= s2.in_mm;
//     else if(s1.in_ss != s2.in_ss) return s1.in_ss <= s2.in_ss;

// }

bool is_later_than(S s1, S s2)
{
    if(s1.hh != s2.hh) return s1.hh > s2.hh;
    else if(s1.mm != s2.mm) return s1.mm > s2.mm;
    else if(s1.ss != s2.ss) return s1.ss > s2.ss;
}

// void init()
// {
//     // 最晚走的
//     ans_lock.in_hh = ans_unlock.out_hh = 0;
//     ans_lock.in_mm = ans_unlock.out_mm = 0;
//     ans_lock.in_ss = ans_unlock.out_ss = 0;
    
//     ans_lock.out_hh = 0;
//     ans_lock.out_mm = 0;
//     ans_lock.out_mm = 0;

//     // 最早来的
//     ans_unlock.in_hh = 24;
//     ans_unlock.in_mm = 59;
//     ans_unlock.in_ss = 59;

// }

int main()
{
    //! 分开比较，比较签到，然后又比较签退时间
    int m = 0;
    scanf("%d", &m);
    ans_earliest.hh = 24;
    ans_earliest.mm = 60;
    ans_earliest.ss = 60;

    ans_latest.hh = 0;
    ans_latest.mm = 0;
    ans_latest.ss = 0;
    while(m--)
    {
        // 先比较签到时间
        scanf("%s%d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
        if(is_later_than(ans_earliest, temp))
            ans_earliest = temp;
        
        // 比较签退时间
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if(is_later_than(temp, ans_latest))
            ans_latest = temp;
    }

    printf("%s %s\n", ans_earliest.id, ans_latest.id);
}