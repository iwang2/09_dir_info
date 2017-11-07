/*
    list all the files in the directory
    specify which files are directories (if any)
    show the total size of all the regular files the directory
        note that you do not have to recursively go through any subdirectories to find their size for this part (unless you want to, but that is not a simple task)
    Have the program scan the current directory
    Possible enhancements:
        Recursively list the files in any subdirectories, update the total to include the total size of subdirectories
        Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int printd(char * name){
  DIR * d = opendir(name);
  struct dirent * thing = readdir(d);
  struct stat sb;
  
  int tsize = 0;

  while(thing){    
    if(thing->d_type == DT_DIR){
      stat(thing->d_name, &sb);
      tsize += sb.st_size;
      printf("name: %s\n", thing->d_name);
      printf("size: %d\n\n", (int)sb.st_size);
    }
    
    thing = readdir(d);
  }
  closedir(d);
  return tsize;
}

int printfile(char * name){
  DIR * d = opendir(name);
  struct dirent * thing = readdir(d);
  struct stat sb;
  int tsize = 0;

  while(thing){
    if(thing->d_type != DT_DIR){
      stat(thing->d_name, &sb);
      tsize = sb.st_size;
      printf("name: %s\n", thing->d_name);
      printf("size: %d\n\n", (int)sb.st_size);
    }
    thing = readdir(d);
  }
  closedir(d);
  return tsize;
}

int main(){
  printf("\nDIRECTORIES:\n");
  int dsize = printd(".");
  printf("total size of directories (but not the stuff in them): %d\n\n", dsize);
  
  printf("\nFILES:\n");
  int fsize = printfile(".");
  printf("total size of files: %d\n\n", fsize);
}
