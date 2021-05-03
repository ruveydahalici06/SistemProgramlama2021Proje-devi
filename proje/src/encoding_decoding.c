/**
*Sistem Programlama Proje Odevi
* @file : encoding_decoding.c
* @description : reads an input file, and then writes to the output as encrypted or decrypted
* @assignment : System Programming Project
* @startdate : 02.05.2021
* @author : Burak Cevik
*/

#include"encoding_decoding.h"
#include <stdlib.h>
#include <string.h>

ED make_endecode(char endecode,const char *i_name,const char* o_name)
{
    ED ed;
    ed=(ED)malloc(sizeof(struct endecode));

    ed->i_name=strdup(i_name);
    ed->o_name=strdup(o_name);

    ed->is=new_inputstruct(ed->i_name);
    
    /*print error if file does not exist*/
    if (ed->is == NULL) {
        perror(ed->i_name);
        exit(1);
    }

    ed->output_fp=fopen(ed->o_name,"wb");

  if(endecode=='e'){
    ed->encode_or_decode='e';
    ed->tree=create_tree_for_encode();/*create tree for encode.*/
  }
  else if(endecode=='d'){
     ed->encode_or_decode='d';
    ed->tree=create_tree_for_decode();/*create tree for decode*/
  }

    return ed;
}
