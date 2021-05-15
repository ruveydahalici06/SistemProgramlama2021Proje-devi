/**
*Sistem Programlama Proje Odevi
* @file : main.c
* @description : checks terminal input count if there is 4 input then starts the process.
* @assignment : System Programming Project
* @startdate : 04.05.2021
* @authors : Burak Cevik, Ayberk Kose
*/
#include "encoding_decoding.h"

int main(int argc,char*argv[]){

char *process_value;
char* i_fname;
char* o_fname;

if(argc==4){

    process_value=argv[1];
    i_fname=argv[2];
    o_fname=argv[3];
    
    ED ed=make_endecode(process_value,i_fname,o_fname);
    start_endecode(ed);
    
    free_ed(ed);
}
else{
    printf("The number of parameters is incorrect\n");
}
  
}
