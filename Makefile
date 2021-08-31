# test: src/util.cpp src/test.cpp src/vigenere.cpp src/autokeyvigenere.cpp src/fullvigenere.cpp
# 	g++ src/util.cpp src/test.cpp src/vigenere.cpp src/autokeyvigenere.cpp src/fullvigenere.cpp -o test

CX:=g++ -O2

TESTOBJS:=\
	src/util.o\
	src/vigenere.o\
	src/autokeyvigenere.o\
	src/fullvigenere.o\
	src/extendedvigenere.o\
	src/playfair.o\
	src/affine.o\
	src/test.o

# LIBS:=\
# 	-lGL\
# 	-lglut\
# 	-lm

# WLIBS:=\
# 	-lopengl32\
# 	-lglut32\
# 	-lglu32\
# 	-lglext\
# 	-lm

# CFLAGS:=\
# 	-Iglm-0.9.7.1

.PHONY: all clean

.SUFFIXES: .c .o .cpp

all: test

test: $(TESTOBJS)
	$(CX) $^ -o $@

.cpp.o:
	$(CX) -MD -c $< -o $@

clean:
	rm test */*.o */*.d

-include $(OBJS:.o=.d)
