/**
Sistem Programlama Proje Ödevi
* @file : read_json.h
* @description : reading .kilit file and extracting requested values.
* @assignment : System Programming Project
* @startdate : 01.05.2021
* @author : Ayberk KÖSE
*/
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
