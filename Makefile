CXX		:= gcc
CXXFLAGS:= -g -std=c++11 -Wall
LDFLAGS := -lstdc++

SRCDIR	:= ./src
OBJDIR	:= ./obj
INCDIR	:= -I$(SRCDIR)

SRCS1	:= $(wildcard $(SRCDIR)/*.cpp)
OBJS	:= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS1))
SRCS2	:= $(wildcard ./*.cpp)
OBJS	+= $(patsubst ./%.cpp,$(OBJDIR)/%.o,$(SRCS2))
TARGET	:= codility_run

.PHONY: all clean

all: mk_objdir $(TARGET)

mk_objdir:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c -o $@ $<

$(OBJDIR)/%.o: ./%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c -o $@ $<

$(TARGET): $(mk_objdir) $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -rf $(OBJDIR) $(TARGET)
