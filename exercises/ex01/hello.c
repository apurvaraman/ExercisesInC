#include <stdio.h>

int main() {
  int x = 5;
  int y = x + 1;
  printf("%i \n", y);
}

/*
Code that corresponds to int x = 5
        movl	$5, -4(%rbp)

1. The optimized version made it much shorter.
pushq	%rbp			rep ret
                .cfi_def_cfa_offset 16
                .cfi_offset 6, -16
                movq	%rsp, %rbp
                .cfi_def_cfa_register 6
                movl	$5, -4(%rbp)
                popq	%rbp
                .cfi_def_cfa 7, 8
                ret

    was replaced with just the line

    rep ret

Other information has been slightly changed (there's now a .p2align and a
.text.startup instead of just .text)

I'm not sure exactly what's that's doing (nothing?)
x was never used, so I guess that's okay?

2. With the printf line, the two versions are a bit closer. The optimized one is
more concise, doing a few neat little things like jmp __printf_chk instead of
call printf and consolidating the mov instructions

3. The optimized version doesn't hold on to the value of x. It appears that y
has already been evaluated in terms of x by the optimization to avoid having to
store x.

Optimization appears to eliminate unused data and do some clever little
shortcuts whenever it can.


*/
