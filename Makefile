VARIABLE = gcc -Wall -g
CLEAN = *.o *.a *.so mains maind

all: main run clean

main:
	$(VARIABLE) -o main.o main.c myBank.c

run:
	./main.o

myBank.o:
	$(VARIABLE) -c myBank.c

myBanks: myBank.o
	ar -rcs libmyBank.a myBank.o

mains: main.o myBanks
	$(VARIABLE) -o mains main.o libmyBank.a

myBankd: myBank.o
	$(VARIABLE) -o libmyBank.so -shared myBank.o 

maind: main.o myBankd
	$(VARIABLE) -o maind main.o ./libmyBank.so

main.o:
	$(VARIABLE) -c main.c
	
clean:
	rm -f $(CLEAN)
