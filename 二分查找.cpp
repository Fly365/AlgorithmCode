/*
1.二分搜索主要解决的问题是确定排序后的数组x[0,n-1]中是否包含目标元素target。
二分搜索通过持续跟踪数组中包含元素target的范围（如果target存在数组中的话）来解决问题。
一开始，这个范围是整个数组，然后通过将target与数组中的中间项进行比较并抛弃一半的范围来缩小范围。该过程持续进行，
直到在数组中找到target或确定包含target的范围为空时为止。在有n个元素的表中，二分搜索大约需要执行lgn次比较操作。

提供充足的时间，竟然只有10%的专业程序员能够将这个程序编写正确。
*/
//正解
/********************************* 
*   日期：2015-01-03 
*   作者：SJF0115 
*   题目: 二分查找算法 
*   博客： http://blog.csdn.net/sunnyyoona/article/details/42364961
*   结果：正解
**********************************/  
#include <iostream>  
using namespace std;  
  
int BinarySearch(int A[], int n, int target) {  
    if(n <= 0){  
        return -1;  
    }//if  
    int start = 0,end = n-1;  
    // 二分查找  
    while(start <= end){  
        // 中间节点  
        int mid = (start + end) / 2;  
        // 找到  
        if(A[mid] == target){  
         return mid;  
        }//if  
        else if(A[mid] > target){  
            end = mid - 1;  
        }//else  
        else{  
            start = mid + 1;  
        }//else  
    }//while  
    return -1;  
}  
  
  
  
int main(){  
    int A[] = {1,2,3,4,7,9,12};  
    cout<<BinarySearch(A,7,9)<<endl;  
    return 0;  
}  


//2.错解一
/*********************************
*   日期：2015-01-03
*   作者：SJF0115
*   题目: 二分查找算法
*   博客：http://blog.csdn.net/sunnyyoona/article/details/42364961
*   结果：错解
**********************************/
#include <iostream>
using namespace std;

int BinarySearch(int A[], int n, int target) {
    if(n <= 0){
        return -1;
    }//if
    int start = 0,end = n-1;
    // 二分查找
    while(start < end){// 错误之处
        // 中间节点
        int mid = (start + end) / 2;
        // 找到
        if(A[mid] == target){
         return mid;
        }//if
        else if(A[mid] > target){
            end = mid - 1;
        }//else
        else{
            start = mid + 1;
        }//else
    }//while
    return -1;
}

int main(){
    int A[] = {1,2,3,4,7,9,12};
    cout<<BinarySearch(A,7,3)<<endl;
    return 0;
}
//主要原因是你搜索的target正好处于start = end处。例如代码中的例子。

//3.错解二
/*********************************
*   日期：2015-01-03
*   作者：SJF0115
*   题目: 二分查找算法
*   博客：http://blog.csdn.net/sunnyyoona/article/details/42364961
*   结果：错解
**********************************/
#include <iostream>
using namespace std;

int BinarySearch(int A[], int n, int target) {
    if(n <= 0){
        return -1;
    }//if
    int start = 0,end = n-1;
    // 二分查找
    while(start <= end){
        // 中间节点
        int mid = (start + end) / 2;
        // 找到
        if(A[mid] == target){
         return mid;
        }//if
        else if(A[mid] > target){
            end = mid; // 可能引起错误之处
        }//else
        else{
            start = mid; // 可能引起错误之处
        }//else
    }//while
    return -1;
}

int main(){
    int A[] = {1,2,3,4,7,9,12};
    cout<<BinarySearch(A,7,12)<<endl;
    return 0;
}


//4.给定一个有序（非降序）数组A，可含有重复元素，求最小的i使得A[i]等于target，不存在则返回-1
/*
此题也就是求target在数组中第一次出现的位置。这里可能会有人想先直接用原始的二分查找，如果不存在直接返回-1，
如果存在，然后再顺序找到这个等于target值区间的最左位置，这样的话，最坏情况下的复杂度就是O（n）了，没有完全发挥出二分查找的优势。
这里的解法具体过程请参考实现代码与注释。
*/
/*********************************
*   日期：2015-01-05
*   作者：SJF0115
*   题目: 给定一个有序（非降序）数组A，可含有重复元素，求最小的i使得A[i]等于target，不存在则返回-1
*   博客：
**********************************/
#include <iostream>
using namespace std;

int BinarySearch(int A[],int n,int target){
    if(n <= 0){
        return -1;
    }//if
    int start = 0,end = n-1;
    // 二分查找变形
    while(start < end){
        int mid = (start + end) / 2;
        if(A[mid] < target){
            start = mid + 1;
        }//if
        else{
            end = mid;
        }//else
    }//while
    // 目标不存在的情况
    // 此时start = end
    if(A[start] != target){
        return -1;
    }//if
    else{
        return start;
    }
}

int main(){
    int A[] = {2,3,4,4,4,4,4,5,6,7,8};
    cout<<BinarySearch(A,11,4)<<endl;
    return 0;
}

//5.输入一个排好序的数组的一个旋转，输出旋转数组的最小元素。
/*
这道题最直观的解法并不难。从头到尾遍历数组一次，就能找出最小的元素，时间复杂度显然是O(N)。
但这个思路没有利用输入数组的特性，我们应该能找到更好的解法。我们注意到旋转之后的数组实际上可以划分为两个排序的子数组，
而且前面的子数组的元素都大于或者等于后面子数组的元素。我们还可以注意到最小的元素刚好是这两个子数组的分界线。
我们试着用二元查找法的思路在寻找这个最小的元素。我们得到处在数组中间的元素。如果该中间元素位于前面的递增子数组，
那么它应该大于或者等于第一个指针指向的元素。此时数组中最小的元素应该位于该中间元素的后面。我们可以把第一指针指向该中间元素，
这样可以缩小寻找的范围。同样，如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指向的元素。
此时该数组中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样同样可以缩小寻找的范围。
我们接着再用更新之后的两个指针，去得到和比较新的中间元素，循环下去。
*/
/*********************************
*   日期：2015-01-04
*   作者：SJF0115
*   题目: 输入一个排好序的数组的一个旋转，输出旋转数组的最小元素
*   博客：
**********************************/
#include <iostream>
using namespace std;

int SearchMin(int A[],int n){
    if(n <= 0){
        return -1;
    }//if
    int start = 0,end = n-1;
    // 数组有序
    if(A[end] > A[start]){
        return A[start];
    }//if
    // 数组旋转
    // 二分查找
    while(start <= end){
        int mid = (start + end) / 2;
        // [start,mid]有序[mid,end]无序
        if(A[mid] > A[start]){
            start = mid;
        }
        // [start,mid]无序[mid,end]有序
        else if(A[mid] < A[start]){
            end = mid;
        }
        else{
            return A[mid+1];
        }
    }//while
}

int main(){
    int A[] = {2,3,4,5,6,7,8};
    cout<<SearchMin(A,7)<<endl;
    return 0;
}

