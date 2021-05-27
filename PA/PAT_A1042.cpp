#include <cstdio>


//! 目前无谓的变量太多了

// char mp[5] = {'S', .....} 更好
char card(int card_num)
{
    if(card_num / 13 == 0) return 'S';
    if(card_num / 13 == 1) return 'H';
    if(card_num / 13 == 2) return 'C';
    if(card_num / 13 == 3) return 'D';
    if(card_num / 13 == 4) return 'J';
}

int main()
{
    int k = 0;
    scanf("%d", &k);
    int cards[54];
    int ans_cards[54];
    int order[54];
    // int order_num = 0;
    for(int i = 0; i < 54; i++)
    { 
        scanf("%d", order + i);
        cards[i] = i;
    }
    // int cur_order = 0;
    int cur_index = 0;
    for(int i = 0; i < 54; i++)
    {
        cur_index = i;
        //! 这里只需要一个不断地变化就行 ，像一个 next
        // cur_order = order[i];
        for(int j = 0; j < k; j++)
        {
            // cur_index =  cur_order - 1;
            cur_index = order[cur_index] - 1;
            // cur_order = order[cur_index];
        }
        ans_cards[cur_index] = cards[i];
    }

    int i = 0;
    for(i = 0; i < 53; i++)
    {
        printf("%c%d ", card(ans_cards[i]), ans_cards[i] % 13 + 1);
    }
    printf("%c%d\n", card(ans_cards[i]), ans_cards[i] % 13 + 1);
    return 0;
}