compile : control_semaphore.o main_semaphore.o
	gcc control_semaphore.o

run :
	./a.out

control_semaphore.o :
	gcc -c control_semaphore.c

main_semaphore.o : 
	gcc -c main_semaphore.c

clean :
	rm *.o ./a.out
	ipcrm -S 0xdeadbeef
