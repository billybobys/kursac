all: report.exe

report.exe: report.o temp_functions.o
	gcc -o report report.o temp_functions.o

report.o: report.c temp_functions.h
	gcc -c -o report.o report.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c
