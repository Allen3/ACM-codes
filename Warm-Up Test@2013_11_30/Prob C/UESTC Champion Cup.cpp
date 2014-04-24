/*
 *  ID:     Allen_3
 *  Prob:   UESTC Champion Cup
 *  LANG:   C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define    output       "result.txt"

struct _info
{
    char name[20];
    int  points , goal , lose , delta , Rank;
};  //_info

int T , n , m;
_info List[30];

inline int max(int a , int b)
{
    if (a > b)
        return a;
    return b;
}   //max

int get_ID(char *str)
{
    for (int i = 0;i < n;i ++)
        if (strcmp(str , List[i].name) == 0)
            return i;
}   //get_ID

int get_len(int num)
{
    if (num == 0) return 1;
    int ans = 0;
    if (num < 0)
        ans ++;
    while (num)
    {
        ans ++;
        num = num / 10;
    }   //
    return ans;
}   //get_len

bool cmp_points(_info a , _info b)
{
    return (a.points > b.points);
}   //cmp_points

bool cmp_delta(_info a , _info b)
{
    return (a.delta > b.delta);
}   //cmp_delta

bool cmp_goal(_info a , _info b)
{
    return (a.goal > b.goal);
}   //cmp_goal

bool cmp_name(_info a , _info b)
{
    if (strcmp(a.name , b.name) < 0)
        return true;
    return false;
}   //cmp_name

void print()
{
    int max_Rank = 4 , max_name = 6 , max_points = 3 , max_goal = 1 , max_lose = 1 , max_delta = 1;

    for (int i = 0;i < n;i ++)
    {
        int len;
        max_name   = max(max_name , strlen(List[i].name));
        max_points = max(max_points , get_len(List[i].points));
        max_goal   = max(max_goal , get_len(List[i].goal));
        max_lose   = max(max_lose , get_len(List[i].lose));
        max_delta  = max(max_delta , get_len(List[i].delta));
    }

    int sum;
    sum = max_Rank + max_name + max_points + max_goal + max_lose + max_delta + 12 + 5;
    printf("+");
    for (int i = 0;i < sum;i ++)    printf("-");
    printf("+\n");
    //      Row 1

    printf("| Rank |");
    for (int i = 0;i < (max_name - 4) / 2;i ++)     printf(" ");
    printf("Player");
    for (int i = 0;i < (max_name - 3) / 2;i ++)     printf(" ");
    printf("|");
    for (int i = 0;i < (max_points - 1) / 2;i ++)   printf(" ");
    printf("Pts");
    for (int i = 0;i < (max_points ) / 2;i ++)      printf(" ");
    printf("|");
    for (int i = 0;i < (max_goal + 1) / 2;i ++)     printf(" ");
    printf("G");
    for (int i = 0;i < (max_goal + 2) / 2;i ++)     printf(" ");
    printf("|");
    for (int i = 0;i < (max_lose + 1) / 2;i ++)     printf(" ");
    printf("L");
    for (int i = 0;i < (max_lose + 2) / 2;i ++)     printf(" ");
    printf("|");
    for (int i = 0;i < (max_delta + 1) / 2;i ++)    printf(" ");
    printf("D");
    for (int i = 0;i < (max_delta + 2) / 2;i ++)    printf(" ");
    printf("|\n");
    //      Row 2

    for (int i = 0;i < n;i ++)
    {
        printf("|");
        for (int j = 0;j < max_Rank + 2;j ++)           printf("-");
        printf("|");
        for (int j = 0;j < max_name + 2;j ++)           printf("-");
        printf("|");
        for (int j = 0;j < max_points + 2;j ++)         printf("-");
        printf("|");
        for (int j = 0;j < max_goal + 2;j ++)           printf("-");
        printf("|");
        for (int j = 0;j < max_lose + 2;j ++)           printf("-");
        printf("|");
        for (int j = 0;j < max_delta + 2;j ++)          printf("-");
        printf("|\n");

        printf("|");
        for (int j = 0;j < (4 + 2 - get_len(List[i].Rank)) / 2;j ++)     printf(" ");
        printf("%d" , List[i].Rank);
        for (int j = 0;j < (4 + 3 - get_len(List[i].Rank)) / 2;j ++)     printf(" ");
        printf("|");
        for (int j = 0;j < (max_name + 2 - strlen(List[i].name)) / 2;j ++)     printf(" ");
        printf("%s" , List[i].name);
        for (int j = 0;j < (max_name + 3 - strlen(List[i].name)) / 2;j ++)     printf(" ");
        printf("|");
        for (int j = 0;j < (max_points + 2 - get_len(List[i].points)) / 2;j ++)     printf(" ");
        printf("%d" , List[i].points);
        for (int j = 0;j < (max_points + 3 - get_len(List[i].points)) / 2;j ++)     printf(" ");
        printf("|");
        for (int j = 0;j < (max_goal + 2 - get_len(List[i].goal)) / 2;j ++)     printf(" ");
        printf("%d" , List[i].goal);
        for (int j = 0;j < (max_goal + 3 - get_len(List[i].goal)) / 2;j ++)     printf(" ");
        printf("|");
        for (int j = 0;j < (max_lose + 2 - get_len(List[i].lose)) / 2;j ++)     printf(" ");
        printf("%d" , List[i].lose);
        for (int j = 0;j < (max_lose + 3 - get_len(List[i].lose)) / 2;j ++)     printf(" ");
        printf("|");
        for (int j = 0;j < (max_delta + 2 - get_len(List[i].delta)) / 2;j ++)     printf(" ");
        printf("%d" , List[i].delta);
        for (int j = 0;j < (max_delta + 3 - get_len(List[i].delta)) / 2;j ++)     printf(" ");
        printf("|\n");

    }   //  The Players Info

    printf("|");
    for (int j = 0;j < max_Rank + 2;j ++)           printf("-");
    printf("|");
    for (int j = 0;j < max_name + 2;j ++)           printf("-");
    printf("|");
    for (int j = 0;j < max_points + 2;j ++)         printf("-");
    printf("|");
    for (int j = 0;j < max_goal + 2;j ++)           printf("-");
    printf("|");
    for (int j = 0;j < max_lose + 2;j ++)           printf("-");
    printf("|");
    for (int j = 0;j < max_delta + 2;j ++)          printf("-");
    printf("|\n");

    printf("\n");
}   //print

int main()
{
    //freopen(output , "w" , stdout);
    char ch;

    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        memset(List , 0 , sizeof(List));
        scanf("%d%d" , &n , &m);
        scanf("%c" , &ch);           //  read '\n'
        for (int i = 0;i < n;i ++)
        {
            scanf("%s" , List[i].name);
            scanf("%c" , &ch);      //  read '\n'
        }   //for i _ n
        for (int i = 0;i < m;i ++)
        {
            char name_1[20] , name_2[20];
            int  goal_1 , goal_2;
            scanf("%s" , name_1);   scanf("%c" , &ch);
            scanf("%d" , &goal_1);
            scanf("%c%c%c" , &ch , &ch , &ch);
            scanf("%d" , &goal_2);
            scanf("%s" , name_2);

            //deal the data
            int u = get_ID(name_1);
            int v = get_ID(name_2);

            List[u].goal += goal_1;     List[u].lose += goal_2;
            List[v].goal += goal_2;     List[v].lose += goal_1;
            if (goal_1 > goal_2)
                List[u].points += 3;
            else if (goal_1 < goal_2)
                List[v].points += 3;
            else
            {
                List[u].points ++;      List[v].points ++;
            }
        }   //for i _ m

        for (int i = 0;i < n;i ++)
            List[i].delta = List[i].goal - List[i].lose;

        sort(List , List + n , cmp_points);

        int j;
        for (int i = 0;i < n - 1;i += j - i)
        {
            for (j = i + 1;j <= n && List[j].points == List[i].points;j ++) {}
            if (j > n)
                j = n;
            sort(List + i , List + j , cmp_delta);
        }   //for i _ j     delta

        for (int i = 0;i < n - 1;i += j - i)
        {
            for (j = i + 1;j <= n && List[j].points == List[i].points
                                  && List[j].delta  == List[i].delta ;j ++)  {}
            if (j > n)
                j = n;
            sort(List + i , List + j , cmp_goal);
        }   //for i _ j     goal

        //detemine the ranks
        List[0].Rank = 1;
        for (int i = 1;i < n;i ++)
            if (List[i].points == List[i - 1].points
             && List[i].delta  == List[i - 1].delta
             && List[i].goal   == List[i - 1].goal)
                List[i].Rank = List[i - 1].Rank;
            else
                List[i].Rank = i + 1;

        for (int i = 0;i < n - 1;i += j - i)
        {
            for (j = i + 1;j <= n && List[j].points == List[i].points
                                  && List[j].delta  == List[i].delta
                                  && List[j].goal   == List[i].goal  ;j ++)  {}
            if (j > n)
                j = n;
            sort(List + i , List + j , cmp_name);
        }   //for i _ j     name

        print();

    }   //for i _ T

    //fclose(stdout);
    return 0;
}   //main
