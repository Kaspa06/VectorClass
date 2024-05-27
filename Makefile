# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall # Updated to C++17

# Program name
TARGET = run

# Object files list 
OBJS = main.o containers.o funkcijos.o funkcijosVECTOR.o studentas.o testRules.o

# Optimization levels
OPTIMIZATION_FLAGS = -O1 -O2 -O3

# Main rule for program compilation
$(TARGET): $(OBJS)

# Individual file compilation rules
main.o: main.cpp containers.h funkcijos.h testRules.h
	$(CXX) $(CXXFLAGS) -c main.cpp

containers.o: containers.cpp containers.h funkcijos.h funkcijosVECTOR.h studentas.h testRules.h
	$(CXX) $(CXXFLAGS) -c containers.cpp

funkcijos.o: funkcijos.cpp funkcijos.h studentas.h testRules.h
	$(CXX) $(CXXFLAGS) -c funkcijos.cpp

funkcijosVECTOR.o: funkcijosVECTOR.cpp funkcijosVECTOR.h studentas.h testRules.h
	$(CXX) $(CXXFLAGS) -c funkcijosVECTOR.cpp

studentas.o: studentas.cpp studentas.h testRules.h
	$(CXX) $(CXXFLAGS) -c studentas.cpp

testRules.o: testRules.cpp testRules.h
	$(CXX) $(CXXFLAGS) -c testRules.cpp

# Rule to compile with different optimization levels
optimize: clean
	@echo "Optimization level -O1"
	$(CXX) $(CXXFLAGS) -O1 -o $(TARGET)_O1 main.cpp containers.cpp funkcijos.cpp funkcijosVECTOR.cpp studentas.cpp testRules.cpp
	@echo "Optimization level -O2"
	$(CXX) $(CXXFLAGS) -O2 -o $(TARGET)_O2 main.cpp containers.cpp funkcijos.cpp funkcijosVECTOR.cpp studentas.cpp testRules.cpp
	@echo "Optimization level -O3"
	$(CXX) $(CXXFLAGS) -O3 -o $(TARGET)_O3 main.cpp containers.cpp funkcijos.cpp funkcijosVECTOR.cpp studentas.cpp testRules.cpp

# Clean rule
clean:
	del -f $(TARGET) $(TARGET)_O1 $(TARGET)_O2 $(TARGET)_O3 $(OBJS)
