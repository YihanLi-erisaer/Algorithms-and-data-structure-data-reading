/* linked_list.h
*
* Created by Yihan Li (yihanl13@student.unimelb.edu.au)
15/08/2023
*
* Proeject: dict1
* linked_list.c: The implementation of buid linked list, insert to linked list
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

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "record.h"

typedef record_t* data_t;
typedef struct node node_t;

struct node {
    data_t data;
    node_t *next;
};

typedef struct {
	node_t *head;
	node_t *foot;
} list_t;

// function definitions
// Return a initialized linked list pointer
list_t *make_empty_list(void);

// Detect whether is the linked list empty or not
//  if is empty return 1 else return 0
int is_empty_list(list_t *list);

// Frees the memory that is used by linked list
void free_list(list_t *list);

// Insert the input data at the head of the input linked list
list_t *insert_at_head(list_t *list, data_t value);

// Insert the input data at the foot of the input linked list
list_t *insert_at_foot(list_t *list, data_t value);

// Return the value of the head node of the input linked list
data_t get_head(list_t *list);

// Remove the head of the input linked list
list_t *get_tail(list_t *list);

#endif

