#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>   // Controlla che il tipo T sia ordinabile
concept Sortable = requires(T& t) {
    {t < t} -> convertible_to<bool>;
};



template<Sortable T>   
void Scambia(vector<T>& v, unsigned int i, unsigned int j){
	T tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int HeapSinistro(unsigned int i){ 
    return 2*i+1;
}
	
int HeapDestro(unsigned int i){ 
    return 2*i+2;
}



template<Sortable T>
void BubbleSort(vector<T>& v)
{
    const unsigned int n = v.size();
    for(unsigned int i = 0; i <= n - 2; i++){
        for(unsigned int j = i + 1; j <= n-1; j++){
            if(v[j] < v[i]){
                Scambia(v,i,j);
            }
        }
    }
}


template<Sortable T>
void HeapTree(vector<T>& v,size_t n, unsigned int i)
{
    int l = HeapSinistro(i); 
    int r = HeapDestro(i); 
    int Max; 
    if (l<n && v[l]>v[i])
        Max = l;
    else 
        Max = i;
    if(r < n && v[r] > v[Max])
        Max = r;
    if(Max != i){
    	Scambia(v,i,Max);
        HeapTree(v,n,Max); 
    }
}
	
	
template<Sortable T>
void HeapSort(vector<T>& v, size_t n){
	for (int i = n/2 -1 ; i>=0;i--){
        HeapTree(v,n,i);
    }
	for (int i = n - 1; i >= 0; i--){
		Scambia(v,0,i); 
		HeapTree(v, i, 0); 
    }	
}
}



