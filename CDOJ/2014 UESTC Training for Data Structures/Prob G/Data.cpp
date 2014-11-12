#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

#define     output      "input.txt"
#define     NUM_RANGE   32768

int n = 10 , m;
int arr[20];

int main(){
    freopen(output , "w" , stdout);

    srand(time(NULL));
    m = 1 + (rand() % 100);
    printf("%d %d\n" , n , m);
    for (int i = 0;i < n;i ++)
        printf("%d " , (rand() % NUM_RANGE) - (NUM_RANGE >> 1));
    printf("\n");

    for (int i = 0;i < m;i ++){
        int cmd = rand() % 2;
        if (cmd == 0){
            int l = 1 + (rand() % n);
            int r = 1 + (rand() % n);
            while (l == r)
                r = 1 + (rand() % n);
            if (l > r){
                r = l ^ r;
                l = l ^ r;
                r = l ^ r;
            }
            printf("0 %d %d\n" , l , r);
        }   //  query
        else{
            int x , w;
            x = 1 + (rand() % n);
            w = (rand() % NUM_RANGE) - (NUM_RANGE >> 1);
            printf("1 %d %d\n" , x , w);
        }   //  update

    }   //for i _ m


    return 0;
}   //main
