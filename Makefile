PROG = main

FLAGS = -O2

CC = g++

SRCS = MyComplex.cpp main.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@
	
%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG) 

## dependencies

main.o: main.cpp MyComplex.h

MyComplex.o: MyComplex.cpp MyComplex.h
