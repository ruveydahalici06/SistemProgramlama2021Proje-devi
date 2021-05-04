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

#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"
/*
    creates red black tree for decoding mode and returns it.
    usage: JRB tree=create_tree_for_decode();
*/
JRB create_tree_for_decode(); 

/*
    creates red black tree for encoding mode and returns it.
    usage: JRB tree=create_tree_for_encode();
*/
JRB create_tree_for_encode();

/*
    removes spaces from the given string
    usage: str="   ayb erk" -> remove_spaces(str) -> str="ayberk"
*/
void remove_spaces(char *str); 

/*
    extracts the value betwwen double quotes
    i won't use char* variable for better explanation.
    do not forget for usage in the program
    you should pass a char* parameter to the function.

    example:  "ayberk." -> extract_quotes() -> ayberk
*/
char *extract_quotes(char *s);

/*
    parse the given string and add it to the RBT.
    usage: for encoding RBT parse_then_add(line,tree,'e')
            for decoding RBT parse_then_add(line,tree,'d')
*/
int parse_then_add(char *data, JRB tree, char mode); 

int file_exists(IS is); //check file exists or not
#endif