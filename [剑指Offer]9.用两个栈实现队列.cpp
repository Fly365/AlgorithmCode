/*---------------------------------------
*   日期：2015-07-20
*   作者：SJF0115
*   题目: 9.用两个栈实现队列
*   结果：AC
*   网址：http://www.nowcoder.com/books/coding-interviews/54275ddae22f475981afa2244dd448c6?rp=1
*   来源：剑指Offer
*   博客：http://blog.csdn.net/SunnyYoona/article/details/46969519
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            if(stack1.empty()){
                return -1;
            }//if
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }//while
        }//while
        int num = stack2.top();
        stack2.pop();
        return num;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.push(4);
    s.push(5);
    cout<<s.pop()<<endl;
    s.push(6);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}
