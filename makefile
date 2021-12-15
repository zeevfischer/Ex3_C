# cc=gcc
# AR=ar
# OBJECTS_MAIN=main.o
# OBJECTS_LIB1=baiscClassification.o
# OBJECTS_LIB2=advancedClassificat.o
# OBJECTS_LIB3=advancedClassificationRecursion.o
# FLAGS= -Wall -g

# all: mains maindloop maindrec loops  
# mains: $(OBJECTS_MAIN) libclassrec.a 
# 	$(cc) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm

# maindloop: $(OBJECTS_MAIN) libclassloops.so
# 	$(cc) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm

# maindrec: $(OBJECTS_MAIN) libclassrec.so
# 	$(cc) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm

# loops: libclassloops.a
# libclassloops.a: $(OBJECTS_LIB1) $(OBJECTS_LIB2)
# 	$(AR) -rcs libclassloops.a $(OBJECTS_LIB1) $(OBJECTS_LIB2)

# loopd: libclassloops.so 
# libclassloops.so: $(OBJECTS_LIB1) $(OBJECTS_LIB2)
# 	$(cc) -shared -o libclassloops.so $(OBJECTS_LIB1) $(OBJECTS_LIB2)

# recursives: libclassrec.a 
# libclassrec.a: $(OBJECTS_LIB1) $(OBJECTS_LIB3)
# 	$(AR) -rcs libclassrec.a $(OBJECTS_LIB1) $(OBJECTS_LIB3)

# recursived: libclassrec.so 
# libclassrec.so: $(OBJECTS_LIB1) $(OBJECTS_LIB3)
# 	$(cc) -shared -o libclassrec.so $(OBJECTS_LIB1) $(OBJECTS_LIB3)

# $(OBJECTS_MAIN): main.c NumClass.h
# 	$(cc) $(FLAGS) -c main.c
# $(OBJECTS_LIB1): baiscClassification.c NumClass.h
# 	$(cc) $(FLAGS) -c baiscClassification.c
# $(OBJECTS_LIB2): advancedClassificat.c NumClass.h
# 	$(cc) $(FLAGS) -c advancedClassificat.c
# $(OBJECTS_LIB3): advancedClassificationRecursion.c NumClass.h
# 	$(cc) $(FLAGS) -c advancedClassificationRecursion.c


# .PHONY: clean all
# clean:
# 	rm -f *.o  *.a *.so mains maindloop maindrec

# //////////////////////////////////////////////////////////////////////
# cc=gcc
# AR=ar
# # OBJECTS_LIB1=tirgul.o
# FLAGS= -Wall -g

# all: Cfile Ofile

# Cfile: main.c
# 	$(cc) $(FLAGS) -c main.c

# Ofile: main.o
# 	$(cc) $(FLAGS) main.o -o run

# .PHONY: clean all
# clean:
# 	rm -f *.o  *.a *.so Cfile run
# /////////////////////////////////////////////////////////
cc=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB1=function.o
FLAGS= -Wall -g

all: stringProg
# main
stringProg: $(OBJECTS_MAIN) $(OBJECTS_LIB1)# my_mat
	$(cc) $(FLAGS) -o stringProg $(OBJECTS_MAIN) $(OBJECTS_LIB1)

# lib
# my_mat: $(OBJECTS_LIB1)
# 	$(cc) -shared -o my_mat $(OBJECTS_LIB1)

$(OBJECTS_MAIN): main.c function.h
	$(cc) $(FLAGS) -c main.c
$(OBJECTS_LIB1): function.c function.h
	$(cc) $(FLAGS) -c function.c


.PHONY: clean all
clean:
	rm -f *.o  *.a *.so my_mat stringProg
