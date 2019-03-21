
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
template<class Type>
void Split(Type *a,int &left,int &right,int n)///这里是函数的分割，极其关键
{
 int mid=n/2;///中位数
for(left=0;left<n;left++)///进行分割左界限
 {
if(a[left]==a[mid])
 break;
 }
 for(right=left+1;right<n;right++)///进行分割右界限
 {
 if(a[right]!=a[mid])
 break;
}
}
template<class Type>
void Mode(Type *a,int &number,int &MaxTime,int n)///计算众数和重数
{
 int left,right;
 Split(a,left,right,n);///先分割
 int num=n/2; ///第一组的中位数（假设为众数）
 int cnt=right-left;///第一组中位数的个数（重数）
 if(cnt>MaxTime)///进行作比较，每次把最大值进行保留下来
 {
 MaxTime=cnt;
 number=a[num];
 }
 
 if(left+1>MaxTime)///当左边的个数小于中位数的个数时，没有在比较下去的意义
{
Mode(a,number,MaxTime,left+1);
 }
 
 if(n-right>MaxTime)///当右边的个数小于中位数的个数时，没有在比较下去的意义
 {
 Mode(a,number,MaxTime,n-right);
 }
}
 
int main()
{
 int a[] = {1,2,2,2,2,3,5,2,3,5,5,2,2,5,5,2,5,5};
 int n = sizeof(a)/sizeof(a[0]);
 sort(a,a+n);
int MaxTime = 0;
 int number = 0;
 Mode(a,number,MaxTime,n);
 printf("%d %d\n",number,MaxTime);
 return 0;
}

