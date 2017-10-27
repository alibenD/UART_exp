/**-----------------------------------------------
  * @Copyright (C) 2017 All rights reserved.
  * @filename: serial_port.c
  * @author: aliben.develop@gmail.com
  * @created_date: 2017-10-24 00:52:55
  * @last_modified_date: 2017-10-24 16:22:21
  * @description: Definitions for operation of serial port
  *-----------------------------------------------*/

//INCLUDE
#include "serial_port.h"

//CODE
int open_serial(const char* path){
  // open(const char* path, int oflag)
  // oflag = FLAG1|FLAG2|...|;
  //  O_RDWR: Read/Write
  //  O_NOCTTY: Not terminated by tty(Terminal)
  //  O_NDELAY: In GNU C, O_NDELAY uses O_NONBLOCK as Macro, which is for compatible with BSD
  
  // fd_open: file description
  int fd_open;
  fd_open = open(path, O_RDWR|O_NOCTTY|O_NDELAY);

  // Check device if open;
  if(fd_open == -1){
    perror("Open serial port failed!\n");
    printf("Path is %s\n", path);
    return -1;
  }

  // Open successfully.
  printf("Opened %s\n", path);
  printf("[Debug] File Descriptor for open: %d\n", fd_open);
  return fd_open;
}

int close_serial(int fd_open){
  int fd_close_flag; 
  fd_close_flag = close(fd_open);
  printf("[Debug] File Descriptor for close: %d\n", fd_close_flag);
  if(fd_close_flag == -1){
    printf("Close serial port failed!");
  }
  return fd_close_flag;
}


