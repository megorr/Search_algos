#include <iostream>

/////////////////////////////////////////////////////////Вспомогательные алгоритмы/////////////////////////////////////////////////////////

template<typename X>
void print_arr(X *begin, X *end)
{
    while(begin < end) std::cout << *begin++ << " ";
    std::cout << "\n";
    return;
}

/////////////////////////////////////////////////////////Алгоритмы поиска//////////////////////////////////////////////////////////////////

template<typename X>//Простой линейный поиск
int linear_search(X *begin, X *end, X *value)
{
    X *curr = begin;
    while(curr < end)
    {
        if(*curr++ == *value) return (curr - begin -1);
    }
    return -1;
}

template<typename X> //Все еще линейный поиск
int linear_search(X *begin, X *end, X value)
{
    X *curr = begin;
    while(curr < end)
    {
        if(*curr++ == value) return (curr - begin - 1);
    }
    return -1;
}

template<typename X> //Бинарный поиск
int binary_search(X *begin, X *end, X *value)
{
	X *curr_begin = begin;
	X *curr_end = end;
	int middle = (curr_end - curr_begin) / 2;
	X *middle_ptr = curr_begin + middle;

	while(curr_end >= curr_begin)
	{
		if(*value == *middle_ptr) return middle_ptr - begin;
		if(*value > *middle_ptr)
		{
			curr_begin = middle_ptr;
			middle = (curr_end - curr_begin) / 2;
			middle_ptr = curr_begin + middle;
		}
		else
		{
			curr_end = middle_ptr;
			middle = (curr_end - curr_begin) / 2;
			middle_ptr = curr_begin + middle;
		}
	}
	return -1;
}


