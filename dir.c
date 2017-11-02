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
#include <dirent.h>
#include <sys/types.h>

int main(){
  DIR * d = opendir("..");

  struct dirent * thing = readdir(d);
  while(thing){
    printf("file name: %s\n", thing->d_name);
    printf("file type: %d\n\n", thing->d_type);
    
    thing = readdir(d);
  }
  closedir(d);
}
