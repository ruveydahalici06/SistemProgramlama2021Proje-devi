/**
*Sistem Programlama Proje Odevi
* @file : encoding_decoding.c
* @description : reads an input file, and then writes to the output as encrypted or decrypted
* @assignment : System Programming Project
* @startdate : 02.05.2021
* @author : Burak Cevik
*/

#include"encoding_decoding.h"

ED make_endecode(const char* encode_or_decode,const char *i_name,const char* o_name)
{	
    if(strcmp(encode_or_decode,"-e")!=0 && strcmp(encode_or_decode,"-d")!=0){/* if parameter is not equal to -e and -d, exit */
    	printf("\nInvalid mode\n");
    	exit(1);  
    }
    
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

    ed->output_fp=fopen(ed->o_name,"w");

  if(strcmp(encode_or_decode,"-e")==0){ /*if parameter is -e start encryption process*/
    ed->encode_or_decode=strdup(encode_or_decode); /*assigment to struct variable*/
    ed->tree=create_tree_for_encode();/*create tree for encode.*/
  }
  else if(strcmp(encode_or_decode,"-d")==0){	/*if parameter is -e start decryption process*/
    ed->encode_or_decode=strdup(encode_or_decode);/*assigment to struct variable*/
    ed->tree=create_tree_for_decode();/*create tree for decode*/
  }

    return ed;
}

/* start encoding or decoding depend on parameters. */
void start_endecode(ED ed)
{
    if (is_encode(ed)==1){
      printf("\nEncryption process is about to begin. Output file name will be \"%s\"\n", ed->o_name);
    }
    else{
      printf("\nDecryption process is about to begin. Output file name will be \"%s\"\n", ed->o_name);
    }

    JRB temp_tree; // to get values
    int i=0;

    while(get_line(ed->is) >= 0) /*read file line by line*/
    {
      for (i = 0; i < ed->is->NF; i++) /* read words */
      {
        temp_tree= jrb_find_str(ed->tree,ed->is->fields[i]); /*check if reading value is in the tree */
        char buf[1000]; 
       
        if (temp_tree==NULL) /*if value is not found. */
        {
          int len= snprintf(buf, sizeof buf, "%s %s", ed->is->fields[i],"");/*format(reading_value ) */
          if(fwrite(buf, len,1 , ed->output_fp)!= 1){ // write to file if there is no error
            perror("Write error");
            exit(1);
          }       
        }
        
        else{/*if value is found*/
          int len= snprintf(buf, sizeof buf, "%s %s", temp_tree->val.s,"");/*format(encrypted_or_decrypted_value */
          if(fwrite(buf, len,1 , ed->output_fp)!= 1){  // write file if there is no error
            perror("Write error\n");
            exit(1);
          }
        }
    }
  }   
    printf("\nProcess is successfully finished.\n\n");
}

int is_encode(ED ed)/*return 1 if it is encode, return 0 if it is decode*/
{
  if (strcmp(ed->encode_or_decode,"-e")==0)
  {
    return 1;
  }
  else if (strcmp(ed->encode_or_decode,"-d")==0)
  {
    return 0;
  }
  else{/*print error if parameter is not e or d*/
       printf("Invalid parameter.\n");
       exit(1);
  }   
}

void free_ed(ED ed)/*delete and free struct ED*/
{
  if(ed!=NULL){
      free(ed->i_name);
      free(ed->o_name);
      jettison_inputstruct(ed->is);
      jrb_free_tree(ed->tree);
      free(ed->encode_or_decode);
      fclose(ed->output_fp);
      free(ed);
  }
}
