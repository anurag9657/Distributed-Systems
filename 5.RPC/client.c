#include <rpc/rpc.h>
#include "prog.h"
#include<stdio.h>
#include<stdlib.h>

void main(int argc,char *argv[])
{
 CLIENT *cl;
 mul_in in;
mul_out *outp, *outp1;

if(argc!=4)
printf("error message");

 cl=clnt_create(argv[1],MUL_PROG,MUL_VERS,"TCP");

in.arg1=atol(argv[2]);
in.arg2=atol(argv[3]);
 outp=mulproc_1(&in,cl);

outp1=add_proc_1(&in,cl);
printf("result:%ld\n",outp->res);

printf("result:%ld\n",outp1->res);
exit(0);

}

