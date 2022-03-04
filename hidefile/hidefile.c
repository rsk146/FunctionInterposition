#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <dlfcn.h>
#include <gnu/lib-names.h> 
#include <string.h>
#define BUFSIZE 256

//EC

// Name: Rakshay Kanthadai
// netID: rsk146
// RUID: 187006497
// your code for readdir goes here


struct dirent* readdir(DIR* dirp){
    const char* hidden = getenv("HIDDEN");
    void* handle = dlopen(LIBM_SO, RTLD_LAZY);
    struct dirent* (*true_readdir)(DIR* dirp) = (struct dirent* (*)(DIR*)) dlsym(handle, "readdir");
    struct dirent* entry= true_readdir(dirp);
    if(!entry){
        return entry;
    }
    if(!strcmp(entry->d_name, hidden)){
        entry = true_readdir(dirp);
    }
    return entry;
}


