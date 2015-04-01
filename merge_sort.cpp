#include <iostream>
#include <time.h>
#include <stdlib.h>

class Sort
{
private:

    static void Copy (int* _array, int _begin, int _end, int* _tmp)
{
    for(int i = _begin; i < _end; i++) _array[i] = _tmp[i];
}

    static void Merge (int* _array, int _begin, int _middle, int _end, int* _tmp)
{
    int id_first = _begin;
    int id_second = _middle;

    for(int i = _begin; i < _end; i++)
    {
        if((_array[id_first] < _array[id_second] || id_second >= _end) && id_first < _middle )
        {
            _tmp[i] = _array[id_first];
            id_first++;
        }
        else
        {
            _tmp[i] = _array[id_second];
            id_second++;
        }
    }
}

    static void Split (int* _array, int _begin, int _end, int* _tmp)
{
    if(_end - _begin < 2) return;

    int middle = (_end + _begin) / 2;
    Split(_array, _begin, middle, _tmp);
    Split(_array, middle, _end, _tmp);
    Merge(_array, _begin, middle, _end, _tmp);
    Copy(_array, _begin, _end, _tmp);
}

public:
    static void Merge_Sort(int* _array, int _size)
{
    int tmp [_size];
    Split(_array, 0, _size, tmp);
}

};

void Print(int* _array, int _length)
{
    for(int i = 0; i < _length; i++)
    {
        std::cout << _array[i] << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    srand(time(NULL));

    int _size = 9;

    int tomb [_size];
    for(int i= 0; i< _size; i++) tomb[i] = rand() % 20;

    Print(tomb, _size);
    Sort::Merge_Sort(tomb, _size);
    Print(tomb, _size);

    return 0;
}
