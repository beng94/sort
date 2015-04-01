#include "merge_sort.h"

static void cpy (int* array, int beg, int end, int* tmp)
{
    for(int i = beg; i < end; i++) array[i] = tmp[i];
}

static void merge (int* array, int beg, int mid, int end, int* tmp)
{
    int id_first = beg;
    int id_second = mid;

    for(int i = 0; i < end; i++)
    {
        if((array[id_first] < array[id_second] ||
            id_second >= end) &&
            id_first < mid)
        {
            tmp[i] = array[id_first];
            id_first++;
        }
        else
        {
            tmp[i] = array[id_second];
            id_second++;
        }
    }
}

static void split(int* array, int beg, int end, int* tmp)
{
    if(end - beg < 2) return;

    int mid = (end + beg) / 2;
    split(array, beg, mid, tmp);
    split(array, mid, end, tmp);
    merge(array, beg, mid, end, tmp);
    cpy(array, beg, end, tmp);
}

void merge_sort (int* array, size_t size)
{
    int tmp[size];
    split(array, 0, size, tmp);
}
