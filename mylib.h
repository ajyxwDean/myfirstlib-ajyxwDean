#include <bits/stdc++.h>

using namespace std;

#ifndef MYLIB
#define MYLIB

template <class T>

char *str_char_(char* a,int n,string b);
int find_my(int* _START,int* _END,int _TARGET);
int* BiggerNumPlus_my(int* a , int* b);
int log(int a,int n);
int poww(int a, int b);
int strlen(char *str);
void outputdown(int n);
void QuickSort(int *array,int low,int high);
template<class T>
class CNum
{
public:	
	T m_elem;
	CNum(T elem);
	T operator^(CNum &other);
};
 
template <class T>
CNum<T>::CNum(T elem)
{
	m_elem = elem;
}
 
template <class T>
T CNum<T>::operator^(CNum &other)
{
	return (T)pow((double)m_elem, double(other.m_elem));
}
#endif