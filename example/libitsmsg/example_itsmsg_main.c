#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "itsmsg_codec.h"

extern void ex_itsmsg_encode();
extern void ex_itsmsg_decode();

void itsmsg_example(unsigned long input)
{
    /* Not using input */
    (void)input;
    int ret;
    ITSMsgConfig cfg;

    ret = itsmsg_init(&cfg);
    if (ret != 0) {
        return;
    }

    ex_itsmsg_decode();
    ex_itsmsg_encode();

    return;
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    itsmsg_example(0);
    return 0;
}
