#include <stdio.h>
#include <stdlib.h>

// C11 Annex K does not appear to be supported on my compiler
// Therefore, I define my own gets_s
void * gets_s(char *buffer, size_t sizeInCharacters) {

// fgets will read in sizeInCharacters - 1 or up until EOF or '\n'
// It will also append a NULL terminator after the characters copied in
    fgets(buffer, sizeInCharacters, stdin);
    if (buffer) {
        for (int i = 0; i < (sizeInCharacters - 1); i++) {
            // If there is a newline, we have good, nonoverflowed content
            if (buffer[i] == '\n')
                return (void *)buffer;
            // If there was no newline, someone was trying to overflow the buffer
        }
    }

    // We'll just clear the input buffer in the 'else' case
    int c;
    while ((c = getchar()) != '\n' && c!= EOF);
    return (void *)0;

};

//  This is a test function for gets_s
void get_y_or_n(void) {
    char response[8];
    size_t len = sizeof(response);
    puts("Continue? [y] n: ");
    gets_s(response, len);
    if(response[0] == 'n')
        exit(0);
}

// Here, I will run the test functions until the user quits from within the function
int main() {
    while(1) {
       get_y_or_n();
    }
    return 0;
}
