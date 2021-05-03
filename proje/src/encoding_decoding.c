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

/* start encoding or decoding depend on parameters. */
void start_endecode(ED ed){
    if (is_encode(ed)==1){
      printf("\nEncryption process is about to begin. Output file name will be \"%s\"\n", ed->o_name);
    }
    else{
      printf("\nDecryption process is about to begin. Output file name will be \"%s\"\n", ed->o_name);
    }

    JRB temp_tree; // to get values
    int i=0;

    while(get_line(ed->is) >= 0) 
    {
      for (i = 0; i < ed->is->NF; i++) 
      {
        temp_tree= jrb_find_str(ed->tree,ed->is->fields[i]);
        char buf[MAX_CHAR]; /*MAX_CHAR = 100*/
       
        if (temp_tree==NULL) /*if value is not found. */
        {
          int len= snprintf(buf, sizeof buf, "%s %s", ed->is->fields[i],"");
          if(fwrite(buf, len,1 , ed->output_fp)!= 1){
            perror("Write error");
          }       
        }
        
        else{/*if value is found*/
          int len= snprintf(buf, sizeof buf, "%s %s", temp_tree->val.s,"");
          if(fwrite(buf, len,1 , ed->output_fp)!= 1){
            perror("Write error\n");
          }
        }
    }
  }   
    printf("\nProcess is successfully finished.\n\n");
}

int is_encode(ED ed){/* return 1 if process is encode. return 0 if it is decode*/
  if (ed->encode_or_decode=='e')
  {
    return 1;
  }
  else if (ed->encode_or_decode=='d')
  {
    return 0;
  }
  else{/*print error if parameter is not e or d*/
       perror("Invalid parameter.\n");
       exit(1);
  }   
}
