cc=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB1=function.o
FLAGS= -Wall -g

all: stringProg
# main
stringProg: $(OBJECTS_MAIN) $(OBJECTS_LIB1)# my_mat
	$(cc) $(FLAGS) -o stringProg $(OBJECTS_MAIN) $(OBJECTS_LIB1)

$(OBJECTS_MAIN): main.c function.h
	$(cc) $(FLAGS) -c main.c
$(OBJECTS_LIB1): function.c function.h
	$(cc) $(FLAGS) -c function.c


.PHONY: clean all
clean:
	rm -f *.o  *.a *.so my_mat stringProg
