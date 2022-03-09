#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc,char **argv)
{
    printf("%s\n", get_next_line(0));
    return (0);
}