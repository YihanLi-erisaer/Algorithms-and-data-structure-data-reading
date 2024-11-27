/* dictionary.h
*
* Created by Yihan Li (yihanl13@student.unimelb.edu.au)
15/08/2023
*
* Proeject: dict1
* dictionary.c: The implementation of the operations on dictionary
*
* To run the program type: 
* ./dict1 1 tests/dataset_1.csv output.out < tests/test1.in > output.stdout.out
*
* To see all the input parameters, type:
* ./dict1 --help
* Options::
*   --help                Show help message
*   --num_coins arg       Input number of coins
*   --shape_coins arg     Input coins shape
*   --bound arg (=1)      Max bound on xxx, default value 1
*   --output arg          Output solution file
* 
*/

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <stdio.h>
#include "linked_list.h"

#define MAX_LINE_LENGTH 512

// Read data from input file and and return a pointer of a dictionary store
//  the data
list_t* create_dictionary(FILE* in_file);

// Search the keys of dictionary to match the query
void search_query(FILE* out_file, char* query, list_t* dictionary, int *count);

// Frees the memory that is used by dictionary
void free_dictionary(list_t* dictionary);

#endif
