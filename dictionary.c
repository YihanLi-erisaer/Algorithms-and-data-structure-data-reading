/* dictionary.c
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

#include "dictionary.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

list_t* create_dictionary(FILE* in_file){
	// create a empty list
    list_t* dictionary = make_empty_list();

	//create a buffer
	char* buffer = malloc(sizeof(char) * (MAX_LINE_LENGTH + 1));
	assert(buffer);

	//skip header
	fgets(buffer, MAX_LINE_LENGTH + 1, in_file);

	//read file line by line
	while (fgets(buffer, MAX_LINE_LENGTH + 1, in_file) != NULL){
		//read as a struct pointer
		record_t* record = read_record(buffer);
		//store the struct pointer to the noode in linked list
        dictionary = insert_at_foot(dictionary,record);
	}

    free(buffer);
    return dictionary;
}

// Search in the dictionary to match the query
void search_query(FILE* out_file, char* query, list_t* dictionary, int *count){
    node_t* curr = dictionary->head;

    // Create a pointer point to the previous query
    char* prev_query = NULL;
    while (curr){
        // Detect is there any dictionary that match the query
        if (strcmp(curr->data->trading_name, query) == 0){

            // Detect is there is a same query input in the function
            //  if there is do not print trading name and 
            //  the count of resturant plus 1
            if (prev_query == NULL || strcmp(prev_query, query) != 0) {
                printf("%s --> ", curr->data->trading_name);
                fprintf(out_file, "%s\n", curr->data->trading_name);
                prev_query = strdup(query);
            }
            (*count)++;  // Increment count using parentheses
            print_record(out_file, curr->data);
        }
        curr = curr->next;
    }
    free(prev_query);
}

// Frees the memory that allocated to dictionary
void free_dictionary(list_t* dictionary){
    node_t* curr = dictionary->head;
    while (curr) {
        record_t* record = curr->data;
        free_record(record);
        curr = curr->next;
    }
    free_list(dictionary);
}

