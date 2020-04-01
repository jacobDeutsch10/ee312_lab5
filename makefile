final: UtPodDriver.o UtPod.o Song.o
	g++ -o test  UtPodDriver.o UtPod.o song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp
