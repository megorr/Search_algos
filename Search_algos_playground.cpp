#include <iostream>
#include "Searches.h"

#define SIZE 300
#define TIMING

#ifdef TIMING //Макрос для измерения времени выполнения участка программы
#define INIT_TIMER auto start = std::chrono::steady_clock::now();
#define START_TIMER  start = std::chrono::steady_clock::now();
#define STOP_TIMER(name, time)  time = std::chrono::duration_cast<std::chrono::nanoseconds>\
								(std::chrono::steady_clock::now()-start).count();\
								std::cout << "RUNTIME of " << name << ": " << \
								time << " ns " << "or " << time/1000000 << "ms" <<std::endl;\
		
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
        if(arr[linear_search(arr, &arr[SIZE], &i)] == i && arr[binary_search(arr, &arr[SIZE], &i)] == i) std::cout << "Поиск верный!" << i << "\n";
        else std::cout << "Поиск неверный!\n";
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