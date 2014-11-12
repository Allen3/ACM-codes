#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define     MAX_NUM     0x3f3f3f3f

struct Node{
    int level;
    int adjGrid[4]; //0 for up , 1 for left , 2 for right , 3 for down
};  //Node

struct _Trans{
    int val , cat , index;
};  //_Trans

struct _Node{
    int index;
    _Node *next;
    _Node(){
        next = NULL;
    }   //Constructor
};  //_Node

int Z , n , m , T , up_val , ans_cnt;
Node nodes[1000010];
bool vis[1000010];
int  years[100010];
_Node  *links[1100010];
int  s[1000010];
int  ans[100010];

_Trans arr[1100010];

bool arr_cmp(_Trans a , _Trans b){
    return (a.val < b.val);
}   //arr_cmp

void discretization(Node nodes[] , int years[]){
    int cnt = 0;
    for (int i = 0;i < n * m;i ++){
        arr[cnt].val = nodes[i].level;
        arr[cnt].cat = 1;
        arr[cnt].index = i;
        cnt ++;
    }   //for i _ n * m

    for (int i = 0;i < T;i ++){
        arr[cnt].val = years[i];
        arr[cnt].cat = 2;
        arr[cnt].index = i;
        cnt ++;
    }   //for i _ T

    sort(arr , arr + cnt , arr_cmp);

    up_val = 0;
    int num = - MAX_NUM;
    for (int i = 0;i < cnt;i ++){
        if (arr[i].val != num)
            up_val ++;
        num = arr[i].val;
        if (arr[i].cat == 1)
            nodes[arr[i].index].level = up_val;
        else
            years[arr[i].index] = up_val;
    }   //for i _ cnt
}   //discretization

void preprocess(){
    for (int i = 0;i < n * m;i ++){
        _Node * p = new _Node;
        p->index = i;
        if (!links[nodes[i].level])
            links[nodes[i].level] = p;
        else{
            p->next = links[nodes[i].level];
            links[nodes[i].level] = p;
        }   //
    }   //for i _ n * m
}   //preprocess

int  setFind(int x){
    if (s[x] > 0)
        return (s[x] = setFind(s[x]));
    return x;
}   //setFind

void setUnion(int setX , int setY){
    if (s[setX] < s[setY]){
        s[setX] += s[setY];
        s[setY] = setX;
    }   //  number of setX bigger
    else{
        s[setY] += s[setX];
        s[setX] = setY;
    }   //
}   //setUnion

void dye(int index){
    vis[index] = true;
    ans_cnt ++;
    for (int k = 0;k < 4;k ++){
        if (nodes[index].adjGrid[k] >= 0 && vis[nodes[index].adjGrid[k]]){
            int setX = setFind(index);
            int setY = setFind(nodes[index].adjGrid[k]);
            if (setX != setY){
                setUnion(setX , setY);
                ans_cnt --;
            }   //  Union
        }   //  connect
    }   //for k _ 4
}   //dye

void solve(){
    int current_height = up_val;
    years[T] = -1;
    for (int i = T - 1;i >= 0;i --){
        if (years[i] == years[i + 1]){
            ans[i] = ans[i + 1];
            continue;
        }   //  year same

        for (int j = current_height;j > years[i];j --){
            if (links[j]){
                _Node *p = links[j] , *q;
                while (p){
                    dye(p->index);

                    q = p;
                    p = p->next;

                    delete(q);  //  garbage collection
                }   //while
            }   //  height exist
        }   //for j (Reverse)
        current_height = years[i];
        ans[i] = ans_cnt;
    }   //for i _ T (Reverse)
}   //solve

int main(){
    scanf("%d" , &Z);
    while (Z --){
        memset(vis , 0 , sizeof(vis));
        memset(nodes , -1 , sizeof(nodes));
        memset(years , 0 , sizeof(years));
        memset(links , 0 , sizeof(links));
        memset(s , -1 , sizeof(s));
        memset(ans , 0 , sizeof(ans));
        ans_cnt = 0;

        scanf("%d%d" , &n , &m);
        for (int i = 0;i < n;i ++)
            for (int j = 0;j < m;j ++){
                int index = i * m + j;
                scanf("%d" , &nodes[index].level);
                if (i > 0)
                    nodes[index].adjGrid[0] = index - m;
                if (j > 0)
                    nodes[index].adjGrid[1] = index - 1;
                if (j < m - 1)
                    nodes[index].adjGrid[2] = index + 1;
                if (i < n - 1)
                    nodes[index].adjGrid[3] = index + m;
            }   //for i j _ n m

        scanf("%d" , &T);
        for (int i = 0;i < T;i ++){
            scanf("%d" , &years[i]);
        }   //for i _ T

        discretization(nodes , years);
        preprocess();
        solve();

        for (int i = 0;i < T;i ++)
            printf("%d " , ans[i]);
        printf("\n");
    }   //while
    return 0;
}   //main
