# project name which will be used as a name of the resulting executable
PROJECT := diff
TEST_PARAMS ?= "./sample-data/src1.lst" "./sample-data/src2.lst"
SRCEXT := .cc
HEXT := .hh
# some common directories
IDIR := ./
SDIR := ./src
ODIR := $(SDIR)/obj
LDIR := lib
BINDIR := bin

# compiler to use
CXX = g++

# libraries to link with
LIBS=

# compiter flags
CXXFLAGS = -Wall  -I$(IDIR) -fms-extensions -std=c++17

# linker flags
LDFLAGS := $(LIBS)

# generate list of object files corresponding to source files
OBJECTS = $(patsubst $(SDIR)/%$(SRCEXT),$(ODIR)/%.o,$(wildcard $(SDIR)/*$(SRCEXT)))

# mode-specific flags

# ensure that all required directories exist and build executable
.PHONY: build
build: directories executable

.PHONY: debug
debug: CXXFLAGS += -g -O0 -DDEBUG
debug: LDFLAGS += -g
debug: build

# .PHONY: release
# release: CXXFLAGS += -O2
# release: build

.PHONY: all
all: debug #release

# rule for object files
$(ODIR)/%.o: $(SDIR)/%$(SRCEXT)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# rule for the resulting file
$(BINDIR)/$(PROJECT): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

executable: $(BINDIR)/$(PROJECT)

.PHONY: clean
clean:
	@rm -f $(OBJECTS)
	@rm -f $(BINDIR) -r
	@rm -f $(ODIR) -r

.PHONY: test
test:
	./$(BINDIR)/$(PROJECT) $(TEST_PARAMS)

.PHONY: directories
directories:
	@mkdir -p $(ODIR)
	@mkdir -p $(BINDIR)
