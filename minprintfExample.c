#include <stdio.h>
#include <stdarg.h>
void minprintf(char *fmt,...);
int main(){
    char store[15];
    sprintf(store,"hello world");
    puts(store);
    minprintf("hello %d %f %s can you deal with this though?",21,32.596,"World");
}

void minprintf(char *fmt,...){
    va_list ap;//refers to each argument in turn, argument pointer
    char *p,*sval;//two character pointers, an int and a double, uninitialised
    int ival;
    double dval;
    va_start(ap,fmt);//initialises ap to point to the first unnamed argument
    for(p=fmt;*p;p++){
        if(*p != '%'){
            //if ! % read char and break out of for loop
            putchar(*p);
            continue;
        }
        switch(*++p){// implicitly if *p == % run this switch, increment pointer to get argument type
            case 'd':
                ival = va_arg(ap,int);//move ap to next argument,of type int if D, other cases do the same thing but for floats and strings
                printf("%d",ival);
                break;
            case 'f':
                dval = va_arg(ap,double);
                printf("%f",dval);
                break;
            case 's':
                for(sval = va_arg(ap,char *);*sval;sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);//"does whatever cleanup is necessary"
    printf("\n");
}
