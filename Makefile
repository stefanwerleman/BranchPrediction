CPP = g++
OPT = -O3
# OPT = -g
WARN = -Wall -Wextra
LOG = -I "./external/spdlog/include"
CFLAGS = $(OPT) $(WARN) $(INC) $(LIB)

# Other directories
BUILD = ./build/
LIBS = ./libs/
SRC = ./src/
TEST = ./tests/

# List all your .cpp files here (source files, excluding header files)
SIM_SRC = ./src/main_sim.cpp ./libs/ArgumentWrapper/ArgumentWrapper.cpp ./libs/Controller/Controller.cpp ./libs/Bimodal/Bimodal.cpp ./libs/GShare/GShare.cpp ./libs/Hybrid/Hybrid.cpp ./libs/Smith/Smith.cpp

# List corresponding compiled object files here (.o files)
SIM_OBJ = ./src/main_sim.o ./libs/ArgumentWrapper/ArgumentWrapper.o ./libs/Controller/Controller.o ./libs/Bimodal/Bimodal.o ./libs/GShare/GShare.o ./libs/Hybrid/Hybrid.o ./libs/Smith/Smith.o
 
#################################

# default rule

# Main Simulation run for TA
all: sim
	@echo "my work is done here..."


# rule for making sim_cache
sim: $(SIM_OBJ)
	$(CPP) -o sim $(CFLAGS) $(SIM_OBJ) $(OPT) -lm
	@if [ ! -d $(BUILD) ]; then mkdir $(BUILD); fi
	@mv $(SRC)*.o $(BUILD)
	@mv $(LIBS)*/*.o $(BUILD)
	@echo "-----------DONE WITH SIM-----------"

# generic rule for converting any .cc file to any .o file 

.cc.o:
	$(CPP) $(CFLAGS) -c $*.cc

detect_leak:
	@echo "======================DETECTING MEMORY LEAK 1=============================="
	valgrind --leak-check=yes ./sim bimodal 6 gcc_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 2=============================="
	valgrind --leak-check=yes ./sim bimodal 12 gcc_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 3=============================="
	valgrind --leak-check=yes ./sim bimodal 4 jpeg_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 4=============================="
	valgrind --leak-check=yes ./sim gshare 9 3 gcc_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 5=============================="
	valgrind --leak-check=yes ./sim gshare 14 8 gcc_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 6=============================="
	valgrind --leak-check=yes ./sim gshare 11 5 jpeg_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 7=============================="
	valgrind --leak-check=yes ./sim hybrid 8 14 10 5 gcc_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 8=============================="
	valgrind --leak-check=yes ./sim smith 3 gcc_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 9=============================="
	valgrind --leak-check=yes ./sim smith 1 jpeg_trace.txt
	@echo "======================DONE WITH MEMORY LEAK DETECTION======================"
	
	@echo "======================DETECTING MEMORY LEAK 10============================="
	valgrind --leak-check=yes ./sim smith 4 perl_trace.txt
	@echo =======================DONE WITH MEMORY LEAK DETECTION======================"

trace_seg_fault:
	gdb ./sim

# type "make clean" to remove all .o files plus the sim_cache binary

clean:
	rm -f ./*.o sim
	rm -f $(BUILD)*.o sim
	rm -f $(SRC)*.o sim
	rm -rf ./build


# type "make clobber" to remove all .o files (leaves sim_cache binary)

clobber:
	rm -f ./build/*.o


