#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define     INF         0x3f3f3f3f
#define     input       "test.txt"

struct node
{
    int v , w;
    node *next;
};  //node

int n;
int dis[101] , Que[101];
bool vis[101];
node *Edge_List[101];

void add_edge(int u , int v , int w)
{
    node *p =  new node;

    p->v = v; p->w = w;
    p->next = Edge_List[u];
    Edge_List[u] = p;
}   //add_edge

void solve()
{
    memset(vis , 0 , sizeof(vis));
    for (int i = 1;i < n ;i ++)
        dis[i] = INF;
    dis[0] = 0; vis[0] = 1; Que[1] = 0;

    int head = 0 , tail = 1;
    while (head != tail)
    {
        int u = Que[(++ head) % (n + 1)];
        vis[u] = false;

        node *p = Edge_List[u];
        while (p)
        {
            if (dis[u] + p->w < dis[p->v])
            {
                dis[p->v] = dis[u] + p->w;
                if (!vis[p->v])
                {
                    vis[p->v] = 1;
                    Que[(++ tail) % (n + 1)] = p->v;
                }   //  add v to Que
            }   //  Able to be slacked
            p = p->next;
        }   //while p
    }   //while

    int ans = -1;
    for (int i = 0;i < n;i ++)
        if (dis[i] > ans)
            ans = dis[i];
    printf("%d\n" , ans);
}   //solve

int main()
{
    freopen(input , "r" , stdin);

    char ch;
    scanf("%d%c" , &n , &ch);
    for (int i = 0;i < n;i ++)
        Edge_List[i] = NULL;

    int num = 0 , u = 1 , v = 0;
    bool flag = true;
    while (scanf("%c" , &ch) != EOF)
    {
        if (ch == 'x')
        {
            flag = false;
        }   //INF
        if (ch >= '0' && ch <= '9')
            num = num * 10 + (ch - '0');
        if (ch == ' ')
        {
            if (flag)
            {
                add_edge(u , v , num);
                add_edge(v , u , num);
            }
            v ++;
            num = 0;
            flag = true;
        }
        if (ch == '\n')
        {
            if (flag)
            {
                add_edge(u , v , num);
                add_edge(v , u , num);
            }
            u ++; v = 0;
            num = 0;
            flag = true;
        }
    }   //  read
    solve();

    fclose(stdin);

    return 0;
}   //main
