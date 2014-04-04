#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
using namespace std;

#define     INF         9999999
#define     l_son(x)   (x << 1)
#define     r_son(x)   (x << 1) + 1
#define     parent(x)   x >> 1

#define     output      "test.txt"

struct node
{
    int pos , value;
    node *next;
};  //node

const float eps = 1e-2;

node *edge[502];
int  dis[502] , heap[502] , heap_ID[502] , heap_pos[502] , pre[502];
int  n , m , cnt = 0;

void heap_swap(int x , int y)
{
    int tmp = heap[x];
    heap[x] = heap[y];
    heap[y] = tmp;

    tmp = heap_ID[x];
    heap_ID[x] = heap_ID[y];
    heap_ID[y] = tmp;

    heap_pos[heap_ID[x]] = x;
    heap_pos[heap_ID[y]] = y;
}   //heap_swap

void min_heapify(int x)
{
    int min_i = x;
    if (l_son(x) <= heap[0] && heap[l_son(x)] < heap[min_i])
        min_i = l_son(x);
    if (r_son(x) <= heap[0] && heap[r_son(x)] < heap[min_i])
        min_i = r_son(x);
    if (min_i != x)
    {
        heap_swap(min_i , x);
        min_heapify(min_i);
    }
}   //min_heapify

void heap_modify_key(int x , int num)
{
    if (num < heap[x])
    {
        heap[x] = num;
        while (parent(x) > 0 && heap[x] < heap[parent(x)])
        {
            heap_swap(x , parent(x));
            x = parent(x);
        }   //while
    }   //  Up float
    else
    {
        heap[x] = num;
        min_heapify(x);
    }   //  Down float
}   //heap_modify_key

void heap_insert(int u , int num)
{
    heap[0] ++;
    heap[heap[0]] = INF;
    heap_ID[heap[0]] = u; heap_pos[u] = heap[0];
    heap_modify_key(heap[0] , num);
}   //heap_insert

int heap_extract()
{
    int ans = heap_ID[1];
    heap_swap(1 , heap[0]);
    heap[0] --;
    min_heapify(1);
    return ans;
}   //heap_extract

void add_edge(int u , int v , int w)
{
    node *p = new node;
    p->pos = v;  p->value = w; p->next = NULL;
    if (edge[u])
    {
        p->next = edge[u]->next;
        edge[u]->next = p;
    }
    else
        edge[u] = p;
}   //add_edge

void solve()
{
    memset(heap , 0 , sizeof(heap));
    memset(heap_ID , 0 , sizeof(heap_ID));
    memset(heap_pos , 0 , sizeof(heap_pos));
    memset(pre , 0 , sizeof(pre));

    for (int i = 1;i <= n;i ++)
        dis[i] = INF;
    dis[1] = 0;

    for (int i = 1;i <= n;i ++)
        heap_insert(i , dis[i]);

    while (heap[0])
    {
        int pt = heap_extract();

        node *p = edge[pt];
        while (p)
        {
            if (dis[pt] + p->value < dis[p->pos])
            {
                dis[p->pos] = dis[pt] + p->value;
                pre[p->pos] = pt;
                heap_modify_key(heap_pos[p->pos] , dis[p->pos]);
            }
            p = p->next;
        }   //while p

    }   //while     Dijkstra

    int max_i = 0 , max_j = 0;
    for (int i = 1;i <= n;i ++)
        if (dis[i] > dis[max_i])
            max_i = i;

    node *p = edge[max_i];
    float ans = (float)dis[max_i];
    int u , v;
    while (p)
    {
        if (p->pos != pre[max_i])
        {
            float delta = (float)(p->value + dis[p->pos] - dis[max_i]);
            if (delta / 2 + (float)dis[max_i] > ans)
            {
                ans = delta / 2 + (float)dis[max_i];
                u = max_i ; v = p->pos;
            }   //  between 2 points
        }   //
        p = p->next;
    }   //

    if (ans - (float)dis[max_i] > eps)
    {
        if (u > v)
        {
            u = u ^ v; v = u ^ v; u = u ^ v;
        }
        printf("System #%d\n" , cnt);
        printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n" , ans , u , v);
    }   //  between the max_i and max_j
    else
    {
        printf("System #%d\n" , cnt);
        printf("The last domino falls after %.1f seconds, at key domino %d.\n" , ans , max_i);
    }   //
}   //solve

int main()
{
    //freopen(output , "w" , stdout);

    scanf("%d%d" , &n , &m);
    while (!(n == 0 && m == 0))
    {
        cnt ++;
        if (m == 0)
        {
            printf("System #%d\n" , cnt);
            printf("The last domino falls after 0.0 seconds, at key domino 1.\n");
            scanf("%d%d",&n,&m);
            printf("\n");
            continue;
        }   // special situation

        for (int i = 1;i <= n;i ++)
            edge[i] = NULL;

        for (int i = 0;i < m;i ++)
        {
            int u , v , w;
            scanf("%d %d %d" , &u , &v , &w);
            add_edge(u , v , w);
            add_edge(v , u , w);
        }
        solve();
        for (int i = 1;i <= n;i ++)
        {
            node *p = edge[i] , *q;
            while (p)
            {
                q = p->next;
                delete p;
                p = q;
            }   //
        }   //  delete

        scanf("%d%d",&n,&m);
        printf("\n");
    }   //

    return 0;
}   //main
