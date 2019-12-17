//
// Created by Administrator on 2019/12/17 0017.
//

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void digit_sort(int numbers[], int n, int exp);
int get_max_digits(int numbers[], int n);
void merge(int numbers[], int low, int mid, int high);
void heapify(int numbers[], int n, int i);
void swap(int* i, int* j);
void build_max_heap(int numbers[], int length);
//二分查找返回应插入的位置
int binary_search(int numbers[], int low, int high, int item);
int partition(int numbers[], int low, int high);

void radix_sort(int numbers[], int n) {
    //获取数组中的最大值来确定该数组所有数的位数
    int max_digits = get_max_digits(numbers, n);
    //exp是用于取相应位数时对应的除数
    int exp = 1;
    for (int i = 1; i <= max_digits; i++) {
        digit_sort(numbers, n, exp);
        exp *= 10;
    }
}

void digit_sort(int *numbers, int n, int exp) {
    //取相应个、十、百上位的对应数字
    int digit;
    int temp[10];
    //暂存排序好的数列
    int* out = (int*)malloc(n * sizeof(int));
    //初始化temp[]所有元素为0
    for (int i = 0; i < 10; i++) {
        temp[i] = 0;
    }
    //记录数组中的元素经过桶排序被分配的位置
    int location;
    //用索引表示0-9的位数上的数字，遍历原数组，用temp[]对应索引（0-9）上的值进行累加，类似map，可知相应位数的数字有多少个数
    for (int i = 0; i < n; i++) {
        digit = (numbers[i] / exp) % 10;
        temp[digit] += 1;
    }
    //依次从前往后累加，对数组上的数字确定相应排序的位置
    for (int i = 0; i + 1 < 10; i++) {
        temp[i + 1] = temp[i] + temp[i + 1];
    }
    for (int i = 0; i < n; i++) {
        digit = (numbers[i] / exp) % 10;
        //temp[digit]只是记录元素个数，变为数组索引要减1
        location = temp[digit] - 1;
        out[location] = numbers[i];
        //排序好元素，temp[digit]记录的元素个数减1
        temp[digit]--;
    }
    for (int i = 0; i < n; i++) {
        numbers[i] = out[i];
    }
    free(out);
}

int get_max_digits(int *numbers, int n) {
    int max = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] >= max) {
            max = numbers[i];
        }
    }
    int max_digits = 0;
    for (; max != 0;) {
        max = max / 10;
        max_digits++;
    }
    return max_digits;
}

void merge(int *numbers, int low, int mid, int high) {
    //n1为左侧数列的元素个数
    //为了防止low=mid的特殊情况（n1=mid-low=0），第一个数组的索引从low开始，到mid结束，故n1=mid-low+1
    int n1 = mid - low + 1;
    //n2为右侧数列的元素个数
    //第二个数组的索引从mid+1开始，到high结束
    int n2 = high - mid;
    int* array1 = (int*)malloc(n1 * sizeof(int));
    int* array2 = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        array1[i] = numbers[low + i];
    }
    for (int i = 0; i < n2; i++) {
        array2[i] = numbers[mid + i + 1];
    }

    //平行将两个数列合并排序成一个数列，需要记住
    int i = 0;
    int j = 0;
    int k = low;
    for (; i < n1 && j < n2;) {
        if (array1[i] <= array2[j]) {
            numbers[k] = array1[i];
            k++;
            i++;
        }
        if (array2[j] <= array1[i]) {
            numbers[k] = array2[j];
            k++;
            j++;
        }
    }

    //如果一个数列比另一个数列元素多，则将长的数列中剩余没排序的元素依次安插在numbers的剩余位置中
    for (; i < n1;) {
        numbers[k] = array1[i];
        k++;
        i++;
    }

    //同上
    for (; j < n2;) {
        numbers[k] = array2[j];
        k++;
        j++;
    }
}

void heapify(int *numbers, int n, int i) {
    int left = 2 * i;//按索引从0开始的完全二叉树的父节点与左孩子结点的关系得出左孩子结点的索引
    int right = 2 * i + 1;//同上
    int large = i;
    if (left < n && numbers[large] <= numbers[left]) {
        large = left;
    }
    if (right < n && numbers[large] <= numbers[right]) {
        large = right;
    }
    swap(&numbers[large], &numbers[i]);
}

void swap(int *i, int *j) {
    int temp;
    temp = *j;
    *j = *i;
    *i = temp;
}

void build_max_heap(int *numbers, int length) {
    int i;
    //索引从1开始的完全二叉树的中点为int(n/2)，n为长度，因为数组的索引从0开始，故中点为int(n/2)-1
    //从中点开始依次往前，依次往上对所有点进行遍历
    for (i = length / 2 - 1; i >= 0; i--) {
        heapify(numbers, length, i);
    }
}

int binary_search(int *numbers, int low, int high, int item) {
    int mid;
    if (high <= low) {
        //hign>low，表示low和high指针不断移动到最后，列表中没有可以找到对应的元素
        //没找到对应元素，就比对最后所找的number[mid]即low对应的位置的元素，与item的大小关系，确定item的位置
        if (item > numbers[low]) {
            return low + 1;
        }
        else {
            return low;
        }
    }
    else {
        mid = (low + high) / 2;
        if (item < numbers[mid]) {
            return binary_search(numbers, low, mid - 1, item);
        }
        if (item > numbers[mid]) {
            return binary_search(numbers, mid + 1, high, item);
        }
        if (item == numbers[mid]) {
            return mid + 1;
        }
    }
}

int partition(int *numbers, int low, int high) {
    int i;
    int j = low;
    //从最低的索引（j）开始依次向后寻找比最后的索引的数更小的数，并堆在前面，实际就是将大于最后的数的数和小于最后的数的数分隔开
    for (i = low; i < high; i++) {
        if (numbers[i] <= numbers[high]) {
            //将小于最后的数的数全部堆在前面
            swap(&numbers[i], &numbers[j]);
            j++;
        }
    }
    //将最后的数放在堆在前面比它小的数组成的数列的末尾，有点类似二分查找
    swap(&numbers[j], &numbers[high]);
    return j;
}

void merge_sort(int numbers[], int low, int high) {
    int mid;
    //low<high，确保数列分割到最小后，索引不会溢出
    if (low < high) {
        mid = (low + high) / 2;

        //先分割到最小单位
        merge_sort(numbers, low, mid);
        merge_sort(numbers, mid + 1, high);

        //最后按排序合并
        merge(numbers, low, mid, high);
    }
}


int heap_sort(int numbers[], int n) {
    int j;
    for (j = n - 1; j >= 0; j--) {
        //j+1是为了计算数组长度
        build_max_heap(numbers, j + 1);
        //通过建立max heap，类似冒泡对每个树进行擂台赛，找出最大的数放在整个树的最顶端，然后将最大的数放在整个数列的末尾（用swap进行位置交换）
        //最大的数的位置放在末尾已经确定了，这是再重新对前面的数列排序成max heap找出下一个最大的数
        swap(&numbers[j], &numbers[0]);
    }
}

void selection_sort(int numbers[], int n) {
    int i;
    int j;
    int min_index;//从后面未排序的数列中找出最小的数对应的索引
    //简单选择排序有点类似直接插入排序，不过区别是：直接插入是先选再找位置，简单选择是先找位置再选
    for (i = 0; i < n; i++) {
        min_index = i;
        for (j = i; j < n; j++) {
            //擂台赛找最小的数对应的索引
            if (numbers[min_index] >= numbers[j]) {
                min_index = j;
            }
        }
        //将后面未排序的数列中最小的数插入到前面已排序的数列的末尾
        swap(&numbers[i], &numbers[min_index]);
    }
}

void quick_sort(int numbers[], int low, int high) {
    if (low < high) {
        int pivot = partition(numbers, low, high);//以最后的数为参考点，将前面所有小于这个数的数从low依次往后排列，最后再把最后的数调整到前面依次排列的序列的末尾，类似二分法，返回中心点
        quick_sort(numbers, low, pivot - 1);//将中心点左侧序列重新排列
        quick_sort(numbers, pivot + 1, high);//将中心点右侧序列重新排列
    }
}

void bubble_sort(int numbers[], int n) {
    int i;
    int j;
    int temp;
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j + 1 <= i; j++) {
            //两两相邻比较，前面大于后面，就交换，这个过程类似冒泡
            if (numbers[j] >= numbers[j + 1]) {
                swap(&numbers[j], &numbers[j + 1]);
            }
        }
    }
}

void insertion_sort(int numbers[], int n) {
    int j, temp;
    for (int i = 0; i < n; i++)
    {
        temp = numbers[i];
        for (j = i - 1; j >= 0 && numbers[j] >= temp; j--) {
            numbers[j + 1] = numbers[j];
        }
        numbers[j + 1] = temp;//j+1是为了防止j=-1的情况发生
    }
}

void shell_sort(int numbers[], int n) {
    int gap, temp, first, s;
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        first = gap;
        for (; first < n; first++) {
            //用一个变量暂时存取将要置换位置的数
            temp = numbers[first];
            s = first;
            //s-gap是s将要向左移动的下个位置，如果s-gap<0，则说明s将要移动的位置越过数组索引0，这样也就保证最后找到temp位置的s不会越过数组索引0
            //numbers[s-gap]>=temp保证了s可以寻获到最终停留的位置
            for (; s - gap >= 0 && numbers[s - gap] >= temp;) {
                numbers[s] = numbers[s - gap];//按gap间隔将大于temp也就是numbers[first]的数右移
                s = s - gap;//和直接插入排序类似，因为前部分已经排序好了，找到temp的位置后就没必要再减gap了
            }
            numbers[s] = temp;
        }
    }
}

void binary_insertion_sort(int numbers[], int n) {
    int location;
    int j;
    int temp;
    int k;
    //第1个元素已经作为排序好的数列，可以不管，故i即索引从1开始
    for (int i = 1; i < n; i++) {
        j = i - 1;
        temp = numbers[i];
        //numbers[i]为向前面的已排序好的数列中待插入的元素
        //location为通过二分查找找出numbers[i]对应前面已排序好的数列所插入的位置
        location = binary_search(numbers, 0, j, temp);
        //numbers[i]前的元素右移也要占用numbers[i]的位置，故k从j开始向左遍历
        //将numbers[i]所插入的位置location至最后的元素向右移动，给numbers[i]腾空
        for (k = j; k >= location; k--) {
            numbers[k + 1] = numbers[k];
        }
        numbers[location] = temp;
    }
}