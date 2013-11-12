#include <cstdio>

int main()
{
    int c, pc, ppc;

    ppc = getchar();
    pc = getchar();

    putchar(ppc);
    putchar(pc);

    for (;;) {
        c = getchar();
        if (c == '\n' || c == EOF)
            break;

        if ((c == pc) && (c == ppc))
            continue;

        int fc;
        if (pc == ppc) {
            while ((fc = getchar()) == c)
                ;
            ungetc(fc, stdin);
        }

        putchar(c);

        ppc = pc;
        pc = c;
    }
    putchar('\n');
    return 0;
}
