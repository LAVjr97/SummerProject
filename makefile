all: main.cpp customer.cpp options.cpp 
	g++ main.cpp  order.cpp  

clean: 
	rm -f *.out a