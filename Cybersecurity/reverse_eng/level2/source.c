#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input[24];
    char output[9];
    char temp[4];
    int input_index;
    int output_index;

    printf("Please enter key: ");

    if (scanf("%23s", input) != 1)
    {
        printf("Nope.\n");
        return 1;
    }

    if (input[1] != '0')
    {
        printf("Nope.\n");
        return 1;
    }

    if (input[0] != '0')
    {
        printf("Nope.\n");
        return 1;
    }

    fflush(stdout);

    memset(output, 0, 9);
    output[0] = 'd';

    temp[3] = '\0';

    input_index = 2;
    output_index = 1;

    while (strlen(output) < 8 &&
           input_index < (int)strlen(input))
    {
        temp[0] = input[input_index];
        temp[1] = input[input_index + 1];
        temp[2] = input[input_index + 2];

        output[output_index] = (char)atoi(temp);

        input_index += 3;
        output_index++;
    }

    output[output_index] = '\0';

    if (strcmp(output, "delabere") == 0)
        printf("Good job.\n");
    else
        printf("Nope.\n");

    return 0;
}