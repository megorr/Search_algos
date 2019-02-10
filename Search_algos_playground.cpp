#include <iostream>
#include "Searches.h"

using namespace std;

#define SIZE 300
#define TIMING

#ifdef TIMING //Макрос для измерения времени выполнения участка программы
#define INIT_TIMER auto start = chrono::steady_clock::now();
#define START_TIMER  start = chrono::steady_clock::now();
#define STOP_TIMER(name, time)  time = chrono::duration_cast<chrono::nanoseconds>\
								(chrono::steady_clock::now()-start).count();\
								cout << "RUNTIME of " << name << ": " << \
								time << " ns " << "or " << time/1000000 << "ms" <<endl;\
		
#else
#define INIT_TIMER
#define START_TIMER
#define STOP_TIMER(name)
#endif


template<typename X>
void fill_array(X *arr, X size);

int main()
{
    int arr[SIZE], target_value = 20;
    fill_array(arr, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        if(arr[linear_search(arr, &arr[SIZE], &i)] == i && arr[binary_search(arr, &arr[SIZE], &i)] == i) cout << "Поиск верный!" << i << endl;
        else cout << "Поиск неверный!" << endl;
    }

    return 0;
}

template<typename X>
void fill_array(X *arr, X size)
{
    register X i = 0;
    while(i < size)
    {
        *arr++ = i++;
    }
    return;
}