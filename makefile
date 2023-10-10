CCG.bin:hello_world.o
	g++ -o CCG.bin hello_world.o `pkg-config --cflags --libs gtkmm-4.0`-std=c++17 

hello_world.o:hello_world.cpp
	g++ -c -ggdb hello_world.cpp `pkg-config --cflags --libs gtkmm-4.0`-std=c++17 
clean:
	rm CCG.bin hello_world.o

