/**
Sistem Programlama Proje Odevi
* @file : read_json.c
* @description : reading .kilit file and extracting requested values.
* @assignment : System Programming Project
* @startdate : 01.05.2021
* @author : Ayberk KOSE
*/

#include "read_json.h"

int file_exists(IS is) //check if the .kilit file exists
{
    if (is == NULL)
    {
        return 0;
    }
    return 1;
}
int parse_then_add(char *data, JRB tree, char mode) //parse the string and get the essential value then add it to the red black tree
{
    if (strchr(data, ':') == NULL) //json file bad format error
    {
        return 0;
    }
    char *key = extract_quotes(strtok(data, ":"));
    char *value = extract_quotes(strtok(NULL, ":"));

    if (mode == 'e')
    {
        (void)jrb_insert_str(tree, strdup(key), new_jval_s(strdup(value)));
    }
    else
    {
        (void)jrb_insert_str(tree, strdup(value), new_jval_s(strdup(key)));
    }
    free(key);
    free(value);

    return 1;
}
char *extract_quotes(char *s) //removes double quotes from the string
{
    char *buff = (char *)(malloc(strlen(s)));
    int quotes_count = 0;
    if (s[0] == '"')
    {
        s++;
        quotes_count++;
    }
    int i = strlen(s) - 1;
    while (i > 0)
    {
        if (s[i] == '"')
        {
            s[i] = 0;
            quotes_count++;
            break;
        }
        i--;
    }
    if (quotes_count != 2)
    {
        printf("Json dosyasi bozuk.\n");
        exit(EXIT_SUCCESS);
    }
    strcpy(buff, s); //buff has more space than s so there is no danger using strcpy
    return buff;
}
void remove_spaces(char *str) //removing spaces from each line
{
    const char *d = str;
    do
    {
        while (*d == ' ')
        {
            ++d;
        }
    } while (*str++ = *d++);
}
JRB create_tree_for_decode() //creating tree for decode
{
    JRB b;
    IS is;
    is = new_inputstruct(".kilit");
    b = make_jrb();
    if (!file_exists(is))
    {
        printf("Kilit dosyasi yok.\n");
        exit(EXIT_SUCCESS);
    }
    printf("\nRed Black Tree building process has started for decoding mode.\n");

    int control;
    while (get_line(is) >= 0)
    {
        remove_spaces(is->text1);

        if (strlen(is->text1) == 1) //if line is empty
            continue;
        if (strchr(is->text1, '{') != NULL)
        {

            char *data = strtok(is->text1, "{");
            if (*data == '\n')
            {
                continue;
            }
            control = parse_then_add(data, b, 'd');
            if (control == 0)
            {
                printf("Json dosyasi bozuk.\n");
                exit(EXIT_SUCCESS);
            }
        }
        else if (strchr(is->text1, '{') == NULL && strchr(is->text1, '}') == NULL)
        {

            control = parse_then_add(is->text1, b, 'd');
            if (control == 0)
            {
                printf("Json dosyasi bozuk.\n");
                exit(EXIT_SUCCESS);
            }
        }
        else if (strchr(is->text1, '}') != NULL)
        {
            char *data = strtok(is->text1, "}");

            if (data == NULL)
                continue;
            control = parse_then_add(is->text1, b, 'd');
            if (control == 0)
            {
                printf("Json dosyasi bozuk.\n");
                exit(EXIT_SUCCESS);
            }
        }
    }
    printf("\nRed Black Tree is ready to go.\n");
    return b;
}
JRB create_tree_for_encode() //createing tree for encode mode
{
    JRB b;
    IS is;

    is = new_inputstruct(".kilit");
    b = make_jrb();
    if (!file_exists(is))
    {
        printf("Kilit dosyasi yok.\n");
        exit(EXIT_SUCCESS);
    }
    printf("\nRed Black Tree building process has started for encoding mode.\n");

    int control;
    while (get_line(is) >= 0)
    {
        remove_spaces(is->text1);

        if (strlen(is->text1) == 1)
            continue; //if line is empty
        if (strchr(is->text1, '{') != NULL)
        {

            char *data = strtok(is->text1, "{");
            if (*data == '\n')
            {
                continue;
            }
            control = parse_then_add(data, b, 'e');
            if (control == 0)
            {
                printf("Json dosyasi bozuk.\n");
                exit(EXIT_SUCCESS);
            }
        }
        else if (strchr(is->text1, '{') == NULL && strchr(is->text1, '}') == NULL)
        {

            control = parse_then_add(is->text1, b, 'e');
            if (control == 0)
            {
                printf("Json dosyasi bozuk.\n");
                exit(EXIT_SUCCESS);
            }
        }
        else if (strchr(is->text1, '}') != NULL)
        {
            char *data = strtok(is->text1, "}");

            if (data == NULL)
                continue;
            control = parse_then_add(is->text1, b, 'e');
            if (control == 0)
            {
                printf("Json dosyasi bozuk.\n");
                exit(EXIT_SUCCESS);
            }
        }
    }
    printf("\nRed Black Tree is ready to go.\n");
    return b;
}
