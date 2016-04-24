all:mfcpu mfcore mfhdd
		
mfcpu:main.o CPU.o Memory.o MemoryBus.o
		g++ main.o CPU.o Memory.o MemoryBus.o -o cpu
main.o:main.cpp
		g++ main.cpp -c 
CPU.o:CPU.cpp CPU.h 
		g++ CPU.cpp -c 
Memory.o:Memory.cpp Memory.h
		g++ Memory.cpp -c 
MemoryBus.o:MemoryBus.cpp MemoryBus.h
		g++ MemoryBus.cpp -c 
mfcore:coreRun.o core.o Memory.o MemoryBus.o IDE.o
		g++ coreRun.o core.o Memory.o MemoryBus.o IDE.o -o core
coreRun.o:coreRun.cpp
		g++ coreRun.cpp -c
core.o:core.cpp vardges.cpp core.h
		g++ core.cpp vardges.cpp -c    
Memory.o: Memory.cpp Memory.h
		g++  Memory.cpp -c 
MemoryBus.o:MemoryBus.cpp MemoryBus.h
		g++ MemoryBus.cpp -c 
IDE.o:IDE.cpp IDE.h
		g++ IDE.cpp -c
mfhdd:HDD.o mainhdd.o
		g++ HDD.o mainhdd.o -lpthread -pthread  -o hdd
HDD.o:HDD.cpp HDD.h
		g++ HDD.cpp -c
mainhdd.o:mainhdd.cpp
		g++ mainhdd.cpp -c

