<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
int a[100005]={0}; // 初始化待排序的数组 
int temp[100005]={0};
void merge(int ls,int le,int rs,int re){
	int flag = ls; 
	int x=ls; 
	while(ls<=le && rs<=re){
		if(a[ls]<a[rs]) temp[x++]=a[ls++];
		else temp[x++]=a[rs++];
	}
	while(ls<=le) temp[x++]=a[ls++];
	while(rs<=re) temp[x++]=a[rs++];
	for(int i=flag;i<=re;i++) a[i]=temp[i];
}

// 拆分函数
void merge_sort(int l,int r){
    // 如果只有一个元素，就不需要继续划分
	if(l<r){
        // 找中间点
        int mid=(l+r)/2;
        // 递归划分左序列
        merge_sort(l,mid);
        // 递归划分左序列
        merge_sort(mid+1,r);
		// 合并已经排序的部分
        merge(l,mid,mid+1,r);
	}
=======
#include<bits/stdc++.h>
using namespace std;
int a[100005]={0}; // 初始化待排序的数组 
int temp[100005]={0};
void merge(int ls,int le,int rs,int re){
	int flag = ls; 
	int x=ls; 
	while(ls<=le && rs<=re){
		if(a[ls]<a[rs]) temp[x++]=a[ls++];
		else temp[x++]=a[rs++];
	}
	while(ls<=le) temp[x++]=a[ls++];
	while(rs<=re) temp[x++]=a[rs++];
	for(int i=flag;i<=re;i++) a[i]=temp[i];
}

// 拆分函数
void merge_sort(int l,int r){
    // 如果只有一个元素，就不需要继续划分
	if(l<r){
        // 找中间点
        int mid=(l+r)/2;
        // 递归划分左序列
        merge_sort(l,mid);
        // 递归划分左序列
        merge_sort(mid+1,r);
		// 合并已经排序的部分
        merge(l,mid,mid+1,r);
	}
>>>>>>> b94a7582cb8f34520937eb18c02a6205232bbc12
}