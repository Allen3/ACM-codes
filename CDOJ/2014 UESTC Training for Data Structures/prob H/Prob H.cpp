#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std;

#define     MAX_NUM     0x3f3f3f3f
#define     LEN         300010
#define     l_son(x)    (x << 1)
#define     r_son(x)    ((x << 1) + 1)
#define     parent(x)   (x >> 1)

inline void swap(int *x , int *y){
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}   //swap

class MinHeap{
    private:
        int len;
        int arr[LEN];
        void minHeapify(int );
    public:
        MinHeap();
        void insert(int );
        void update(int , int );
        int  pop();
        int  getMin();
        int  getSize();
};  //MinHeap

MinHeap::MinHeap(){
    len = 0;
    memset(arr , 0 , sizeof(arr));
}   //Constructor

void MinHeap::minHeapify(int x){
    int min_ele = x;
    if (l_son(x) <= len && arr[l_son(x)] < arr[min_ele])
        min_ele = l_son(x);
    if (r_son(x) <= len && arr[r_son(x)] < arr[min_ele])
        min_ele = r_son(x);
    if (min_ele != x){
        swap(&arr[x] , &arr[min_ele]);
        minHeapify(min_ele);
    }   //min_ele
}   //minHeapify

void MinHeap::update(int x, int toVal){
    if (toVal > arr[x]){
        arr[x] = toVal;
        minHeapify(x);
    }   //  Down
    else{
        arr[x] = toVal;
        int parent = x >> 1;
        while (parent(x) && arr[x] < arr[parent(x)]){
            swap(&arr[x] , &arr[parent(x)]);
            x = parent(x);
        }   //while
    }   //  Up
}   //update

void MinHeap::insert(int val){
    len ++;
    arr[len] = MAX_NUM;
    update(len , val);
}   //insert

int  MinHeap::pop(){
    if (len == 0)
        return 0;
    int ans = arr[1];
    swap(arr[1] , arr[len]);
    len --;
    minHeapify(1);
    return ans;
}   //pop

int  MinHeap::getMin(){
    return arr[1];
}   //getMin

int  MinHeap::getSize(){
    return len;
}   //getSize

class MaxHeap{
    private:
        int len;
        int arr[LEN];
        void maxHeapify(int );
    public:
        MaxHeap();
        void insert(int );
        void update(int , int );
        int  pop();
        int  getMax();
        int  getSize();
};  //MaxHeap

MaxHeap::MaxHeap(){
    len = 0;
    memset(arr , 0 , sizeof(arr));
}   //MaxHeap

void MaxHeap::maxHeapify(int x){
    int max_ele = x;
    if (l_son(x) <= len && arr[l_son(x)] > arr[max_ele])
        max_ele = l_son(x);
    if (r_son(x) <= len && arr[r_son(x)] > arr[max_ele])
        max_ele = r_son(x);
    if (max_ele != x){
        swap(&arr[x] , &arr[max_ele]);
        maxHeapify(max_ele);
    }   //min_ele
}   //maxHeapify

void MaxHeap::update(int x , int toVal){
    if (toVal < arr[x]){
        arr[x] = toVal;
        maxHeapify(x);
    }   //  Down
    else{
        arr[x] = toVal;
        int parent = x >> 1;
        while (parent(x) && arr[x] > arr[parent(x)]){
            swap(&arr[x] , &arr[parent(x)]);
            x = parent(x);
        }   //while
    }   //  Up
}   //update

void MaxHeap::insert(int val){
    len ++;
    arr[len] = - MAX_NUM;
    update(len , val);
}   //insert

int  MaxHeap::pop(){
    if (len == 0)
        return 0;
    int ans = arr[1];
    swap(arr[1] , arr[len]);
    len --;
    maxHeapify(1);
    return ans;
}   //pop

int  MaxHeap::getMax(){
    return arr[1];
}   //getMax

int  MaxHeap::getSize(){
    return len;
}   //getSize

char str[12];
MinHeap minHeap;
MaxHeap maxHeap;

int stringToNum(char str[]){
    int ans = 0;
    for (int i = 0;i < strlen(str);i ++){
        ans = ans * 10 + str[i] - '0';
    }   //for i _ strlen
    return ans;
}   //stringToNum

int main(){
    while (scanf("%s" , str) != EOF){
        if (str[0] == '#'){
            if (maxHeap.getSize() > minHeap.getSize())
                printf("%d\n" , maxHeap.pop());
            else
                printf("%d\n" , minHeap.pop());
        }   //  package
        else{
            int num = stringToNum(str);
            if (num < maxHeap.getMax()){
                if (maxHeap.getSize() <= minHeap.getSize())
                    maxHeap.insert(num);
                else{
                    minHeap.insert(maxHeap.pop());
                    maxHeap.insert(num);
                }
            }   //  num < maxHeapTop
            else if (maxHeap.getMax() <= num && num <= minHeap.getMin()){
                if (maxHeap.getSize() <= minHeap.getSize())
                    maxHeap.insert(num);
                else
                    minHeap.insert(num);
            }   //  maxHeapTop <= num <= minHeapTop
            else{
                if (minHeap.getSize() <= maxHeap.getSize())
                    minHeap.insert(num);
                else{
                    maxHeap.insert(minHeap.pop());
                    minHeap.insert(num);
                }
            }   //  num > minHeapTop

        }   //  produce to holding area

    }   //while

    return 0;
}   //main
