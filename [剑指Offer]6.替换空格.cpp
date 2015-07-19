/*---------------------------------------
*   日期：2015-07-19
*   作者：SJF0115
*   题目: 6.替换空格
*   结果：AC
*   来源：剑指Offer
*   博客：http://blog.csdn.net/SunnyYoona/article/details/46959311
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    void replaceSpace(char* str,int size) {
        if(str == nullptr || size <= 0){
            return;
        }//if
        // 统计空格个数
        int count = 0;
        for(int i = 0;i < size;++i){
            if(str[i] == ' '){
                ++count;
            }//if
        }//for
        int newSize = size + count * 2;
        if(newSize == size){
            return;
        }//if
        int index = size - 1;
        int i = newSize - 1;
        // 替换空格
        while(index >= 0){
            if(str[index] == ' '){
                str[i--] = '0';
                str[i--] = '2';
                str[i--] = '%';
            }//if
            else{
                str[i--] = str[index];
            }//else
            --index;
        }//while
        str[newSize] = '\0';
    }
};

int main(){
    Solution s;
    char str[100] = "hello world";
    int size = strlen(str);
    s.replaceSpace(str,size);
    cout<<str<<endl;
    return 0;
}
