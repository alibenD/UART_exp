/**-----------------------------------------------
  * @Copyright (C) 2017 All rights reserved.
  * @filename: serial_port_sent.c
  * @author: aliben.develop@gmail.com
  * @created_date: 2017-10-24 16:23:50
  * @last_modified_date: 2017-10-25 16:31:14
  * @description: A client senting message from
  *   serial port
  *-----------------------------------------------*/

//INCLUDE
#include "serial_port.h"

//CODE
int main(int argc, char** argv){
  // Variable for serial port
  int fd_open;                        // Handler of serial port
  int flag_write;                     // Return a status of writing msg
//  const char* path = "/dev/ttys007";  // Address of serial port device file
  const char* path = argv[1];
  char sbuf[] = {"\033[32m[Warning] It is not war, not war!\n\033[0m"};
  int len_msg = sizeof(sbuf);
  unsigned char count = 65;
  unsigned int tmp_count = 0;

  // Open Serial Port
  fd_open = open_serial(path);

  // Serial Port Setting Structure
  struct termios option;

  // Setting up Serial Port
  tcgetattr(fd_open, &option);   // Get current setting
  cfmakeraw(&option);            // Set serial port as raw mode
  cfsetispeed(&option, B9600);  // Set Baud Rate recieving
  cfsetospeed(&option, B9600);  // Set Baud Rate senting
  tcsetattr(fd_open, TCSANOW, &option);  // Update setting
  
  // Start senting message
  while(1){
    flag_write = write(fd_open, sbuf, len_msg);
    for(tmp_count=0;tmp_count<50000;tmp_count++);
    count++;
    if(count > 90){
      count = 65;
    }
    sbuf[14] = count;
//    if(flag_write == -1){
//      perror("Sent failed!!!");
//    }
  }
  printf("What is it: %d", flag_write);
  return 0;
}
