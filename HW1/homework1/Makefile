CXXFLAGS=-Wall

all: testFraction useFraction calculator

testFraction: testFraction.o Fraction.o
	$(CXX) -o $@ $^

useFraction: useFraction.o Fraction.o
	$(CXX) -o $@ $^

calculator: calculator.o Fraction.o
	$(CXX) -o $@ $^

execs = testFraction useFraction calculator

clean:
	rm -f $(execs) *.o
	
