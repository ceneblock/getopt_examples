APR_CXX=${shell apr-1-config --includes --link-ld}

all: naive getopt apr

naive: naive.cpp
	g++ naive.cpp -o naive

getopt: getopt.cpp
	g++ getopt.cpp -o getopt

apr: apr.cpp
	g++ ${APR_CXX} apr.cpp -o apr

clean:
	-rm naive getopt apr

.PHONY: all clean
