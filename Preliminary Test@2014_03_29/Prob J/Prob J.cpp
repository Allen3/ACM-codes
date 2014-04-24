#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct Point{
    int x , y;
};  //Point

int N;
Point arr[50010];

bool cmp(Point a , Point b){
    if (a.x < b.x) return true;
    else if (a.x == b.y){
        if (a.y < b.y) return true;
        else return false;
    }
    else return false;
}   //cmp

bool isSameLine(Point A , Point B , Point C){
    long long x1 = (long long)(B.x - A.x);
    long long y1 = (long long)(B.y - A.y);
    long long x2 = (long long)(C.x - A.x);
    long long y2 = (long long)(C.y - A.y);
    if (x1 * y2 - y1 * x2 == 0)
        return true;
    return false;
}   //isSameLine

void solve(){
    //sort(arr , arr + N , cmp);

    int flag = -1;
    arr[N].x = arr[0].x;        arr[N].y = arr[0].y;
    arr[N + 1].x = arr[1].x;    arr[N + 1].y = arr[1].y;
    arr[N + 2].x = arr[2].x;    arr[N + 2].y = arr[2].y;

    for (int i = 0;i <= N;i ++){
        if (!isSameLine(arr[i] , arr[i + 1], arr[i + 2]))
            flag = i;
        if (flag >= 0 && i > flag){
            printf("%d %d\n" , arr[flag].x , arr[flag].y);
            return ;
        }
    }   //for i _ N
}   //solve

int main(){
    scanf("%d" , &N);
    for (int i = 0;i < N;i ++){
        scanf("%d%d" , &arr[i].x , &arr[i].y);
    }   //for i _ N
    solve();

    return 0;
}   //main
