# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall
# Include directories
INCLUDES = -I./include
# Source files
SRCS = src/main.cpp src/services/lcd_service.cpp src/services/nfc_service.cpp src/services/database_service.cpp src/services/relay_service.cpp 
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
EXEC = nfc_app 

# Build executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ -lwiringPi -lnfc -lsqlite3

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(EXEC)
