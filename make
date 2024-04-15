CC = g++
CFLAGS = -Wall
SRCS = project3.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = proj3

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.cpp
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)
