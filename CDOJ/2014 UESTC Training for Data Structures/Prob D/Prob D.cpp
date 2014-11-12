#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define     N           100010
#define     MAX_NUM     0x3f3f3f3f
#define     LEN         200010

struct _Node{
    int x , y_up , y_down , w;
    bool isIn , once;
};  //_Node

struct Discrete_Node{
    int val , pos;
};  //Discrete_Node

class SegTree{
    private:
        int tail;
        int seg[LEN << 1] , tag[LEN << 1];
        int left[LEN << 1] , right[LEN << 1] , l_son[LEN << 1] , r_son[LEN << 1];
        void clean(int );
    public:
        int arr[LEN << 1];
        SegTree();
        void build(int , int );
        void update(int , int , int , int );
        int  query(int , int , int );
};   //SegTree

SegTree::SegTree(){
    tail = 0;
    memset(arr , 0 , sizeof(arr));
    memset(seg , 0 , sizeof(seg));
    memset(tag , 0 , sizeof(tag));
    memset(left , 0 , sizeof(left));
    memset(right , 0 , sizeof(right));
    memset(l_son , 0 , sizeof(l_son));
    memset(r_son , 0 , sizeof(r_son));
}   //Constructor

void SegTree::clean(int x){
    if (tag[x]){
        seg[x] += tag[x];
        if (l_son[x])   tag[l_son[x]] += tag[x];
        if (r_son[x])   tag[r_son[x]] += tag[x];
        tag[x] = 0;
    }   //tag[x]
}   //clean

void SegTree::build(int l , int r){
    tail ++;
    int x = tail;
    left[x] = l;    right[x] = r;
    if (l == r){
        seg[x] = this->arr[l];
        return;
    }   //  leafnode

    int mid = (l + r) >> 1;
    l_son[x] = tail + 1;    build(l , mid);
    r_son[x] = tail + 1;    build(mid + 1 , r);

    clean(l_son[x]);    clean(r_son[x]);
    seg[x] = max(seg[l_son[x]] , seg[r_son[x]]);
}   //build

void SegTree::update(int x , int l , int r , int val){
    clean(x);
    if (l <= left[x] && right[x] <= r){
        tag[x] += val;
        return;
    }

    int mid = (left[x] + right[x]) >> 1;
    if (l <= mid)    update(l_son[x] , l , r , val);
    if (r >  mid)    update(r_son[x] , l , r , val);

    clean(l_son[x]);    clean(r_son[x]);
    seg[x] = max(seg[l_son[x]] , seg[r_son[x]]);
}   //update

int  SegTree::query(int x , int l , int r){
    clean(x);
    if (l <= left[x] && right[x] <= r)
        return seg[x];

    int mid = (left[x] + right[x]) >> 1;
    int ans = 0;
    if (l <= mid)   ans = max(ans , query(l_son[x] , l , r));
    if (r >  mid)   ans = max(ans , query(r_son[x] , l , r));

    clean(l_son[x]);    clean(r_son[x]);
    seg[x] = max(seg[l_son[x]] , seg[r_son[x]]);

    return ans;
}   //query

int n , W , H;
int cnt_a , cnt_b , ord;
_Node arr[N << 1];
Discrete_Node brr[N << 2];
SegTree obj;

void y_swap(int *a , int *b){
    *b = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
}   //y_swap

bool cmp_x(_Node a , _Node b){
    return (a.x < b.x);
}   //cmp_x

bool cmp_val(Discrete_Node a , Discrete_Node b){
    return (a.val < b.val);
}   //cmp_y

int main(){
    scanf("%d%d%d" , &n , &W , &H);
    cnt_a = 0;
    for (int i = 0;i < n;i ++){
        int xx , yy , ww;
        scanf("%d%d%d" , &xx , &yy , &ww);
        arr[cnt_a].x      = xx;
        arr[cnt_a].y_up   = yy + H;
        arr[cnt_a].y_down = yy;
        arr[cnt_a].w      = ww;
        arr[cnt_a].isIn   = true;
        arr[cnt_a].once   = false;
        cnt_a ++;

        arr[cnt_a].x      = xx + W;
        arr[cnt_a].y_up   = yy + H;
        arr[cnt_a].y_down = yy;
        arr[cnt_a].w      = ww;
        arr[cnt_a].isIn   = false;
        arr[cnt_a].once   = false;
        cnt_a ++;
    }   //for i _ n

    sort(arr , arr + cnt_a , cmp_x);

    cnt_b = 0;
    for (int i = 0;i < cnt_a;i ++){
        brr[cnt_b].val = arr[i].y_up;
        brr[cnt_b].pos = i;
        cnt_b ++;

        brr[cnt_b].val = arr[i].y_down;
        brr[cnt_b].pos = i;
        cnt_b ++;
    }   //  for i _ cnt_a

    sort(brr , brr + cnt_b , cmp_val);

    int num = MAX_NUM;
    ord = 0;
    for (int i = 0;i < cnt_b;i ++){
        if (brr[i].val != num)
            ord ++;
        num = brr[i].val;
        if (!arr[brr[i].pos].once){
            arr[brr[i].pos].y_up = ord;
            arr[brr[i].pos].once = true;
        }
        else
            arr[brr[i].pos].y_down = ord;
    }   //for i _ cnt_b

    int ans = 0;
    obj.build(1 , ord);
    num = arr[0].x;
    for (int i = 0;i < cnt_a;i ++){
        if (num != arr[i].x){
            ans = max(ans , obj.query(1 , 1 , ord));
            num = arr[i].x;
        }   //  x differs

        if (arr[i].y_up < arr[i].y_down)
            y_swap(&arr[i].y_up , &arr[i].y_down);
        int l = arr[i].y_down;
        int r = arr[i].y_up;

        if (arr[i].isIn){
            obj.update(1 , l , r - 1 , arr[i].w);
        }   //  In
        else{
            obj.update(1 , l , r - 1 , -arr[i].w);
        }   //  Out
    }   //for i _ cnt_a
    ans = max(ans , obj.query(1 , 1 , ord));    //the last x

    printf("%d\n" , ans);

    return 0;
}   //main
