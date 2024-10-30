#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int ChangeFileSize(char *file_name,int size);
size_t getFileSize(char *file_name); 
