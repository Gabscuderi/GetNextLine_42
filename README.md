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


### A better understanding of the gnl project.

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

char *ft_create_line(char *base_buffer) {
  //copia base in str compreso il \n mettondo un \0, e non il resto
  //ritorna come one_line nel get_next_line
}

char *ft_manage_remaining(char *base_buffer) {
  //toglie dal buffer il pre \n e ci lascia cio che rimane, 
  //ritorna come nuova base da riempire in get
}
```
base_buffer si riempie, se non ci sono newline, allora richiama read_from_file e ci aggiunge roba, il main richiama get_next_line e cosi via, se nel base buffer ce il new line va avnti 

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

## reread conclusion -> create ft_create_line and ft_manage_remaining -> adjust libft ft* -> run code -> peertopeer help -> find tester -> push -> restudy the project

The append_buffer function takes two arguments: 
char *basin_buffer and char *read_buffer. 

The purpose of this function is to concatenate the contents of 
read_buffer to the end of basin_buffer and return the updated combined 
string. To achieve this without causing any memory issues, the function 
handles memory allocation and pointer reassignment smartly.

When the append_buffer function is called, it receives the memory address 
of basin_buffer as its first argument and the memory address of read_buffer 
as its second argument. Since these are pointers, they represent memory 
addresses rather than the actual data.

To perform the concatenation, the function needs to create a new buffer 
that is large enough to hold the combined data. The function dynamically 
allocates memory for the new basin_buffer using the ft_strjoin function, 
which takes the old basin_buffer and the read_buffer as arguments, and 
concatenates them together into a new buffer. Crucially, the ft_strjoin 
function ensures that sufficient memory is allocated for the new buffer, 
considering both sets of data.

After the data is successfully combined in the new basin_buffer, the function 
then reassigns the pointer basin_buffer to point to the new memory address 
containing the merged data. This is the smart reassignment that allows the 
function to update the original basin_buffer outside of the function.

By reassigning basin_buffer, the function effectively updates the original 
pointer outside the function's scope. Now, the original basin_buffer points 
to the newly created buffer that holds the merged data from both buffers 
(basin_buffer and read_buffer).

This smart reassignment ensures that the caller of the append_buffer 
function receives the updated pointer, pointing to the combined data, 
and any further operations or usage of basin_buffer outside the function 
will reflect the changes made within the function.

In conclusion, the append_buffer function demonstrates the concept of 
passing pointers to modify the original pointer's value, allowing for 
efficient data concatenation without causing memory leaks or loss of data. 
This smart memory management and pointer reassignment make the function 
reliable and safe when dealing with dynamically allocated memory in C.
