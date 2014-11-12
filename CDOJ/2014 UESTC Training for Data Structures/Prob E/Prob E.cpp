#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#ifdef unix
#define     LONGLONG_FMT        "%lld"
#else
#define     LONGLONG_FMT        "%I64d"
#endif // unix

#define     lowbit(x)       (x & (-x))
#define     MAX_NUM         33000

int n;
int arr[50010] , F[50010] , G[50010];
int BITree[MAX_NUM];

void update(int index , int val){
    for (int i = index;i <= MAX_NUM;i += lowbit(i))
        BITree[i] += val;
}   //update

int query(int index){
    int ans = 0;
    while (index){
        ans += BITree[index];
        index -= lowbit(index);
    }   //while
    return ans;
}   //query

void solve(){
    memset(BITree , 0 , sizeof(BITree));
    for (int i = 0;i < n;i ++){
        update(arr[i] , 1);
        F[i] = query(arr[i] - 1);
    }   //for i _ n

    memset(BITree , 0 , sizeof(BITree));
    for (int i = n - 1;i >= 0;i --){
        update(arr[i] , 1);
        G[i] = query(arr[i] - 1);
    }

    long long ans = 0;
    for (int i = 0;i < n;i ++)
        ans += F[i] * G[i];
    printf(LONGLONG_FMT"\n" , ans);
}   //solve

int main(){
    scanf("%d" , &n);
    for (int i = 0;i < n;i ++)
        scanf("%d" , &arr[i]);
    solve();

    return 0;
}   //main
