prog.exe: simulate_roomba.o ZigRoomba.o RandomRoomba.o CircleRoomba.o Roomba.o Floor.o
	g++ simulate_roomba.o ZigRoomba.o RandomRoomba.o CircleRoomba.o Roomba.o Floor.o

simulate_roomba.o: simulate_roomba.cpp
	g++ -c simulate_roomba.cpp

ZigRoomba.o: ZigRoomba.cpp
	g++ -c ZigRoomba.cpp

RandomRoomba.o: RandomRoomba.cpp
	g++ -c RandomRoomba.cpp

CircleRoomba.o: CircleRoomba.cpp
	g++ -c CircleRoomba.cpp

Roomba.o: Roomba.cpp
	g++ -c Roomba.cpp

Floor.o: Floor.cpp
	g++ -c Floor.cpp

make clean:
	rm -f *.out *.exe *.o
