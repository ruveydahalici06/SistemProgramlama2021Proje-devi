#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_json.h"
void extract_between_quotes(char* s, char* dest)
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
void create_tree_for_decode(JRB b){ //key 01
    IS is;

    /* Create the JRB and the inputstruct */
    is = new_inputstruct(".kilit");

    /* Read each line and insert it into the jrb as a key, and with NULL as the val. */

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

}
void create_tree_for_encode(JRB b){//key selam
    IS is;

    /* Create the JRB and the inputstruct */
    is = new_inputstruct(".kilit");

    /* Read each line and insert it into the jrb as a key, and with NULL as the val. */

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
}
