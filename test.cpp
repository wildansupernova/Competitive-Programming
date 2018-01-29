#include <stdio.h>
#include <string.h>
void foo(char *s){

int buf[1];

strcpy((char *)buf ,s );

printf("%s",buf);

}


int main(){

foo("aaaa");
}
