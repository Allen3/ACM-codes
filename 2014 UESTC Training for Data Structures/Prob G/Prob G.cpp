#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#ifdef unix
#define     LONGLONG_FMT        "%lld"
#else
#define     LONGLONG_FMT        "%I64d"
#endif // unix

#define     LEN         100010
#define     MAX_NUM     0x3f3f3f3f 

inline long long max(long long x , long long y , long long z){
    return max(x , max(y , z));
}   //max

class SegTree{
    private:
        int tail;
        long long seg_sum[LEN << 2] , seg_max[LEN << 2] , seg_max_l[LEN << 2] , seg_max_r[LEN << 2];
        int left[LEN << 2] , right[LEN << 2] , l_son[LEN << 2] , r_son[LEN << 2];
    public:
        int arr[LEN];
        SegTree();
        void build(int , int );
        void update(int , int , int );
        long long query_sum(int , int , int );
        long long query_max(int , int , int );
        long long query_max_l(int , int );
        long long query_max_r(int , int );
};  //SegTree

SegTree::SegTree(){
    tail = 0;

    memset(l_son , 0 , sizeof(l_son));
    memset(r_son , 0 , sizeof(r_son));
    memset(left , 0 , sizeof(left));
    memset(right , 0 , sizeof(right));
}   //Constructor

void SegTree::build(int l , int r){
    tail ++;
    int x = tail;
    left[x] = l;    right[x] = r;
    if (l == r){
        seg_sum[x] = arr[l];
        seg_max[x] = arr[l];
        seg_max_l[x] = arr[l];
        seg_max_r[x] = arr[l];
        return;
    }   //  the leafnode
    int mid = (l + r) >> 1;

    l_son[x] = tail + 1;    build(l , mid);
    r_son[x] = tail + 1;    build(mid + 1 , r);

    seg_sum[x]   = seg_sum[l_son[x]] + seg_sum[r_son[x]];
    seg_max[x]   = max(seg_max_r[l_son[x]] + seg_max_l[r_son[x]] , seg_max[l_son[x]] , seg_max[r_son[x]]);
    seg_max_l[x] = max(seg_max_l[l_son[x]] , seg_max_l[r_son[x]] + seg_sum[l_son[x]]);
    seg_max_r[x] = max(seg_max_r[r_son[x]] , seg_max_r[l_son[x]] + seg_sum[r_son[x]]);
}   //build

void SegTree::update(int x , int index , int val){
    if (left[x] == right[x]){
        seg_sum[x] = val;
        seg_max[x] = val;
        seg_max_l[x] = val;
        seg_max_r[x] = val;
        return;
    }   //  Find it!
    int mid = (left[x] + right[x]) >> 1;
    if (index <= mid)   update(l_son[x] , index , val);
    if (index >  mid)   update(r_son[x] , index , val);

    seg_sum[x]   = seg_sum[l_son[x]] + seg_sum[r_son[x]];
    seg_max[x]   = max(seg_max_r[l_son[x]] + seg_max_l[r_son[x]] , seg_max[l_son[x]] , seg_max[r_son[x]]);
    seg_max_l[x] = max(seg_max_l[l_son[x]] , seg_max_l[r_son[x]] + seg_sum[l_son[x]]);
    seg_max_r[x] = max(seg_max_r[r_son[x]] , seg_max_r[l_son[x]] + seg_sum[r_son[x]]);
}   //update

long long SegTree::query_max(int x , int l , int r){
    if (l <= left[x] && right[x] <= r)
        return seg_max[x];

    int mid = (left[x] + right[x]) >> 1;
    long long tmp = 0 , ans = -MAX_NUM;
    if (l <= mid){
        if (r < mid)
            return query_max(l_son[x] , l , r);

        tmp += query_max_r(l_son[x] , l);
        ans = max(ans , query_max(l_son[x] , l , r));
    }   //l <= mid
    if (r >  mid){
        if (l > mid + 1)
            return query_max(r_son[x] , l , r);

        tmp += query_max_l(r_son[x] , r);
        ans = max(ans , query_max(r_son[x] , l , r));
    }   //r > mid

    ans = max(ans , tmp);

    return ans;
}   //query_max

long long SegTree::query_max_l(int x , int r){
    if (right[x] <= r)
        return seg_max_l[x];

    int mid = (left[x] + right[x]) >> 1;
    long long ans = -MAX_NUM;
    if (r > mid)
        ans = max(ans , query_max_l(r_son[x] , r) + seg_sum[l_son[x]]);

    ans = max(ans , query_max_l(l_son[x] , r));
    return ans;
}   //query_max_l

long long SegTree::query_max_r(int x , int l){
    if (left[x] >= l)
        return seg_max_r[x];

    int mid = (left[x] + right[x]) >> 1;
    long long ans = -MAX_NUM;
    if (l <= mid)
        ans = max(ans , query_max_r(l_son[x] , l) + seg_sum[r_son[x]]);
    
    ans = max(ans , query_max_r(r_son[x] , l));
    return ans;
}   //query_max_r

long long SegTree::query_sum(int x ,int l , int r){
    if (l <= left[x] && right[x] <= r)
        return seg_sum[x];

    int mid = (left[x] + right[x]) >> 1;
    long long ans = 0;
    if (l <= mid)   ans += query_sum(l_son[x] , l , r);
    if (r >  mid)   ans += query_sum(r_son[x] , l , r);

    return ans;
}   //query_sum

SegTree obj;
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
            printf(LONGLONG_FMT"\n" , obj.query_max(1 , l , r));
        }   //  query_max
        else{
            int x , w;
            scanf("%d%d" , &x , &w);
            obj.update(1 , x , w);
        }   //  update
    }   //for i _ m

    return 0;
}   //main
