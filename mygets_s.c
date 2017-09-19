#include <stdio.h>
#include <stdlib.h>

// C11 Annex K does not appear to be supported on my compiler
// Therefore, I define my own gets_s
void * gets_s(char *buffer, int sizeInCharacters) {
    
    buffer = NULL;
    
    // fgets will read in sizeInCharacters - 1 or up until EOF or '\n'
    // It will also append a NULL terminator after the characters copied in
    fgets(buffer, sizeInCharacters, stdin);
    
    // If successful...
    if (buffer) {
        for (int i = 0; i < (sizeInCharacters - 1); i++) {
            // If there is a newline, we have good, nonoverflowed content
            if (buffer[i] == '\n')
                return (void *)buffer;
            // If there was no newline, someone was trying to overflow the buffer
        }
    }
    else {
        // We'll just clear the input buffer in the 'else' case
        int c;
        while ((c = getchar()) != '\n' && c!= EOF);
    }
    
    // Either we have no buffer or there is no newline in the buffer
    return NULL;
    
};

//  This is a test function for gets_s
void get_y_or_n(void) {
    char response[8];
    int len = (int)sizeof(response);
    puts("Continue? [y] n: ");
    gets_s(response, len);
    if(response[0] == 'n')
        exit(0);
}

// Here, I will run the test functions until the user quits from within the function
int main(int argc, const char * argv[]) {

    // insert code here...
    printf("Hello, World!\n");
    
    while(1) {
        get_y_or_n();
    }

    return 0;
}
