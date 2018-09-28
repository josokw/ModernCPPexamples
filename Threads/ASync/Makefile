CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Wextra -Weffc++ -Wpedantic \
           -Wold-style-cast -Winit-self -Wno-unused -Wshadow \
		   -Wno-parentheses -Wlogical-op -Wredundant-decls \
		   -Wcast-align -Wsign-promo -Wmissing-include-dirs \
		   -Woverloaded-virtual -Wctor-dtor-privacy \
		   -D_GLIBCXX_USE_NANOSLEEP

CXXLIBS = -L/usr/lib -lpthread

EXECUTABLE = async
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all
all: $(EXECUTABLE)

-include depend

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(CXXLIBS) -o $@

# Create dependency file
depend: $(SOURCES)
	$(CXX) -MM $(CXXFLAGS) $^ > $@

# Create a clean environment
.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)

# Clean up dependency file
.PHONY: clean-depend
clean-depend: clean
	$(RM) depend
