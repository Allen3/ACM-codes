#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define     lowbit(x)       (x & (-x))
#define     LEN             32010

struct Node{
    int x , y;
};  //Node

class BITree{
    private:
        int  arr[LEN];
    public:
        BITree();
        void update(int , int );
        int  query(int );
};  //BITree

BITree::BITree(){
    memset(arr , 0 , sizeof(arr));
}   //BITree

void BITree::update(int index , int val){
    for (int i = index;i <= LEN;i += lowbit(i))
        arr[i] += val;
}   //update

int BITree::query(int index){
    int ans = 0;
    while (index){
        ans += arr[index];
        index -= lowbit(index);
    }   //while
    return ans;
}   //query

int n;
Node arr[100010];
int cnt[100010];
BITree obj;

bool cmp(Node a , Node b){
    if (a.y < b.y)
        return true;
    if (a.y == b.y && a.x < b.x)
        return true;
    return false;
}   //cmp

int main(){
    memset(cnt , 0 , sizeof(cnt));

    scanf("%d" , &n);
    for (int i = 0;i < n;i ++){
        scanf("%d%d" , &arr[i].x , &arr[i].y);
        arr[i].x ++;
        arr[i].y ++;
    }
    sort(arr , arr + n , cmp);

    for (int i = 0;i < n;i ++){
        cnt[obj.query(arr[i].x)] ++;
        obj.update(arr[i].x , 1);
    }   //for i _ n

    for (int i = 0;i < n;i ++)
        printf("%d\n" , cnt[i]);

    return 0;
}   //main
