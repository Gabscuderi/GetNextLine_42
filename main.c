#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("testo_prova.txt", O_RDONLY);
  next_line = ft_get_next_line(fd);
  count++;
  printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
  next_line = NULL;

  close(fd);
  return (0);
}