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

OBJS:=\
	src/util.o\
	src/vigenere.o\
	src/autokeyvigenere.o\
	src/fullvigenere.o\
	src/extendedvigenere.o\
	src/playfair.o\
	src/affine.o\
	src/main_window.o\
	src/main.o

QT5FLAGS!=pkg-config --cflags Qt5Widgets Qt5Qml
QT5LIBS!=pkg-config --libs Qt5Widgets Qt5Qml


.PHONY: all clean

.SUFFIXES: .c .o .cpp

all: test

test: $(TESTOBJS)
	$(CX) $^ -o $@

crypttools: $(OBJS)
	$(CX) $^ -o $@ $(QT5FLAGS) $(QT5LIBS)

.cpp.o:
	$(CX) -MD -fPIC -c $< -o $@ $(QT5FLAGS) $(QT5LIBS)

compile_flags:
	printf "%s\n" $(QT5FLAGS) > compile_flags.txt

clean:
	rm test */*.o */*.d

-include $(OBJS:.o=.d)
-include $(TESTOBJS:.o=.d)
