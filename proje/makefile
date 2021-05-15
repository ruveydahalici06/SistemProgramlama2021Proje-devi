OBJS=read_json.o encoding_decoding.o main.o
CC=gcc
LIB= ./libfdr/libfdr.a

all: kripto

kripto: $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $@

encoding_decoding.o: encoding_decoding.c
	$(CC) -c $<
read_json.o: read_json.c
	$(CC) -c $<
main.o: main.c
	$(CC) -c $<
clean:
	find . -type f -name "*.o"  -delete
	find . -type f -name "kripto"  -delete
cleanall:
	find . -type f -name "*.o"  -delete
	find . -type f ! -name "makefile" ! -name "*.*"  -delete
	find . -type f -name "*.txt"  -delete
	rm .kilit
run: clean all
	./kripto -e ornek_metin encrypted  
	./kripto -d encrypted decrypted
        
