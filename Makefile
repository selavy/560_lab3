CPP = g++
CFLAGS = -Wall -Werror -pedantic -g

OBJS = main.o
TIMER = Timer.hpp

Lab3: $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o Lab3
main.o: main.cpp $(TIMER)
	$(CPP) $(CFLAGS) -c main.cpp
clean:
	rm -rf *.o *~ Lab3
