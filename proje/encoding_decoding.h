/**
*Sistem Programlama Proje Odevi
* @file : encoding_decoding.h
* @description : reads an input file, and then writes to the output as encrypted or decrypted
* @assignment : System Programming Project
* @startdate : 02.05.2021
* @author : Burak Cevik
*/

#ifndef _ENCODINGDECODING_
#define _ENCODINGDECODING_
#include "read_json.h"

typedef struct endecode{
    char *encode_or_decode; /* -e for encode, -d for decode */
    char *i_name;/*input file name*/
    char *o_name;/*output file name*/
    IS is;/*to reads file*/
    FILE *output_fp;/*output file descriptor*/
    JRB tree;
}*ED;

 /*creates ED. additionally this function creates JRB;
    paramaters: 
 ENCODE/DECODE(e-d), INPUT FILE NAME, OUTPUT FILE NAME */
ED make_endecode(const char*, const char*,const char*);

/* start encoding or decoding depend on parameters. */
void start_endecode(ED);

/* return 1 if it is encode, return 0 
if it is decode. otherwise print error*/
int is_encode(ED);

/*clean heap memory*/
void free_ed(ED);

#endif


