/*---------------------------------------
*   日期：2015-07-19
*   作者：SJF0115
*   题目: 1.跳台阶
*   网址：http://www.nowcoder.com/books/coding-interviews/8c82a5b80378478f9484d87d1c5f12a4?rp=1
*   结果：AC
*   来源：剑指Offer
*   博客：
-----------------------------------------*/
#include <iostream>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if(number == 1){
            return 1;
        }//if
        else if(number == 2){
            return 2;
        }//else
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};

int main(){
    Solution s;
    int number = 3;
    cout<<s.jumpFloor(number)<<endl;
    return 0;
}


#include <stdio.h>
#include <math.h>

int main()
{
	int n,i,j;
	double Fibonacci[71];
	Fibonacci[0] = 0;
	Fibonacci[1] = 1;
	Fibonacci[2] = 2;
	while(scanf("%d",&n) != EOF){
	    for(int i = 3;i <= n;i++){
	        Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
	    }
	    printf("%.0lf\n",Fibonacci[n]);
	}
	return 0;
}


/*********************************
*   日期：2013-11-15
*   作者：SJF0115
*   题目: 1388：跳台阶
*   来源：http://ac.jobdu.com/problem.php?pid=1388
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
