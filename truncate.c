#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

size_t check_error(char *file_name){
    struct stat st;
    int stat_result = stat(file_name,&st);
    if(stat_result == -1){
        fprintf(stderr,"Failed to get \"%s\" data\nError: %s\n",file_name,strerror(errno));
        return 1;
    };
    return st.st_size;
}

int change_file_size(char *file_name,int size){
    int file;
    file = _open(file_name,_O_RDWR);
    if(file == -1){
        fprintf(stderr,"Failed to open \"%s\"\nError: %s\n",file_name,strerror(errno));
        return -1;
    };
    size_t default_size = check_error(file_name);
    if(default_size < size){
        fprintf(stderr,"File size is not upper than %d\n",size);
        _close(file);
        return -1;
    };
    if(_chsize(file,size) == -1){
        fprintf(stderr,"Failed to change \"%s\" size\nError: %s\n",file_name,strerror(errno));
        _close(file);
        return -1;
    };
    _close(file);
    return 0;
}
