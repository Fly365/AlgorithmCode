/*
二分搜索主要解决的问题是确定排序后的数组x[0,n-1]中是否包含目标元素target。
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


//错解一
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

//错解二
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

