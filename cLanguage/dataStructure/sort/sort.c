void swap(int *x, int *y) 
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(int arr[], int length)    //冒泡排序
{
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//源程序参见《C++语言程序设计》（郑莉）p380
void bubble_sort_improve(int arr[], int length) {   
    int i = length - 1;     //i是下一趟需参与排序交换的元素的最大下标
    while (i > 0) {         //继续排序过程，直到最后一趟排序没有交换发生
        int lastExchangeIndex = 0;      //每一趟开始时，设置交换标志为0（未交换）
        int j;
        for (j = 0; j < i; j++) {       //每一趟对元素arr[0]...arr[i]进行比较和交换
            if (arr[j] > arr[j + 1]) {      //如果元素arr[j] > arr[j + 1]，交换之
                swap(&arr[j], &arr[j + 1]);
                lastExchangeIndex = j;      //记录被交换的一对元素中较小的下标
            }   
        }   
        i = lastExchangeIndex;          //将i设置为本趟被交换的最后一对元素中较小的下标
    }   
} 

void select_sort(int arr[], int length)    //选择排序
{
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[j] < arr[i]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

//源程序参见《C++语言程序设计》（郑莉）p379
void selectionSort(int arr[], int length) {       //改进的选择排序
    int i, j, min;
    for (i = 0; i < length - 1; i++) {
        min = i;                                //最小元素的下标初值设为i
        for (j = i + 1; j < length; j++) {      //在元素arr[i+1]...arr[length-1]中逐个比较，选出最小值
            if (arr[j] < arr[min]) {
                min = j;                        //min始终记录当前找到的最小值的下标
            }   
        }   
        swap(&arr[i], &arr[min]);               //将这一趟找到的最小元素与arr[i]交换
    }   
}  

void selectSort(int r[], int n) {  
    int i ,j , min ,max, tmp;  
    for (i = 1; i <= n / 2; i++) {    
        // 做不超过n/2趟选择排序   
        min = i; max = i ; //分别记录最大和最小关键字记录位置  
        for (j = i + 1; j <= n - i; j++) {  
            if (r[j] > r[max]) {   
                max = j ; continue ;   
            }    
            if (r[j]< r[min]) {   
                min = j ;   
            }     
        }    
        //该交换操作还可分情况讨论以提高效率  
        swap(&arr[i - 1], &arr[min]);
        swap(&arr[n - i], &arr[max]);
    }   
}  

/*
 基本思想:
 将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。
 即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。

 直接插入排序的效率分析:
 （1）时间复杂度
 最好:n-1次比较，0次移动 ,时间复杂度为O(n)  
 最差:(n+2)(n-1)/2次比较，(n+4)(n-1)/2次移动，时间复杂度为 O(n^2) 
 时间复杂度：O（n^2）
 （2）空间复杂度
 首先从空间来看，它只需要一个元素的辅助空间，用于元素的位置交换O(1)

 （3）稳定性:
 插入排序是稳定的,因为具有同一值的元素必然插在具有同一值得前一个元素的后面,即相对次序不变.

 （4）结构的复杂性及适用情况
 插入排序是一种简单的排序方法,他不仅适用于顺序存储结构(数组),而且适用于链接存储结构,
 不过在链接存储结构上进行直接插入排序时,不用移动元素的位置,而是修改相应的指针。
 */

//源程序参见《C++语言程序设计》（郑莉）p378
void insertionSort(int arr[], int length)      //直接插入排序
{
    int i;
    for (i = 1; i < length; i++) {              //将下标为1~length-1的元素逐个插入到已排序序列中恰当的位置
        int tmp = arr[i];                       
        int j = i;
        while (j > 0 && tmp < arr[j - 1]) {     //从arr[i-1]开始向a[0]方向扫描各元素，寻找恰当位置插入arr[i]
            arr[j] = arr[j - 1];                //将元素逐个后移，以便找到插入位置时可立即插入
            j--;
        }   
        arr[j] = tmp;
    }   
}

void radix_sort(int arr[], int length);      //基数排序

void quick_sort(int arr[], int length);     //快速排序

void sort(int arr[], int length)
{
    select_sort(arr, length);
}

希尔排序：
第一个突破O(n^2)的排序算法，对直接插入排序的改进
基本思想：
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。

堆排序：
对简单选择排序的改进
时间复杂度为O(nlogn)   
不稳定排序算法  
辅助空间为1  
不适合排序个数较少的序列  



排序算法：
冒泡、选择（堆排序）、快速、基数、插入（希尔）、归并

