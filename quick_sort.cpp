#include <iostream>
#include <time.h>
#include <stdlib.h>

void Print (int* _array, int length)
{
    for(int i = 0; i < length; i++) std::cout << _array[i] << ' ';

    std::cout << std::endl;
}

class SortClass
{
private:
    static void Sort(int* _array, const int _begin, const int _end)
    {
        if(_begin < _end)
        {
            int a = Partition(_array, _begin, _end);
            Sort(_array, _begin, a-1);
            Sort(_array, a+1, _end);
        }
    }

    static int Partition (int* _array, int _begin, int _end)
    {
        int pivot_id = rand() % (_end - _begin) + _begin;
        int pivot_value = _array[pivot_id];

        Swap(_array, pivot_id, _end);

        int left_id = _begin;
        for(int i = _begin; i < _end; i++)
        {
            if(_array[i] <= pivot_value)
            {
                Swap(_array, i, left_id);
                left_id++;
            }
        }

        Swap(_array, _end, left_id);

        return left_id;
    }

    inline static void Swap (int* _array, int _id1, int _id2)
    {
        int tmp = _array[_id1];
        _array[_id1] = _array[_id2];
        _array[_id2] = tmp;
    }

public:
    static void QuickSort(int* _array, const int _size) {Sort(_array, 0, _size-1);}
};

int main()
{
    srand(time(NULL));

    const int size = 10;
    int tomb [size];
    for(int i = 0; i < size; i++) tomb[i] = rand() % 20;

    //Print(tomb, size);
    SortClass::QuickSort(tomb, size);
    Print(tomb, size);



    return 0;
}
