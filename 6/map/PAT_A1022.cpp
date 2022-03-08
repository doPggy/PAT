#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <map>

using namespace std;

void query(map<string, set<int>> &mp, string query_word)
{
    //! 忽略了没找到的情况
    if(mp.find(query_word) == mp.end()) printf("Not Found\n");
    else
    {
        for(set<int>::iterator it = mp[query_word].begin(); it != mp[query_word].end(); it++)
        {
            //! 07d
            printf("%07d\n", *it);
        }
    }
}

//!
map<string, set<int>> title_2_id, author_2_id, key_2_id, pub_2_id, year_2_id;
int main()
{
    int n = 0;
    int id;
    char c;
    string title, author, key, pub, year;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &id);
        c = getchar(); //吸收换行，因为后头要接收字符串
        getline(cin, title);
        title_2_id[title].insert(id);
        getline(cin, author);
        author_2_id[author].insert(id);
        //! 输入单词
        while(cin >> key)
        {
            key_2_id[key].insert(id);
            c = getchar(); // 接受回车
            if(c == '\n') break;
        }
        getline(cin, pub);
        pub_2_id[pub].insert(id);
        getline(cin, year);
        year_2_id[year].insert(id);
    }

    int type;
    int k;
    string temp;
    scanf("%d", &k); // query 次数
    for(int i = 0; i < k; i++)
    {
        scanf("%d: ", &type);
        getline(cin, temp);
        cout << type << ": " << temp << endl;
        if(type == 1)
            query(title_2_id, temp);
        else if(type == 2)
            query(author_2_id, temp);
        else if(type == 3)
            query(key_2_id, temp);
        else if(type == 4)
            query(pub_2_id, temp);
        else// 这样更快
            query(year_2_id, temp);
    }
}