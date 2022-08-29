#include <bits/stdc++.h>
#include "mylib.h"

using namespace std;

//

void outputdown(int n){
	if(n==0)return;
	cout << n%10;
	outputdown(n/10);
}

int find_my(int* _START,int* _END , int _TARGET){
    int n = _START-_END+1;
    sort(_START,_START+n);
    int mid;
    int l=0,r=_START-_END+1;
    while(l<=r){
        mid = (l+r)/2;
        if(_TARGET<_START[mid]){
            r=mid-1;
        }else if(_TARGET>_START[mid]){
            l=mid+1;
        }else if(_TARGET==_START[mid]){
            return mid;
        }
    }
    return -1;
}

char* str_char_lyfLIB(char* a , int n , string b){
    for(int i = 0 ; i < n ; i++){
        a[i] = b[i];
    }
    return a;
}

int* BiggerNumPlus_my(int* a , int* b , int n){
    int c[1000] = {0};
    reverse(a,a+n);
    reverse(b,b+n);
    int flag=0;
    for (int i = 0; i < n; i++){
        if(flag == 0){
            c[i] = (a[i] + b[i])%10;
            if(c[i] >= 10){
                flag = 1;
            }
        }else if(flag == 1){
            c[i] = (a[i] + b[i])%10+1;
            if(c[i] >= 10){
                flag = 1;
            }
        }
    }
    return c;
}

int log(int a , int n){
    int count=0;
    for(;n <= 1 || n%2 != 0;){
        n/=2;
        count++;
    }
    return count;
}

int poww(int a, int b){
    int k = a;
    for(int i = 0 ; i < b ; i++){
        k *= k;
    }
    return k;
}

int strlen(char *str) { // 堆栈溢出(递归次数过多？)
	if (*(str++) == '\0') {
		return 0;
	}
	return 1+strlen(str++);
}

void QuickSort(int *array,int low,int high){	//快排 
	if(low>=high){	//若待排序序列只有一个元素，返回空 
		return ;
	}
	int i=low;	//i作为指针从左向右扫描 
	int j=high;	//j作为指针从右向左扫描
	int key=array[low];//第一个数作为基准数 
	while(i<j){
		while(array[j]>=key&&i<j){	//从右边找小于基准数的元素 （此处由于j值可能会变，所以仍需判断i是否小于j） 
			j--;	//找不到则j减一 
		}
		array[i]=array[j];	//找到则赋值 
		while(array[i]<=key&&i<j){	//从左边找大于基准数的元素 
			i++;	//找不到则i加一 
		}
		array[j]=array[i];	//找到则赋值 
	}
	array[i]=key;	//当i和j相遇，将基准元素赋值到指针i处 
	QuickSort(array,low,i-1);	//i左边的序列继续递归调用快排 
	QuickSort(array,i+1,high);	//i右边的序列继续递归调用快排 
}

void QuickSort_fastest(int * a,int l,int r){
    int key=a[(l+r)/2];
    int i=l,j=r;
    while(i<=j){
        while(a[i]<key)i++;
        while(a[i]>key)j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++,j--;
        }
    }
    if(j>1)QuickSort_fastest(a,l,j);
    if(i<r)QuickSort_fastest(a,i,r);
}

