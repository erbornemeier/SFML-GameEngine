TARGET = bank_tanks
CXX    = g++
CFLAGS = -Wall -g -std=c++11

SOURCE_DIR  = src/
INCLUDE_DIR = include/
BUILD_DIR = build/
LIB_DIR = ./
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

###########################################################
#get all source files in source directory + main.cpp
_src = $(wildcard $(SOURCE_DIR)*.cpp)

# get all object files by replacing source path with build path and
# convert .cpp extension to .o
obj = $(patsubst $(SOURCE_DIR)%,$(BUILD_DIR)%,$(_src))
_obj = $(obj:.cpp=.o)

# set include and lib path flags
INC_PATH = -I$(INCLUDE_DIR)
LIB_PATH = -L$(LIB_DIR)

###########################################################


all: $(TARGET)
	
main.cpp: main.o

main.o: $(_obj)
	$(CXX) $(CFLAGS) $(INC_PATH) -c main.cpp -o $(BUILD_DIR)main.o

$(_obj):
	echo $@
	$(CXX) $(CFLAGS) $(INC_PATH) -c $(patsubst $(BUILD_DIR)%.o,$(SOURCE_DIR)%.cpp,$@) -o $@ 

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)main.o $(_obj) bank_tanks

$(TARGET): main.cpp $(_src)
	$(CXX) $(CFLAGS) $(INC_PATH) -o $@ $^ $(LIB_PATH) $(LIBS)
