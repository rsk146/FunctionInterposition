#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <gnu/lib-names.h> 


// Name: Rakshay
// netID: rsk146
// RUID: 187006497
// your code for time() goes here

int time_flag = 1;
time_t time(time_t *tloc){
     void* handle = dlopen(LIBM_SO, RTLD_LAZY);
     time_t (*true_time)(time_t* tloc) = (time_t(*)(time_t*)) dlsym(handle, "time");
     time_t valid_time = 1614885385;
     if(time_flag){
          time_flag = 0;
          *tloc = valid_time;
          return *tloc;
     }
     else return true_time(tloc);
}