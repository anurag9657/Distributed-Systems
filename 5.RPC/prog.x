struct mul_in{
long arg1;
long arg2;
};

struct mul_out{
long res;
};

program MUL_PROG{
         version MUL_VERS{
                   mul_out MULPROC (mul_in)=1;
                   mul_out ADD_PROC(mul_in)=2;
                         }=1;
                }=0x31230000;
                             
