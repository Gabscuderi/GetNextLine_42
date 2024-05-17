# GetNextLine_42

## procedure

### first steps

**get_next_line(int fd)**
```
bytes_read = read(fd, cup_buffer, 3);

return (cup_buffer);
```
**main**

fd = open("testo_prova.txt", O_RDONLY);

**while (1)**

{

next_line = ft_get_next_line(fd);

**if (next_line == NULL)**
  **break ;**

printf("[%d]:%s\n", count, next_line); //count is to show you 
the line numbers

}

close(fd);

### now.
accumulating content until there is a new line

printing it 

and continuing until end of file.

but first:

- to check memory leaks:
**valgrind --leak-check=full ./a.out**

after you call get_next_line and printf it.  In the while loop:
**free(line)**


- let's add error if fd not found: so after opening the file

if (fd == -1) //-1 beacuse 0 could be ok for some sort of file

  printf("Error opening file");


- malloc in get_next_line: 

when bytes_read <= 0 before to return null we must free the buffer created with malloc, wich should correct the one leak standed out freeing already in the main.
**use calloc if malloc doesn't work**


### now let's spleet get_next_line.c

1. ft wich reads from fileadn append in a buffer with read
2. ft wich helps us get the next line.
- the 2 will called the first passing fd.

base_buffer = ft_read_from_file(fd);
return (base_buffer);

- we leave 3 char read when we call the ft because the subject asks us to read as little as possible: we have to return the hole  line when find a \n so it's not helpful to read smt like 100 char all in once.

so: 
### focus on Buffer size

( subject says to read as little as possible; 
and to check if code works with a buff size of 1, 9999, 100000000. )

we should also mantion that the buff size can be tested in the peer evaluation, while compiling: ***gcc -D BUFFER_SIZE=numero main.c g_n_l.c***;
and if not define there we should give it a number of default,
to do that:

#ifndef
#define BUFFER_SIZE=3
#end

in getnextline.h because it is a macro.


!!! vedere se aggiungere ft_helper per verifica qui nel readme

### chapter 4: a better understanding of the gnl project.






