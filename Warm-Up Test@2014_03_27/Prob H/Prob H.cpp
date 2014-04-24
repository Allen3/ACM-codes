#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct node{
    int pt;
    node * next;
};  //node

int T , n , m , p;
node* Edge[100010];
int que[300010];
int keyAtRoom[100010];
bool locked[100010];
bool vis[100010];
bool access[100010];

void add_edge(int u , int v){
    node *p = new node;
    p->pt = v;
    p->next = Edge[u];
    Edge[u] = p;
}   //add_edge

void garbage_Collection(){
    for (int i = 0;i < n;i ++){
        node *p = Edge[i] , *q;
        while (p){
            q = p;
            p = p->next;
            delete q;
        }   //while
    }   //for i _ n
}   //garbage_Collection

void solve(int index){
    memset(vis , 0 , sizeof(vis));
    memset(access , 0 , sizeof(access));

    int head = 0 , tail = 0;
    que[++ tail] = 0;
    access[que[tail]] = 1;

    while (head < tail){
        head ++;

        vis[que[head]] = true;
        if (keyAtRoom[que[head]]){
            locked[keyAtRoom[que[head]]] = false;

            if (access[keyAtRoom[que[head]]]){
                node *p = Edge[keyAtRoom[que[head]]];
                while (p){
                    if (!access[p->pt]){
                        if (!locked[p->pt]){
                            tail ++;
                            que[tail] = p->pt;
                            access[p->pt] = true;
                        }   //  not locked
                    }   //not visited before
                    p = p->next;
                }   //while p
            }   //  Add a expand point
        }   //  Can unlock a door

        node *p = Edge[que[head]];
        while (p){
            if (!access[p->pt]){
                if (!locked[p->pt]){
                    tail ++;
                    que[tail] = p->pt;
                    access[p->pt] = true;
                }   //  not locked
            }   //  not visited before
            p = p->next;
        }   //while p
    }   //while

    for (int i = 0;i < n;i ++)
        if (!vis[i]){
            printf("Case #%d: No\n" , index);
            return ;
        }
    printf("Case #%d: Yes\n" , index);
}   //solve

int main(){
    scanf("%d" , &T);
    int cnt = 1;
    while (T --){
        memset(Edge , 0 , sizeof(Edge));
        memset(keyAtRoom , 0 , sizeof(keyAtRoom));
        memset(locked , 0 , sizeof(locked));

        scanf("%d%d" , &n , &m);
        for (int i = 0;i < m;i ++){
            int u , v;
            scanf("%d%d" , &u , &v);
            add_edge(u , v);
            add_edge(v , u);
        }   //for i _ m

        scanf("%d" , &p);
        for (int i = 0;i < p;i ++){
            int x , y;
            scanf("%d%d" , &x , &y);
            keyAtRoom[y] = x;
            locked[x] = true;
        }   //for i _ p

        solve(cnt);

        garbage_Collection();
        cnt ++;
    }   //while T

    return 0;
}   //main
