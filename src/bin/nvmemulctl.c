#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <errno.h>

void enable() {
    init();
}

void disable() {
    init();
    finalize();
}

int main(int argc, char *argv[]) {
    int opt;
    int enableFlag = 0;
    int disableFlag = 0;

    while ((opt = getopt(argc, argv, "ed")) != -1) {
        switch (opt) {
            case 'e':
                enableFlag = 1;
                break;
            case 'd':
                disableFlag = 1;
                break;
            case '?':
                fprintf(stderr, "Usage: %s -e | -d\n", argv[0]);
                return 1;
        }
    }

    if (enableFlag && disableFlag) {
        fprintf(stderr, "Error: You cannot specify both -e and -d at the same time.\n");
        return 1;
    }

    // Check which flag is set and call the corresponding function
    if (enableFlag) {
        enable();
    } else if (disableFlag) {
        disable();
    } else {
        fprintf(stderr, "Error: You must specify either -e or -d.\n");
        return 1;
    }

    return 0;
}

