/*-------------------------------------
*   日期：2015-04-24
*   作者：SJF0115
*   题目: 滑动窗口的最大值
*   博客：
------------------------------------*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> SlidingWindowMaximum(vector<int> num,int k){
    vector<int> result;
    int size = num.size();
    if(size <= 0 || k <= 0){
        return result;
    }//if
    // 双向队列
    deque<int> deque;
    for(int i = 0;i < k;++i){
        // 删除小于等于当前元素的值 例如 4 2 1 5
        while(!deque.empty() && num[i] >= num[deque.back()]){
            deque.pop_back();
        }//while
        deque.push_back(i);
    }//for
    for(int i = k;i < size;++i){
        result.push_back(num[deque.front()]);
        // 删除小于等于当前元素的值
        while(!deque.empty() && num[i] >= num[deque.back()]){
            deque.pop_back();
        }//while
        // 不在滑动窗口之内
        while(!deque.empty() && i - deque.front() >= k){
            deque.pop_front();
        }//while
        deque.push_back(i);
    }//for
    result.push_back(num[deque.front()]);
    return result;
}

int main(){
    vector<int> num = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = SlidingWindowMaximum(num,k);
    for(int i = 0;i < result.size();++i){
        cout<<result[i]<<" ";
    }//for
    cout<<endl;
    return 0;
}
