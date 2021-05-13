OBJS=read_json.o encoding_decoding.o main.o
CC=gcc
LIB= ./libfdr/libfdr.a
INC= -I ./libfdr

all: kripto

kripto: $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $@

encoding_decoding.o: encoding_decoding.c
	$(CC) $(INC) -c $<
read_json.o: read_json.c
	$(CC) $(INC) -c $<
main.o: main.c
	$(CC) $(INC) -c $<
clean:
	find . -type f -name "*.o"  -delete
	find . -type f -name "kripto"  -delete
cleanall:
	find . -type f -name "*.o"  -delete
	find . -type f ! -name "makefile" ! -name "*.*"  -delete
	find . -type f -name "*.txt"  -delete
	rm .kilit
	rm kripto
run: clean all
	./kripto -e ornek_metin encripted  
	./kripto -d encripted decripted
        
