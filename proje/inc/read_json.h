#define MAX_WORDS 500
#define MAX_CHAR 100

#include "jrb.h"
#include "fields.h"

void create_tree_for_decode(JRB b);
void create_tree_for_encode(JRB b);
void extract_between_quotes(char* s, char* dest);

