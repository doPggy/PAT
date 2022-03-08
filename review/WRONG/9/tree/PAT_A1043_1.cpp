#include <cstdio>
#include <vector>


using namespace std;


struct node
{
    int data;
    node *left;
    node *right;
};


vector<int> origin, pre_v, pre_m_v, post_v, post_m_v;


//! 这里都 node * 引用传进来了，还返回干嘛！！！！
void create(node * & root, int data)
{
    if(!root)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        // return root;
        return;
    }

    if(data < root->data)
        create(root->left, data);
    else
        create(root->right, data);
}


void pre(node * root, vector<int> &vi)
{
    if(!root) return;
    vi.push_back(root->data);
    pre(root->left, vi);
    pre(root->right, vi);
}

// 前序遍历镜像树
void pre_m(node *root, vector<int> &vi)
{
    if(!root) return;
    vi.push_back(root->data);
    pre_m(root->right, vi);
    pre_m(root->left, vi);
}


void post(node *root, vector<int> &vi)
{
    if(!root) return;
    post(root->left, vi);
    post(root->right, vi);
    vi.push_back(root->data);
}

void post_m(node *root, vector<int> &vi)
{
    if(!root) return;
    post_m(root->right, vi);
    post_m(root->left, vi);
    vi.push_back(root->data);
}

int main()
{
    int n;
    int data;
    node * root = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        create(root, data);
    }

    pre(root, pre_v);
    pre_m(root, pre_m_v);
    for(int it:pre_v)
        printf("%d ", it);
    if(pre_v == origin)
    {
        printf("YES\n");
        post(root, post_v);
        int sz = post_v.size();
        for(int i = 0; i < sz; i++)
            printf("%d%s", post_v[i], i != sz ? " " : "\n");

    }
    else if(pre_m_v == origin)
    {
        printf("YES\n");
        int sz = post_m_v.size();
        post_m(root, post_m_v);
        for(int i = 0; i < sz; i++)
            printf("%d%s", post_m_v[i], i != sz ? " " : "\n");
    }
    else
    {
        printf("NO\n");
    }
}