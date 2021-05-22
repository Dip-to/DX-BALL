#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.

#OBJS specifies which files to compile as part of the project
OBJS = default.cpp
OBJS2 = main2.cpp
OBJS3 = *.cpp
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2
LINKER_FLAGS2 = -lSDL2_image
LINKER_FLAGS3 = -lSDL2_ttf
LINKER_FLAGS4 = -lSDL2_mixer

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = 01_hello_SDL

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(LINKER_FLAGS2) $(LINKER_FLAGS3) $(LINKER_FLAGS4) && ./a.out
all2 : $(OBJS2)
	$(CC) $(OBJS2) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(LINKER_FLAGS2) $(LINKER_FLAGS3) $(LINKER_FLAGS4) && ./a.out
all3 : $(OBJS3)
	$(CC) $(OBJS3) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(LINKER_FLAGS2) $(LINKER_FLAGS3) $(LINKER_FLAGS4)  && ./a.out