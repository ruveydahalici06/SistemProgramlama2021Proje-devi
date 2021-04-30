#define MAX_WORDS 500
#define MAX_CHAR 100

#include "jrb.h"
#include "fields.h"

JRB create_tree_for_decode();
JRB create_tree_for_encode();
void extract_between_quotes(char* s, char* dest);

