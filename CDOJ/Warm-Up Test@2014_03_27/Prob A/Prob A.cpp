#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define     INF         0x3f3f3f3f

struct node{
    int v , w;
    node *next;
};  //node

int T , n , m , s , e , p1 , p2 , K;
node *Edge[100010];
bool vis[100010];
int Que[100010];
int dis[100010];

void add_edge(int u , int v , int w){
    node *p = new node;
    p->v = v;   p->w = w;
    p->next = Edge[u];
    Edge[u] = p;
}   //add_edge

void pre_SPFA(int S){
    memset(vis , 0 , sizeof(vis));
    for (int i = 0;i < n;i ++)
        dis[i] = INF;
    dis[S] = 0; vis[S] = 1; Que[1] = S;

    int head = 0 , tail = 1;
    while (head != tail){
        int u = Que[(++ head) % (n + 1)];
        vis[u] = false;

        if (u == p1) continue;

        node *p = Edge[u];
        while (p){
            if (dis[u] + p->w < dis[p->v]){
                dis[p->v] = dis[u] + p->w;
                if (!vis[p->v]){
                    vis[p->v] = 1;
                    Que[(++ tail) % (n + 1)] = p->v;
                }   //  add v to Que
            }   //  Able to be slacked
            p = p->next;
        }   //while p
    }   //while
}   //pre_SPFA

int SPFA(int dis_p2_p1){
    memset(vis , 0 , sizeof(vis));
    for (int i = 0;i < n;i ++)
        dis[i] = INF;
    dis[s] = 0; vis[s] = 1; Que[1] = s;

    int head = 0 , tail = 1;
    while (head != tail){
        int u = Que[(++ head) % (n + 1)];
        vis[u] = false;

        node *p = Edge[u];
        while (p){
            if (p->v == p1){
                if (dis[u] + p->w + K * dis_p2_p1 < dis[p->v]){
                    dis[p->v] = dis[u] + p->w + K * dis_p2_p1;
                    if (!vis[p->v]){
                        vis[p->v] = 1;
                        Que[(++ tail) % (n + 1)] = p->v;
                    }   //add v to Que
                }   //  Able to be slacked
            }   //if v == p1
            else{
                if (dis[u] + p->w < dis[p->v]){
                    dis[p->v] = dis[u] + p->w;
                    if (!vis[p->v]){
                        vis[p->v] = 1;
                        Que[(++ tail) % (n + 1)] = p->v;
                    }   //  add v to Que
                }   //  Able to be slacked
            }
            p = p->next;
        }   //while p
    }   //while
    return dis[e];
}   //SPFA

void solve(int index){
    pre_SPFA(s);
    int dis_s_p1 = dis[p1];
    pre_SPFA(p2);
    int dis_p2_e  = dis[e];
    int dis_p2_p1 = dis[p1];
    int ans_1 = dis_s_p1 + dis_p2_e;
    int ans_2 = SPFA(dis_p2_p1);
    int ans = min(ans_1 , ans_2);
    if (ans >= INF)
        ans = -1;

    printf("Case #%d: %d\n" , index , ans);
}   //solve

int main(){
    scanf("%d" , &T);
    for (int _i = 0;_i < T;_i ++){
        memset(Edge , 0 , sizeof(Edge));

        scanf("%d%d" , &n , &m);
        for (int i = 0;i < m;i ++){
            int u , v , w;
            scanf("%d%d%d" , &u , &v , &w);
            add_edge(u , v , w);
            add_edge(v , u , w);
        }   //for i _ m
        scanf("%d%d%d%d%d" , &s , &e , &p1 , &p2 , &K);
        solve(_i + 1);
    }   //for _i _ T

}   //main
