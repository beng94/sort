#include "quick_sort.h"

static void swap (int* array, int id_a, int id_b)
{
    int tmp = array[id_a];
    array[id_a] = array[id_b];
    array[id_b] = tmp;
}


static int partition(int* array, int beg, int end)
{
    int pivot_id = rand() % (end - beg) + beg;
    int pivot_val = array[pivot_id];

    swap(array, pivot_id, end);

    int left_id = beg;
    for(int i = beg; i < end; i++)
    {
        if(array[i] <= pivot_val)
        {
            swap(array, i, left_id);
            left_id++;
        }
    }

    swap(array, end, left_id);

    return left_id;
}

static void sort (int* array, int beg, int end)
{
    if(beg < end)
    {
        int a = partition(array, beg, end);
        sort(array, beg, a-1);
        sort(array, a+1, end);
    }
}

void quick_sort(int* array, size_t size)
{
    sort(array, 0, size-1);
}
