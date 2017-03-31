#include "prog.h"
#include<stdio.h>
#include<stdlib.h>


mul_out *mulproc_1_svc(mul_in *argp,struct svc_req *rqstp)
 {
  static mul_out result;
  result.res=((argp->arg1 )* (argp->arg2));
 return(&result);
}
mul_out *add_proc_1_svc(mul_in *argp,struct svc_req *rqstp)
 {
  static mul_out result;
  result.res=((argp->arg1 )+ (argp->arg2));
 return(&result);
}

