例如：num = 0.625
因为小数点后第一位表示的是0.5，第二位是0.25，第三位是0.125。。。。。。
如果num 大于等于 base = 0.5 则第一位则为1，num 减去0.5 否则为0。无论是不是为1，base都的除以2，以来判断第二位是不是为1，以此类推。。。。


/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1017.二进制小数
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/743853af75fc4026939a682b86535f79?rp=2&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
using namespace std;

class BinDecimal {
public:
    string printBin(double num) {
        string str("0.");
        double base = 0.5;
        while(num > 0){
            if(num >= base){
                num -= base;
                str += "1";
            }//if
            else{
                str += "0";
            }//else
            base /= 2;
            if(str.size() > 32){
                str = "Error";
                break;
            }//if
        }//while
        return str;
    }
};

int main() {
    BinDecimal s;
    double num = 0.46502;
    cout<<s.printBin(num)<<endl;
    return 0;
}
