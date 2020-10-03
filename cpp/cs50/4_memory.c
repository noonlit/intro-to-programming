#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

int main(void) {
    char* s = "emma";

    char* t = malloc(strlen(s) + 1); // for the null terminator

    if (!t) {
        return;
    }

    for (int i = 0, n = strlen(s); i < n + 1; i++) {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("String s is %s and string t is %s\n", s, t);

    free(t);
}