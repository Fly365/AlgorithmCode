/*---------------------------------------
*   日期：2015-08-16
*   作者：SJF0115
*   题目：1004.整数对查找
*   来源：程序员面试金典
*   
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FindPair {
public:
    int countPairs(vector<int> A, int n, int sum) {
        int size = A.size();
        if(size == 0 || n <= 0){
            return 0;
        }//if
        // 排序
        sort(A.begin(),A.end());
        //
        int count = 0;
        for(int i = 0,j = n - 1;i < j;){
            int s = A[i] + A[j];
            if(s == sum){
                // 3 3 3这种情况
                if(A[i] == A[j]){
                    int x = j-i+1;
                    count += x*(x-1)/2;
                    break;
                }//if
                // 2 2 3 4 4 4这种情况
                else{
                    int k = i+1;
                    while(k <= j && A[i] == A[k]){
                        ++k;
                    }//while
                    int k2 = j-1;
                    while(k2 >= i && A[j] == A[k2]){
                        --k2;
                    }//while
                    count += (k-i)*(j-k2);
                    i = k;
                    j = k2;
                }//else
            }//if
            else if(s < sum){
                ++i;
            }//else
            else{
                --j;
            }//else
        }//for
        return count;
    }
};

int main() {
    FindPair s;
    vector<int> vec = {11,7,7,6,14,2,14,15,2,1,2,12,13,9,8,15,13,8,10,11,14,10,2,9,4,9,3,7,6,10,15,4,7,6,15,3,9,13,5,2,6,10,10,1,12,4,3,3,8,8,1,4,7,11,13,5,13,15,4,3,1,11,6,11,9,9,11,15,12,10,13,3,11,4,8,9,7,3,13,9,11,3,2,11,10,1,4,2,3,3,14,11,5,10,1,14,8,1,11,3,1,9,14,6,1,7,15,10,14,6,4,12,11};
    int n = 113;
    int sum = 16;
    int result = s.countPairs(vec,n,sum);
    cout<<result<<endl;
    return 0;
}
