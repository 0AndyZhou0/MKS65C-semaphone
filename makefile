compile : control_semaphore.c main_semaphore.c
	gcc -c control_semaphore.c main_semaphore.c

run :
	./a.out

clean :
	rm *.o ./a.out
