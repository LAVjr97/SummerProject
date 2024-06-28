all: menu.cpp menuHeader.h customer.h customer.cpp options.cpp 
	g++ main.cpp menuHeader.h order.cpp order.h 

clean: 
	rm -f *.out a