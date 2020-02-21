cache_handle: cache_printer.c cache_handle.o
	gcc -std=c99 -g -o cache_printer cache_printer.c cache_handle.o
cache_reader.o: cache_handle.c
	gcc -std=c99 -g -c cache_handle.c
clean:
	rm *.o cache_printer
