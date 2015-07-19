/*---------------------------------------
*   日期：2015-07-19
*   作者：SJF0115
*   题目: 5.二维数组中的查找
*   网址：http://www.nowcoder.com/books/coding-interviews/abc3fe2ce8e146608e868a70efebf62e?rp=1
*   结果：AC
*   来源：剑指Offer
*   博客：http://blog.csdn.net/SunnyYoona/article/details/46956679
-----------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int row = array.size();
        if(row == 0){
            return false;
        }//if
        int col = array[0].size();
        if(col == 0){
            return false;
        }//if
        int i = 0,j = col - 1;
        while(i < row && j >= 0){
            // 大于目标 剔除这个数字所在的列
            if(array[i][j] > target){
                --j;
            }//if
            // 小于目标 剔除这个数字所在的行
            else if(array[i][j] < target){
                ++i;
            }//else
            else{
                return true;
            }//else
        }//while
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int> > matrix = {
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30}
        };
    int target = 30;
    cout<<s.Find(matrix,target)<<endl;
    return 0;
}
