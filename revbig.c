#include <stdio.h>
#include <string.h>

int
main()
{
    const char      str[] = "1234";
    const size_t    len = strlen(str);
    const size_t    mul = 1000000;
    const size_t    biglen = len * mul;
    char            big[biglen + 1];
    size_t          half;
    char            tmp;

    for (size_t i = 0; i < biglen; i += len) {
        snprintf(&big[i], sizeof(str), "%s", str);
    }

    if (biglen % 2 == 0) {
        half = biglen / 2;
    } else {
        half = (biglen - 1) / 2;
    }

    for (size_t i = 0; i < half; i++) {
        tmp = big[i];
        big[i] = big[biglen - (i + 1)];
        big[biglen - (i + 1)] = tmp;
    }

    printf("%s\n", big);

    return 0;
}
