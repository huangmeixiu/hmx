
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
template<class Type>
void Split(Type *a,int &left,int &right,int n)///�����Ǻ����ķָ����ؼ�
{
 int mid=n/2;///��λ��
for(left=0;left<n;left++)///���зָ������
 {
if(a[left]==a[mid])
 break;
 }
 for(right=left+1;right<n;right++)///���зָ��ҽ���
 {
 if(a[right]!=a[mid])
 break;
}
}
template<class Type>
void Mode(Type *a,int &number,int &MaxTime,int n)///��������������
{
 int left,right;
 Split(a,left,right,n);///�ȷָ�
 int num=n/2; ///��һ�����λ��������Ϊ������
 int cnt=right-left;///��һ����λ���ĸ�����������
 if(cnt>MaxTime)///�������Ƚϣ�ÿ�ΰ����ֵ���б�������
 {
 MaxTime=cnt;
 number=a[num];
 }
 
 if(left+1>MaxTime)///����ߵĸ���С����λ���ĸ���ʱ��û���ڱȽ���ȥ������
{
Mode(a,number,MaxTime,left+1);
 }
 
 if(n-right>MaxTime)///���ұߵĸ���С����λ���ĸ���ʱ��û���ڱȽ���ȥ������
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
