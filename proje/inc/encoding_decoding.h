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
    char encode_or_decode; /* e for encode, d for decode */
    char *i_name;/*input file name*/
    char *o_name;/*output file name*/
    IS is;/*for input file*/
    FILE *output_fp;/*output file descriptor*/
    JRB tree;
}*ED;

 /*additionally this function creates JRB
    paramaters: 
 ENCODE/DECODE(e-d), INPUT FILE NAME, OUTPUT FILE NAME */
ED make_endecode(char, const char*,const char*);

/* start encodin or decoding depend on parameters. */
void start_endecode(ED);

/*do encode and create encrypted file*/
void do_encoding(ED);

/*do decode and create descryted file*/
void do_decoding(ED);

/* return 1 if it is encode, return 0 
if it is decode. otherwise print error*/
int is_encode(ED);

/*clear heap memory*/
void free_ed(ED);


#endif


