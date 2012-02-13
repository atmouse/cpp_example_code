# Makefile : for simulator C-src

# the LIBS  variable defines the C libraries to link with

LIBS = -lstdc++

# the SOURCES variable defines the C sources

SOURCES = calendar.cpp main.cpp model.cpp path.cpp queues.cpp ran2.cpp station.cpp

# the OBJS variable defines the object files

OBJS = calendar.o main.o model.o path.o queues.o ran2.o station.o

# compiler flags and things

FLAGS    = 2>>err
DEBUG    =   -ggdb
WARNINGS = # -Wall
OPTIMIZE =   -O0
PROFILE  = # -pg

# The C sources are compiled with flags as described by CFLAGS. 

CFLAGS =  ${OPTIMIZE} ${DEBUG}  ${WARNINGS} ${BOUNDS} ${PROFILE}

CC = gcc
O  = .o

%.o: %.cpp
	$(CC) -c $(FLAGS) $(CFLAGS) $<

# the real makecoy

all: clean drop
	@echo Done

clean: 
	rm -f err

# compile sources

drop: ${OBJS}
	${CC} -o simulate.exe ${CFLAGS} ${FLAGS} ${OBJS} ${LIBS} 

calendar$(0) : calendar.cpp queues.h calendar.h

main$(0) : main.cpp queues.h calendar.h path.h station.h model.h

model$(0) : model.cpp queues.h calendar.h path.h station.h model.h

path$(0) : path.cpp path.h

queues$(0) : queues.cpp queues.h calendar.h

ran2$(0) : ran2.cpp

station$(0) : station.cpp queues.h calendar.h path.h station.h

