//
//  main.cpp
//  HeapSort
//
//  Created by kidd on 2018/8/6.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
using namespace std;

void AdjustDown(int arr[], int k, int length){
    arr[0] = arr[k]; // a[0] 用来暂时存放
    for (int i = 2 * k; i < length; i = i * 2) {
        if (i < length && arr[i] < arr[i+1]) {
            i = i + 1; // 从左右子节点中找到最大的一个
        }
        if(arr[0] >= arr[i]){
            break;
        }else{
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
    
}

void BuildMaxHeap(int arr[], int length){
    for (int i = length/2; i > 0; i--) { // 从i = [ n/2 ]~1,反复调整堆
        AdjustDown(arr, i, length);
    }
}

void HeapSort(int arr[], int length){
    BuildMaxHeap(arr, length); // 初始建堆
    for (int i = length; i > 1; i--) { // n-1趟的交换和建堆过程
        swap(arr[i], arr[1]);  // 输出堆顶(将最大的数放到数组的最后一个下标)
        AdjustDown(arr, 1, i-1); // 将剩余的 i-1 个数进行整理成堆
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, HeapSort !\n";
    
    int arr[] = {0,3,67,82,12,45,61,92,33,68,6,3,8,22};
    int length = sizeof(arr)/sizeof(*arr);
    HeapSort(arr, length-1); // 因为第一个位置作为暂时存储，需要减去
    
    for (int i = 1; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}







