以s1=ABCD为例，我们先分析s1进行循环移位之后的结果：
ABCD->BCDA->CDAB->DABC->ABCD  .......
假设我们把前面移走的数据进行保留：
ABCD->ABCDA->ABCDAB->ABCDABC->ABCDABCD.....
因此看出，对s1做循环移位，所得字符串都将是字符串s1s1的子字符串。如果s2可以由s1循环移位得到，则一定可以在s1s1上。

/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1011.翻转子串
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/bc12808a2b0f445c96a64406d5513e96?rp=1&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        if(size1 == 0 || size2 == 0){
            return false;
        }//if
        string str = s1 + s1;
        if(str.find(s2) == -1){
            return false;
        }//if
        return true;
    }
};

int main() {
    ReverseEqual s;
    string str1("Hello world");
    string str2("worldHello ");
    cout<<s.checkReverseEqual(str1,str2)<<endl;
    return 0;
}
