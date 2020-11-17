compRecMS : recursive_merge_sort.o merge_sort.o
	gcc merge_sort.o recursive_merge_sort.o -o recursive

compIterMS : iterative_merge_sort.o merge_sort.o
	gcc merge_sort.o iterative_merge_sort.o -o iterative

runRecMS : recursive
	./recursive

runIterMS : iterative
	./iterative

compare : iterative recursive
	./iterative
	./recursive

recursive : compRecMS

iterative : compIterMS

merge_sort.o : merge_sort.c merge_sort.h
	gcc -c merge_sort.c

recursive_merge_sort.o : recursive_merge_sort.o merge_sort.h
	gcc -c recursive_merge_sort.c

iterative_merge_sort.o : iterative_merge_sort.o merge_sort.h
	gcc -c iterative_merge_sort.c

