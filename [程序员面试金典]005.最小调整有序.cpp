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
