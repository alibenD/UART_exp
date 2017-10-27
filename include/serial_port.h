/**
  * @Copyright Dorabot Inc.
  * @date   : 2017-201?
  * @author : kaiwen.hu@dorabot.com
  *  
  * @brief  : TODO
  */
#ifndef _SERIAL_PORT_H__
#define _SERIAL_PORT_H__

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus
#include <stdio.h>    // Standard I/O lib 
#include <string.h>   // String headfile (C Language)
//#include <malloc.h>   // Memory Management
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>    // Serial Port Control, for "open" function
#include <unistd.h>   // Unix Standard Lib, for "close" function
#include <termios.h>  // Terminal I/O interface, POSIX interrupt control definition
#include <errno.h>    // Definition of error number
#include <math.h>

// Macro define
#define MAX_BUFFER_SIZE 512


// Declaration

int open_serial(const char* path);
int close_serial(int fd_open);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _SERIAL_PORT_H__
