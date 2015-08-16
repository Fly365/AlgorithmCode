/*---------------------------------------
*   日期：2015-08-16
*   作者：SJF0115
*   题目：1005.最小调整有序
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/091c2f1cf441484f81696f08328b06cd?rp=4&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        vector<int> result;
        int size = A.size();
        if(size == 0 || n <= 0){
            return result;
        }//if
        int left = -1,right;
        // 计算左边起点
        for(int i = 0;i < size - 2;++i){
            int j;
            // 如果A[i]小于等于右边的所有元素则继续否则停止找到左边的起点
            for(j = i + 1;j < size;++j){
                if(A[i] > A[j]){
                    break;
                }//if
            }//for
            if(j != size){
                left = i;
                break;
            }//if
        }//for
        // 有序
        if(left == -1){
            result.push_back(0);
            result.push_back(0);
            return result;
        }//if
        else{
            result.push_back(left);
        }//else
        // 计算右边起点
        for(int i = size - 1;i >= 1;--i){
            int j;
            // 如果A[i]都大于等于左边的元素则继续否则停止找到了右边的起点
            for(j = i - 1;j >= 0;--j){
                if(A[i] < A[j]){
                    break;
                }//if
            }//for
            if(j != -1){
                right = i;
                break;
            }//if
        }//for
        result.push_back(right);
        return result;
    }
};

int main() {
    Rearrange s;
    vector<int> vec = {1,4,6,5,9,10};
    int n = 6;
    vector<int> result = s.findSegment(vec,n);
    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;
    return 0;
}


思路

进行两次遍历，一次从左到右找出N，一次从右到左找出M
（1）从左到右找出N
如果当前元素小于之前的最大元素则说明当前元素应处于[M N]无序序列中而且当前元素是当前最大下标的无序元素所以更新N为当前元素下标。
（2）从右到左找出M
如果当前元素大于之前的最小元素则说明当前元素应处于[M N]无序序列中而且当前元素是当前最小下标的无序元素所以更新M为当前元素下标

代码

/*---------------------------------------
*   日期：2015-08-16
*   作者：SJF0115
*   题目：1005.最小调整有序
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/091c2f1cf441484f81696f08328b06cd?rp=4&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        vector<int> result;
        int size = A.size();
        if(size == 0 || n <= 0){
            return result;
        }//if
        int M = 0,N = 0;
        int max = A[0];
        // 计算[M,N]中的N
        // 如果当前元素小于之前的最大元素则说明当前元素应处于[M N]无序序列中
        // 而且当前元素是当前最大下标的无序元素所以更新N为当前元素下标
        for(int i = 1;i < n;++i) {
            if (A[i] >= max){
                max = A[i];
            }//if
            else{
                N = i;
            }//else
        }//for
        int min = A[n-1];
        // 计算[M,N]中的M
        // 如果当前元素大于之前的最小元素则说明当前元素应处于[M N]无序序列中
        // 而且当前元素是当前最小下标的无序元素所以更新M为当前元素下标
        for(int i = n - 2;i >= 0;--i) {
            if(A[i] <= min){
                min = A[i];
            }//if
            else{
                M = i;
            }//else
        }//for
        result.push_back(M);
        result.push_back(N);
        return result;
    }
};

int main() {
    Rearrange s;
    vector<int> vec = {1,2,157627,5386,16620,6619,139364,303029,303030};
    int n = 9;
    vector<int> result = s.findSegment(vec,n);
    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;
    return 0;
}

