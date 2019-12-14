# Project: plagiarismCatcher
# Makefile created by Dev-C++ 4.9.9.2
# Modified by zanefreeman

CPP  = g++
RES  = 
OBJ  = textfile.o hash.o main.o directory.o $(RES)
LINKOBJ  = textfile.o hash.o main.o directory.o $(RES)
BIN  = plagiarismCatcher
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f


all: plagiarismCatcher

clean: 
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o plagiarismCatcher $(LIBS)

textfile.o: textfile.cpp
	$(CPP) -c textfile.cpp -o textfile.o $(CXXFLAGS)

hash.o: hash.cpp
	$(CPP) -c hash.cpp -o hash.o $(CXXFLAGS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

directory.o: directory.cpp
	$(CPP) -c directory.cpp -o directory.o $(CXXFLAGS)
