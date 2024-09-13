#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int change_file_size(char *file_name,int size);
size_t check_error(char *file_name); 
