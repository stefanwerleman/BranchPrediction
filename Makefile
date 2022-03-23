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
SIM_SRC = ./src/main_sim.cpp ./libs/ArgumentWrapper/ArgumentWrapper.cpp ./libs/utils/utils.cpp

# List corresponding compiled object files here (.o files)
SIM_OBJ = ./src/main_sim.o ./libs/ArgumentWrapper/ArgumentWrapper.o ./libs/utils/utils.o
 
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
	@echo "-----------DETECTING MEMORY LEAKS-----------"
	valgrind --leak-check=yes ./sim
	@echo "-----------DONE WITH MEMORY LEAK DETECTION-----------"

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


