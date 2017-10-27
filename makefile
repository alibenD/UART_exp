#---Automatically Generated from template 'makefile' wrote by @aliben---
#
# @Copyright (C) 2017 All rights reserved.
# @filename: makefile
# @author: aliben.develop@gmail.com
# @create_date: 2017-10-24 15:56:40
# @last_modified_date: NO_LAST_MODIFIED_DATE
# @description: TODO
#---****************************************************************---

#----------------------------------------------------------------------
#VARIABLE
  #TEST
    HEAD_POSTFIX=h
    SOURCE_POSTFIX=c

  #COMPILER
    CC=g++
  #COMPILER_FLAG
    CCFLAG=-Wall
    INCLUDEFLAG=-I./include/

  #DIRECTORY
    SOURCE_DIR=./src/
    INCLUDE_DIR=./include/
    BUILD_DIR=./build/
    OBJECT_DIR=./build/obj/
    BINARY_DIR=./build/bin/

  #SOURCE_LIST
    SOURCE_LIST=serial_port.c serial_port_recieve.c serial_port_sent.c
    INCLUDE_LIST=serial_port.h
    OBJECT_LIST=serial_port.o serial_port_recieve.o serial_port_sent.o

  #FILE_LIST
    SOURCE_FILE_LIST=./src/serial_port.c ./src/serial_port_recieve.c ./src/serial_port_sent.c
    INCLUDE_FILE_LIST=./include/serial_port.h
    OBJECT_BUILD_FILE_LIST=./build/obj/serial_port.o ./build/obj/serial_port_recieve.o ./build/obj/serial_port_sent.o
    BINARY_BUILD_FILE_LIST=./build/bin/serial_port_recieve ./build/bin/serial_port_sent

#----------------------------!!!!!!!-----------------------------
#---This field should be set while you created your program
  #TARGET_LIST
    TARGET_OBJECT_LIST=serial_port.o serial_port_recieve.o serial_port_sent.o
    TARGET_BIN_LIST=serial_port_recieve serial_port_sent

  #DEPEND_LIST
    DEP=serial_port.o
#----------------------------!!!!!!!-----------------------------

  #VPATH

#MAKE_KEYWORD
  vpath %.h ./include/
  vpath %.hh ./include/
  vpath %.hpp ./include/
  vpath %.hxx ./include/

  vpath %.c ./src/
  vpath %.cc ./src/
  vpath %.cpp ./src/
  vpath %.cxx ./src/

#----------------------------------------------------------------------
#TARGET

all: all_obj $(TARGET_BIN_LIST)

all_obj: $(TARGET_OBJECT_LIST)

$(TARGET_OBJECT_LIST): %.o : %.c
	$(CC) $(CCFLAG) -o $(OBJECT_DIR)$@ -c $< $(INCLUDEFLAG)

$(TARGET_BIN_LIST): %: %.o 
	$(CC) $(CCFLAG)  -o $(BINARY_DIR)$@ $(OBJECT_DIR)$<  $(OBJECT_DIR)$(DEP) $(INCLUDEFLAG)

.PHONY: clean

clean:
	rm ${OBJECT_BUILD_FILE_LIST}
	rm ${BINARY_BUILD_FILE_LIST}

