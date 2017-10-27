/**-----------------------------------------------
  * @Copyright (C) 2017 All rights reserved.
  * @filename: serial_port_recieve_new.c
  * @author: aliben.develop@gmail.com
  * @created_date: 2017-10-24 16:17:11
  * @last_modified_date: 2017-10-25 15:38:28
  * @description: A client recieving message from
  *   serial port
  *-----------------------------------------------*/

//INCLUDE
#include "serial_port.h"

//CODE

int main(int argc, char** argv){
//  const char* path = "/dev/ttys001";
  const char* path = argv[1];
  char buff[MAX_BUFFER_SIZE], *rbuf;
  int fd_open;
  
  fd_open = open_serial(path);
  // struct for terminal I/O
  struct termios opt;
  tcgetattr(fd_open, &opt);
  cfmakeraw(&opt);
  cfsetispeed(&opt, B9600);
  cfsetospeed(&opt, B9600);
  tcsetattr(fd_open, TCSANOW, &opt);
  rbuf = buff;
  printf("Ready for receiving data\n");

  while(1){
    while((read(fd_open, rbuf, 1))> 0)
      printf("%c", *rbuf);
  }

  printf("\n");
  close_serial(fd_open);
  return 0;
}

