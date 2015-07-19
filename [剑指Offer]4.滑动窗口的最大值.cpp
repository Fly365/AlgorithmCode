/*---------------------------------------
*   日期：2015-07-19
*   作者：SJF0115
*   题目: 4.滑动窗口的最大值
*   网址：http://www.nowcoder.com/books/coding-interviews/1624bc35a45c42c0bc17d17fa0cba788?rp=3
*   结果：AC
*   来源：LeetCode
*   博客：
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> result;
        int size = nums.size();
        if(size <= 0 || k <= 0){
            return result;
        }//if
        // 双向队列
        deque<int> deque;
        for(int i = 0;i < k-1;++i){
            // 删除小于等于当前元素的值 例如 4 2 1 5
            while(!deque.empty() && nums[i] >= nums[deque.back()]){
                deque.pop_back();
            }//while
            deque.push_back(i);
        }//for
        for(int i = k-1;i < size;++i){
            // 删除小于等于当前元素的值
            while(!deque.empty() && nums[i] >= nums[deque.back()]){
                deque.pop_back();
            }//while
            // 不在滑动窗口之内
            while(!deque.empty() && i - deque.front() >= k){
                deque.pop_front();
            }//while
            deque.push_back(i);
            result.push_back(nums[deque.front()]);
        }//for
        return result;
    }
};

int main(){
    Solution s;
    int k = 3;
    vector<int> vec = {4,1,3};//,-1,-2,-3,5,3,6,7
    vector<int> result = s.maxSlidingWindow(vec,k);
    for(int i = 0;i < result.size();++i){
        cout<<result[i]<<" ";
    }//for
    cout<<endl;
    return 0;
}
