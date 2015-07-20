/*---------------------------------------
*   日期：2015-07-20
*   作者：SJF0115
*   题目: 11.斐波那契数列
*   结果：AC
*   网址：http://www.nowcoder.com/books/coding-interviews/c6c7742f5ba7442aada113136ddea0c3?rp=1
*   来源：剑指Offer
*   博客：
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int a = 1;
        int b = 1;
        if(n <= 0){
            return 0;
        }//if
        if(n == 1 || n == 2){
            return 1;
        }//if
        int num;
        for(int i = 3;i <= n;++i){
            num = a + b;
            a = b;
            b = num;
        }//for
        return num;
    }
};

int main(){
    Solution s;
    int n;
    while(cin>>n){
        int result = s.Fibonacci(n);
        // 输出
        cout<<result<<endl;
    }//while
    return 0;
}


// 代码二

/*********************************
*   日期：2013-11-15
*   作者：SJF0115
*   题号: 题目1387：斐波那契数列
*   来源：http://ac.jobdu.com/problem.php?pid=1387
*   结果：AC
*   来源：剑指Offer
*   总结：
**********************************/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
//斐波那契数列F(n)
long long  Fibonacci(int n){
    int i;
    long long fibonacciA = 0;
    long long fibonacciB = 1;
    long long fibonacciC;
    if(n == 0){
        return fibonacciA;
    }
    else if(n == 1){
        return fibonacciB;
    }
    for(i = 2;i <= n;i++){
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

// 代码三
#include <stdio.h>
#include <math.h>

int main()
{
	int n,i,j;
	double Fibonacci[71];
	Fibonacci[0] = 0;
	Fibonacci[1] = 1;
	while(scanf("%d",&n) != EOF){
	    for(int i = 2;i <= n;i++){
	        Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
	    }
	    printf("%.0lf\n",Fibonacci[n]);
	}
	return 0;
}
