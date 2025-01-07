all: server client

server: start.cpp
	g++ -o server start.cpp

client: client.cpp
	g++ -o client client.cpp

clean:
	rm -f *.o client server