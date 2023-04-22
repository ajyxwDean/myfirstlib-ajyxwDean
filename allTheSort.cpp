#include <bits/stdc++.h>

using namespace std;

void BubSort(vector<int> &a){     //升序
    int len=a.size();
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(a[j]>a[j+1]){         //比较两者，将较大的交换到后边
                swap(a[j],a[j+1]);
            }
        }
    }
}

void SelectSort(vector<int> &a){    //升序
    int len=a.size();
    int min_index,tmp;
    for(int i=0;i<len-1;i++){
        min_index=i;
        for(int j=i+1;j<len;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }
        tmp=a[i];
        a[i]=a[min_index];
        a[min_index]=tmp;
    }
}

