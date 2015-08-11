/*---------------------------------------
*   日期：2015-08-11
*   作者：SJF0115
*   题目：1002.下一个较大元素
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/11ae41035eef4ed9b354d0752f5abc6f?rp=4&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        vector<int> result;
        if(n <= 0){
            return result;
        }//if
        stack<int> stack;
        stack.push(-1);
        for(int i = n-1;i >= 0;--i){
            int top = stack.top();
            while(top != -1 && A[i] >= top){
                stack.pop();
                top = stack.top();
            }//while
            result.insert(result.begin(),top);
            stack.push(A[i]);
        }//for
        return result;
    }
};

int main() {
    NextElement s;
    //vector<int> vec = {11,13,10,5,12,21,3};
    //vector<int> vec = {1,2,3,4,5,6,7};
    vector<int> vec = {7,12,5,8,11};
    vector<int> result = s.findNext(vec,5);
    for(int i = 0;i < result.size();++i){
        cout<<result[i]<<" ";
    }//for
    cout<<endl;
    return 0;
}
