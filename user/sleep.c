#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if(argc<=1){

        exit(0);
    }
    else if(argc>2){
        printf("Cannot accept too many CLI elements");
        exit(0);
    }
    else {
        int time = atoi(argv[1]);
        //alarm(time);
        pause(time);
        printf("Pause returned with %d\n",time);
        exit(0);
    }
}