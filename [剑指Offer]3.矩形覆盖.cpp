/*---------------------------------------------------------------------------
*   日期：2015-07-19
*   作者：SJF0115
*   题目: 3.矩形覆盖
*   网址：http://www.nowcoder.com/books/coding-interviews/72a5a919508a4251859fb2cfb987a0e6?rp=1
*   结果：AC
*   来源：剑指Offer
*   博客：http://blog.csdn.net/sunnyyoona/article/details/14162005
------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class Solution {
public:
    int rectCover(int n){
        if(n < 0){
            return 0;
        }//if
        else if(n == 1 || n == 0){
            return 1;
        }//else
        else if(n == 2){
            return 2;
        }//else
        return rectCover(n-1) + rectCover(n-2);
    }
};

int main(){
    Solution s;
    int number = 4;
    cout<<s.rectCover(number)<<endl;
    return 0;
}


/*********************************
*   日期：2013-11-15
*   作者：SJF0115
*   题号: 题目1390：矩形覆盖
*   来源：http://ac.jobdu.com/problem.php?pid=1390
*   结果：AC
*   来源：剑指Offer
*   总结：
**********************************/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
//F(n) = F(n-1) + F(n-2)
long long  Fibonacci(int n){
    int i;
    long long fibonacciA = 1;
    long long fibonacciB = 2;
    long long fibonacciC;
    if(n == 1){
        return fibonacciA;
    }
    else if(n == 2){
        return fibonacciB;
    }
    for(i = 3;i <= n;i++){
        fibonacciC = fibonacciA + fibonacciB;
        fibonacciA = fibonacciB;
        fibonacciB = fibonacciC;
    }
    return fibonacciC;
}

int main()
{
	int i,n;
	while(scanf("%d",&n) != EOF){
        printf("%lld\n",Fibonacci(n));
	}
    return 0;
}

