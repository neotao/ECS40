## Yizhi Tao
## 912121365

CXXFLAGS=-Wall

all: maintenance testAircraft

maintenance: maintenance.o Aircraft.o
	$(CXX) -o $@ $^

testAircraft: testAircraft.o Aircraft.o
	$(CXX) -o $@ $^

execs = maintenance testAircraft

clean:
	rm -f $(execs) *.o
