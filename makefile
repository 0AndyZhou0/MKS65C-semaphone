compile : control_semaphore.o main_semaphore.o
	gcc main_semaphore.o

setup : $(arg)
	gcc -o setup control_semaphore.o
	./setup $(arg)

run :
	./a.out

control_semaphore.o :
	gcc -c control_semaphore.c

main_semaphore.o : 
	gcc -c main_semaphore.c

clean :
	rm *.o ./a.out
	ipcrm -S 0xdeadbeef
