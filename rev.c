#include <stdio.h>
#include <string.h>

int
main()
{
    char            str[] = "1234";
    const size_t    len = strlen(str);
    size_t          half;
    char            tmp;

    if (len % 2 == 0) {
        half = len / 2;
    } else {
        half = (len - 1) / 2;
    }

    for (size_t i = 0; i < half; i++) {
        tmp = str[i];
        str[i] = str[len - (i + 1)];
        str[len - (i + 1)] = tmp;
    }

    printf("%s\n", str);

    return 0;
}
