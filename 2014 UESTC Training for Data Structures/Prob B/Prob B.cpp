#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#ifdef unix
#define     LONGLONG_FMT    "%lld"
#else
#define     LONGLONG_FMT    "%I64d"
#endif // unix

#define     lowbit(x)       x & (-x)

int n , m;
int arr[100010];
long long tree_arr[100010];

long long query(int index){
    long long ans = 0;
    while (index){
        ans += tree_arr[index];
        index -= lowbit(index);
    }   //  while
    return ans;
}   //query

void update(int index , int val){
    arr[index] += val;
    for (int i = index;i <= n;i += lowbit(i))
        tree_arr[i] += val;
}   //update

int main(){
    scanf("%d%d" , &n , &m);
    for (int i = 1;i <= n;i ++){
        scanf("%d" , &arr[i]);
        for (int j = i;j <= n;j += lowbit(j))
            tree_arr[j] += arr[i];
    }

    for (int i = 0;i < m;i ++){
        int cmd;
        scanf("%d" , &cmd);
        if (cmd == 0){
            int l , r;
            scanf("%d%d" , &l , &r);
            long long sum_l = query(l - 1);
            long long sum_r = query(r);
            printf(LONGLONG_FMT"\n" , sum_r - sum_l);
        }   //  query
        else{
            int x , w;
            scanf("%d%d" , &x , &w);
            update(x , w);
        }   //  update
    }   //for i _ m

    return 0;
}   //main
