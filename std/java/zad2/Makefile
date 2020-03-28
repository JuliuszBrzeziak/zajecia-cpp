# Mój plik makefile - wpisz 'make all' aby skompilować cały program
# (właściwie wystarczy wpisać 'make' - all jest domyślny jako pierwszy cel)
CC = gcc  

all: pierwszy.o drugi.o trzeci.o czwarty.o
    $(CC) pierwszy.o drugi.o trzeci.o czwarty.o -o test

pierwszy.o: pierwszy.c pierwszy.h
    $(CC) pierwszy.c -c -o pierwszy.o

