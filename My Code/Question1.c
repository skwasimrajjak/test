#include<stdio.h>

int global=0;
void increment(){
    global++;
}
int main() {
    increment();
    printf("Value of variable: %d", global);
    return 0;
}
   
