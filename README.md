# GetNextLine_42

*gscuderi <gscuderi@student.42roma.it>*
*20/05/2024*

## procedure
*code is not always full, and could be incorrectly just to be faster it should be easy to read*


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

printf("[%d]:%s\n", count, next_line); //count so we see the number of the line

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

```free(line)```


- let's add error if fd not found: so after opening the file
```
if (fd == -1) //-1 beacuse 0 could be ok for some sort of file

  printf("Error opening file");
```

- malloc in get_next_line: 

when bytes_read <= 0 before to return null we must free the buffer created with malloc, wich should correct the one leak standed out freeing already in the main.
**use calloc if malloc doesn't work**


### now let's spleet get_next_line.c

1. ft wich reads from fileadn append in a buffer with read
2. ft wich helps us get the next line.
- the 2 will called the first passing fd.
```
base_buffer = ft_read_from_file(fd);
return (base_buffer);
```
- we leave 3 char read when we call the ft because the subject asks us to read as little as possible: we have to return the hole  line when find a \n so it's not helpful to read smt like 100 char all in once.

so: 
### focus on Buffer size

( subject says to read as little as possible; 
and to check if code works with a buff size of 1, 9999, 100000000. )

we should also mantion that the buff size can be tested in the peer evaluation, while compiling: ***gcc -D BUFFER_SIZE=numero main.c g_n_l.c***;
and if not define there we should give it a number of default,
to do that:
```
#ifndef
#define BUFFER_SIZE=3
#end
```
in getnextline.h because it is a macro.
(macros are static variables so they are allocated in the data segment (they are "permently" memorized in the pc) not like the stack segment for local viarables)


# A better understanding of the gnl project.

- we don't know the size of the file 
- a code wich is able to handle any number of lines in the file
- the size of the buffer to choose is connected to the fact that we could have more then one new line in our buffer, may better small dispate the time consuming
-  free and malloc buffer with the necessary size, BUFF Size + 1

## Now we need to work on the ft*

***get_next_line***   function should then allocate mem. for static base_buffer (if empty) reads calling ft_read_from_file, and then should call another function to look for newlines.
```
char *get_next_line(int fd)
{
  static char *base_buffer;

  char *one_line;
  //controls of any sort 
  
  if (!ft_strchr(basin_buffer, '\n'))
   base_buffer = ft_read_from_file(base_buffer, fd);
  //controls if end of file, free base and return null

  one_line = ft_create_line(base_buffer);
  basin_buffer = ft_manage_remaining(base_buffer)
  return (one_line);
}
```
***two new ft to manage the buffer***
```
char *ft_create_line(char *base_buffer) {
  	char	*line;

	while (base_buffer)
	{
		*line = *base_buffer;
		if ((*line) == '\n')
			break;
		line++;
		base_buffer++;
	}
	*ptr_counter += 1;
	return (line);
}

char *ft_manage_remaining(char *base_buffer) {
	char	*tmp;

	tmp = malloc(1 * sizeof(char));
	while (*base_buffer != '\n')
		base_buffer++;
	while (*base_buffer != '\0')
		*tmp = *base_buffer;
	return (tmp);
}
```
(IT: base_buffer si riempie, se non ci sono newline, allora richiama read_from_file e ci aggiunge roba, il main richiama get_next_line e cosi via, se nel base buffer ce il new line va avanti):

***ft_read_from_file***   takes from a file, put in a mid buffer wich needs to be allocated first, and then calling ft_attach_buffer puts together base_buffer e mid buffer. 
("cup_buffer" -> "mid_buffer")

```
ft_read_from_file(base_buffer, fd)
{
  //malloc on mid_buffer
  //while bytes read > 0 and there aint't \n in base_buffer:
  //read from fd

  mid_buffer[bytes_read] = '\0'; // it goes in the +1 of the allocation

  base_buffer = ft_attach_buffer(base_buffer, mid_buffer);

  if (ft_strchr(base_buffer, '\n'))
   break ;
   //here i look for then \n and then i stop if found
}
```

***ft_attach_buffer***   base_buffer shell return once we find \n in the mid buffer, if not we join mid and base.
```
char *ft_attach_buffer(char *base_buffer, char *mid_buffer)
{ 
  char *temp = ft_strjoin(base_buffer, mid_buffer);
  free(base_buffer);
  return (temp); //in base buffer of read_from_file.
}
```

### how does ft_attach work and how not to waist mem.
The ft_attach_buffer wich takes as arguments(char *basin_buffer, char *read_buffer),
has the purpose of returning a combined char * di base e mid, wich comes back as new base in get next line.
It needs to be rimimbered base e mid are two pointers so they don't rappresent the actual data.

To concatenate base and mid buffer together memory space needs to be prepared considering both sets of data.
ft_strjoin allocates memory for the new base, and it does the real job of putting them together.

After the data is successfully combined in the new base_buffer, the function 
then reassigns the pointer base_buffer to point to the new memory address 
containing the merged data. 

## modifying
So it compils and nothing comes out, first thing I do is shrink the code so it's easier to adjest, now that we now how it must work, we can do this step.


I see I have created ft_attach to append a src in dst, and that's smt we have been doing inlibft, so I will replace

ft_attach_buffer , ft_strjoin , ft_strdup , ft_strlen , ft_strlcpy , all with:

ft_strcat and ft_strlen.

#error in ft_create_line e manage_remaining:
in create line we used directly the memory written in base: 

*base_buffer

base_buffer++

so we did not need manage remaining, because our base_buffer was already pointing at the position after the new line character

the error is also the fact that I did the same for the line wich would be return, and that's a problem because I wanna have the line pointer to the begging of the line string and not at the end 

```
while (base_buffer)
	{
		line[i] = *base_buffer;
		if (line[i] == '\n')

			break;
		i++;
		base_buffer++;
	}
```

So with this I can also another function.
serve prima del break base++, ed inoltre devo devo mettere un null a fine line.
I can join the while and the if cicle
I did this way:
```
char 	*ft_create_line(char *base_buffer) //torna one_line
{
	char	*line;
	int		i;

	i = 0;
	while (line[i - 1] == '\n' || base_buffer)
	{
		line[i] = *base_buffer;
		i++;
		base_buffer++;
	}
	line[i] = '\0';
	return (line);
}
```
then one more thing would also be going to change ft_calloc removing ft_bzero, and then we can also swap som malloc in the gnl.c with ft_calloc.

ft_bzero is done inside of calloc.

Using the limits.h we can use the value of UINT_MAX, as limits of allocations;
using malloc of the total (elements and size of elements).

