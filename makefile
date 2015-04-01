all:
	gcc -std=c11 -o ALL main.c merge_sort.c merge_sort.h \
						quick_sort.c quick_sort.h
