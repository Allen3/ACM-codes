#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#ifdef unix
#define     LONGLONG_FMT        "%lld"
#else
#define     LONGLONG_FMT        "%I64d"
#endif // unix

#define     LEN     100010

class Segtree{
    private:
        int tail;
        long long seg[LEN << 2] , tag[LEN << 2];
        int left[LEN << 2] , right[LEN << 2] , l_son[LEN << 2] , r_son[LEN << 2];
    public:
        int arr[LEN];

        Segtree();
        void clean(int );
        void build(int , int );
        void update(int , int , int , int );
        long long query(int , int , int );
};  //Segtree

Segtree::Segtree(){
    tail = 0;
    memset(arr , 0 , sizeof(arr));
    memset(seg , 0 , sizeof(seg));
    memset(tag , 0 , sizeof(tag));
    memset(l_son , 0 , sizeof(l_son));
    memset(r_son , 0 , sizeof(r_son));
}   //constructor

void Segtree::clean(int x){
    if (tag[x]){
        seg[x] += tag[x] * (right[x] - left[x] + 1);
        if (l_son[x])   tag[l_son[x]] += tag[x];
        if (r_son[x])   tag[r_son[x]] += tag[x];
        tag[x] = 0;
    }   //  if tag
}   //clean

void Segtree::build(int l , int r){
    int x = ++ tail;
    left[x] = l;    right[x] = r;
    if (l == r){
        seg[x] = arr[l];
        return;
    }   //  leafnode
    int mid = (l + r) >> 1;
    l_son[x] = tail + 1; build(l , mid);
    r_son[x] = tail + 1; build(mid + 1, r);

    clean(l_son[x]);    clean(r_son[x]);
    seg[x] = seg[l_son[x]] + seg[r_son[x]];
}   //build

void Segtree::update(int x , int l , int r , int val){
    clean(x);
    if (l <= left[x] && right[x] <= r){
        tag[x] += val;
        return;
    }   //  tag
    int mid = (left[x] + right[x]) >> 1;
    if (l <= mid) update(l_son[x] , l , r , val);
    if (r >  mid) update(r_son[x] , l , r , val);

    clean(l_son[x]);    clean(r_son[x]);
    seg[x] = seg[l_son[x]] + seg[r_son[x]];
}   //update

long long Segtree::query(int x , int l , int r){
    clean(x);
    if (l <= left[x] && right[x] <= r)
        return seg[x];

    int mid = (left[x] + right[x]) >> 1;
    long long ans = 0;
    if (l <= mid) ans += query(l_son[x] , l , r);
    if (r >  mid) ans += query(r_son[x] , l , r);

    clean(l_son[x]);    clean(r_son[x]);
    seg[x] = seg[l_son[x]] + seg[r_son[x]];

    return ans;
}   //query

Segtree obj;
int n , m;

int main(){
    scanf("%d%d" , &n , &m);
    for (int i = 1;i <= n;i ++)
        scanf("%d" , &obj.arr[i]);
    obj.build(1 , n);

    for (int i = 0;i < m;i ++){
        int cmd;
        scanf("%d" , &cmd);
        if (cmd == 0){
            int l , r;
            scanf("%d%d" , &l , &r);
            printf(LONGLONG_FMT"\n" , obj.query(1 , l , r));
        }   //  query
        else{
            int l , r , w;
            scanf("%d%d%d" , &l , &r , &w);
            obj.update(1 , l , r , w);
        }   //  update
    }   //for i _ m

    return 0;
}   //main
