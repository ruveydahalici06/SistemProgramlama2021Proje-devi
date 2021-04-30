#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_json.h"
void extract_between_quotes(char* s, char* dest) //extracts the string between double quotes for example "word" will be extracted as word.
{
   int in_quotes = 0;
   *dest = 0;
   while(*s != 0)
   {
      if(in_quotes)
      {
         if(*s == '"') return;
         dest[0]=*s;
         dest[1]=0;
         dest++;
      }
      else if(*s == '"') in_quotes=1;
      s++;
   }
}
JRB create_tree_for_decode(){ //creating red black tree for decode mode
    JRB b = make_jrb();
    IS is;

    is = new_inputstruct(".kilit");

    while (get_line(is) >= 0) {
        if(strchr( is->text1, '{')==NULL && strchr( is->text1, '}')==NULL){
        char *value = strtok(is->text1, ":");
        char *key=strtok(NULL,":");
        char *new_value=malloc(MAX_CHAR);
        char *new_key=malloc(MAX_CHAR);
        extract_between_quotes(value,new_value);
        extract_between_quotes(key,new_key);
        (void) jrb_insert_str(b, strdup(new_key), new_jval_s(new_value));

        }
    }
    return b;

}
JRB create_tree_for_encode(){ //creating red black tree for encode mode
    IS is;
    JRB b = make_jrb();

    is = new_inputstruct(".kilit");

    while (get_line(is) >= 0) {
        if(strchr( is->text1, '{')==NULL && strchr( is->text1, '}')==NULL){
        char *key = strtok(is->text1, ":");
        char *value=strtok(NULL,":");
        char *new_key=malloc(MAX_CHAR);
        char *new_value=malloc(MAX_CHAR);
        extract_between_quotes(key,new_key);
        extract_between_quotes(value,new_value);
        (void) jrb_insert_str(b, strdup(new_key), new_jval_s(new_value));

        }
    }
    return b;
}
