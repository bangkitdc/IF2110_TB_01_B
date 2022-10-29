/* For Aesthetic Purposes */

#include <stdio.h>
#include "color.h"

/* Character */

void printRed(char c)
{
    printf("%s%c", RED, c);
    printf("%s", RESET);
}

void printGreen(char c)
{
    printf("%s%c", GREEN, c);
    printf("%s", RESET);
}

void printYellow(char c)
{
    printf("%s%c", YELLOW, c);
    printf("%s", RESET);
}

void printBlue(char c)
{
    printf("%s%c", BLUE, c);
    printf("%s", RESET);
}

void printMagenta(char c)
{
    printf("%s%c", MAGENTA, c);
    printf("%s", RESET);
}

void printCyan(char c)
{
    printf("%s%c", CYAN, c);
    printf("%s", RESET);
}

/* String */

void sprintRed(char *c) {
    printf("%s%s", RED, c);
    printf("%s", RESET);
}

void sprintGreen(char *c) {
    printf("%s%s", GREEN, c);
    printf("%s", RESET);
}

void sprintYellow(char *c) {
    printf("%s%s", YELLOW, c);
    printf("%s", RESET);
}

void sprintBlue(char *c) {
    printf("%s%s", BLUE, c);
    printf("%s", RESET);
}

void sprintMagenta(char *c) {
    printf("%s%s", MAGENTA, c);
    printf("%s", RESET);
}

void sprintCyan(char *c) {
    printf("%s%s", CYAN, c);
    printf("%s", RESET);
}
