#include "include.h"

unsigned char transmission_buffer[MAX_BUFFER];
unsigned char recive_buffer[MAX_BUFFER];

int main(void)
{
  struct buffer_type tb;

  printf("Use this for application code\n");

  init_buffer(&tb,transmission_buffer);

}
