#include <cstdio>
#include <vector>

using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

void insert(node * &root, int data)
{
    if(root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL; //! 这句漏了, 会不断走下去
        return;
    }
    // if(data == root->data) //! 本题中是会给出相等的节点，不能加这个
    //     return;
    //! data<= 不行
    if(data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void pre_order(node * root, vector<int> &vi)
{
    if(root == NULL)
        return;
    vi.push_back(root->data);
    pre_order(root->left, vi);
    pre_order(root->right, vi);
    return;
}

void pre_m_order(node * root, vector<int> &vi)
{
    if(root == NULL) return;
    vi.push_back(root->data);
    // 镜像树
    pre_m_order(root->right, vi);
    pre_m_order(root->left, vi);
}

void post_order(node * root, vector<int> & vi)
{
    if(root == NULL) return;
    post_order(root->left, vi);
    post_order(root->right, vi);
    vi.push_back(root->data);
}

//! 这个忘记了
void post_m_order(node * root, vector<int> & vi)
{
    if(root == NULL) return;
    post_m_order(root->right, vi);
    post_m_order(root->left, vi);
    vi.push_back(root->data);
}


vector<int> origin, pre, post, preM, postM; // preM, postM 为镜像树的序列
int main()
{
    int n, data;
    scanf("%d", &n);
    // 建树
    node *root = NULL;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }

    // for(int it:origin) printf("%d ", it);
    // printf("\n");

    pre_order(root, pre);
    pre_m_order(root, preM);
    // for(int it:pre) printf("%d ", it);
    // printf("\n");
    if(pre == origin)
    {
        printf("YES\n");
        post_order(root, post);
        int size = post.size();
        for(int i = 0; i < size; i++)
        {
            printf("%d%s", post[i], i != size - 1 ? " " : "\n");
        }
    }
    else if(preM == origin)
    {
        printf("YES\n");
        post_m_order(root, postM);
        int size = postM.size();
        for(int i = 0; i < size; i++)
        {
            printf("%d%s", postM[i], i != size - 1 ? " " : "\n");
        }
    }
    else
    {
        printf("NO\n");
    }
}