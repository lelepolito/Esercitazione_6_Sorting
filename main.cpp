#include <iostream>
#include <numeric> 
#include <chrono> 
#include <vector>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace chrono;

vector<unsigned int> CreaVettore(unsigned int size, const string& type) {
    vector<unsigned int> v(size);
    if (type == "ordinato") {
        iota(v.begin(), v.end(), 1);
    }
    else if (type == "inverso") {
        iota(v.rbegin(), v.rend(), 1);
    } 
    else {
        iota(v.begin(), v.end(), 1);
        random_shuffle(v.begin(), v.end());
    }
    return v;
}

int main() {

    const unsigned int size = 420;
    const vector<string> types = {"sorted", "reversed", "random"};
    const unsigned int NUM_SIMULATIONS = 10;

    for (const string& type : types) {
        vector<unsigned int> vec_condiviso = CreaVettore(size, type);
        
        //Measure BubbleSort
        long long bubble_total = 0;
        for (size_t i=0; i < NUM_SIMULATIONS; i++) {
            vector<unsigned int> vec = vec_condiviso;
            auto start = high_resolution_clock::now();
            SortLibrary::BubbleSort(vec);
            auto end = high_resolution_clock::now();
            bubble_total += duration_cast<microseconds>(end - start).count();
        }

        //Measure HeapSort
        long long heap_total = 0;
        for (size_t i=0; i < NUM_SIMULATIONS; i++) {
            vector<unsigned int> vec = vec_condiviso;
            auto start = high_resolution_clock::now();
            SortLibrary::HeapSort(vec, vec.size());
            auto end = high_resolution_clock::now();
            heap_total += duration_cast<microseconds>(end - start).count();
        }

        cout<<"Vector type: "<<type<<endl; 
        cout<<"BubbleSort: "<<bubble_total<<" μs"<<endl;
        cout<< "HeapSort: "<<heap_total<<" μs"<<endl;
 
    }

    return 0;
}