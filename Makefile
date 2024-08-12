# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Define source files and object files
SERVER_SRC = server.cpp Logger.cpp
CLIENT_SRC = client.cpp Logger.cpp
SERVER_OBJ = $(SERVER_SRC:.cpp=.o)
CLIENT_OBJ = $(CLIENT_SRC:.cpp=.o)

# Define the executables
SERVER_EXE = server
CLIENT_EXE = client

# Default target
all: $(SERVER_EXE) $(CLIENT_EXE)

# Rule to build the server executable
$(SERVER_EXE): $(SERVER_OBJ) 
	$(CXX) $(CXXFLAGS) -o $@ $(SERVER_OBJ)

# Rule to build the client executable
$(CLIENT_EXE): $(CLIENT_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(CLIENT_OBJ)

# Rule to build the object files for the server
server.o: server.cpp Logger.h
	$(CXX) $(CXXFLAGS) -c server.cpp

# Rule to build the object files for the client
client.o: client.cpp Logger.h
	$(CXX) $(CXXFLAGS) -c client.cpp

# Rule to build the object files for Logger
Logger.o: Logger.cpp Logger.h
	$(CXX) $(CXXFLAGS) -c Logger.cpp

# Clean up build artifacts
clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_EXE) $(CLIENT_EXE)

# Run server
run-server: $(SERVER_EXE)
	./$(SERVER_EXE)

# Run client
run-client: $(CLIENT_EXE)
	./$(CLIENT_EXE)

# Ensure that the `clean` target runs before `run-server` or `run-client`
.PHONY: clean all run-server run-client
