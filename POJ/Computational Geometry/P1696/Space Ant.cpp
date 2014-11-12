#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define     MAXN                50
#define     MAX_coordinate      100
#define     INF                 999999

class Point
{
    public:
        int index , x , y;
        Point(){}
        Point (int _x , int _y)
        {
            x = _x;     y = _y;
        }   //
        Point operator - (Point p)
        {
            return Point(x - p.x , y - p.y);
        }   //Operator -
        double length()
        {
            return sqrt((double)(x * x + y * y));
        }   //length
};  //Point

int  dot(Point O , Point A , Point B)
{
    Point OA = A - O;
    Point OB = B - O;
    return (OA.x * OB.x + OA.y * OB.y);
}   //dot

int  cross(Point O , Point A , Point B)
{
    Point OA = A - O;
    Point OB = B - O;
    return (OA.x * OB.y - OA.y * OB.x);
}   //cross

int   N , M;
Point arr[MAXN + 5];
int   route[MAXN + 5];
int   cnt;
bool  vis[MAXN + 5];

void print()
{
    printf("%d" , cnt);
    for (int i = 0;i < cnt;i ++)
    {
        printf(" %d" , route[i]);
    }   //for i _ cnt
    printf("\n");
}   //print

void solve(int min_j)
{
    cnt = 0;
    memset(vis , 0 , sizeof(vis));
    route[cnt ++] = arr[min_j].index;   vis[arr[min_j].index] = true;

    Point A(0 , arr[min_j].y);
    Point B(arr[min_j].x , arr[min_j].y);

    int pt , tmp;

    while (true)
    {
        int dir    = INF;
        double length_line = INF;
        double length_dir  = INF;
        bool exist = false;
        bool line  = false;
        pt = min_j;

        for (int i = 0;i < N;i ++)
        {
            if (!vis[arr[i].index])
            {
                tmp = cross(A , B , arr[i]);
                if (tmp == 0 && dot(A , B , arr[i]) > 0)
                {
                    line = true;
                    if (vis[arr[pt].index])
                    {
                        pt = i;
                        continue;
                    }
                    else
                    {
                        if ((arr[i] - B).length() < (arr[pt] - B).length())
                            pt = i;
                    }
                }   //cross() == 0
                else if (tmp > 0)
                {
                    if (line) continue;
                    else
                    {
                        exist = true;
                        if (vis[arr[pt].index])
                        {
                            pt = i;
                            continue;
                        }
                        else
                        {
                            if (cross(B , arr[i] , arr[pt]) > 0)
                                pt = i;
                            else if (cross(B , arr[i] , arr[pt]) == 0)
                            {
                                if ((arr[i] - B).length() > (arr[pt] - B).length())
                                    pt = i;
                            }
                        }
                    }   // not line
                }
            }   // !vis
        }   //for i _ N
        if (!line && !exist)
        {
            print();
            return ;
        }
        else
        {
            vis[arr[pt].index] = true;
            route[cnt ++] = arr[pt].index;
            A = B;
            B.x = arr[pt].x;    B.y = arr[pt].y;
        }   //
    }   //while
}   //solve

int main()
{
    scanf("%d" , &M);
    for (int i = 0;i < M;i ++)
    {
        int min_y = MAX_coordinate + 1 , min_x = MAX_coordinate + 1 , min_j;
        scanf("%d" , &N);
        for (int j = 0;j < N;j ++)
        {
            scanf("%d%d%d" , &arr[j].index , &arr[j].x , &arr[j].y);
            if (arr[j].y < min_y)
            {
                min_y = arr[j].y;
                min_j = j;
            }   //compare y
            else if (arr[j].y == min_y && arr[j].x < min_x)
            {
                min_x = arr[j].x;
                min_j = j;
            }   //compare x when y are same
        }   //for j _ N
        solve(min_j);
    }   //for i _ M

    return 0;
}   //main
