#ifndef READ_JSON
#define READ_JSON

#define MAX_WORDS 500
#define MAX_CHAR 100

#include "jrb.h"
#include "fields.h"

JRB create_tree_for_decode();
JRB create_tree_for_encode();
void remove_spaces(char *str);
char *extract_quotes(char *s);
int parse_then_add(char *data, JRB tree, char mode);
int file_exists(IS is);
#endif
