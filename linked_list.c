/* linked_list.c
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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

// Return a initialized linked list pointer
list_t *make_empty_list(void) {

	// Create a pointer point to a linked list
    list_t* list;

    // Allocate memory to the list 
    list = (list_t*)malloc(sizeof(list_t));
    assert(list);
    
    // Initialize the linked list
   	list->head = NULL;
    list->foot = NULL;
    
    return list;
}

// Detect whether is the linked list empty or not
//  if is empty return 1 else return 0
int is_empty_list(list_t *list) {
	assert(list);
    
    // Detect the head pointer of the linked list is Null or not
    if (list->head == NULL) {
        return 1;
    } 
    else {
        return 0;
    }
}

// Frees the memory that is used by linked list
void free_list(list_t *list) {
    assert(list);
    
    // Initialize the pointer to point the linked list that need to free
    node_t* current = list->head;
    node_t* prev;
    
    // Free the linked list that is pointed
    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }
    free(list); 
}

// Insert the input data at the head of the input linked list
list_t* insert_at_head(list_t *list, data_t value) {

    // Create and allocate memory to a new node
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    assert(new_node && list);
    
    // Initialize the data to be the input value
    //  make the new node's next node the head of the linked list
    new_node->data = value;
    new_node->next = list->head;
    // Make the new node to be the head of the linked list
    list->head = new_node;

    // Test whether the linked list only have one node
    if (list->foot == NULL) {
    	list->foot = new_node;    
    }
	return list;
}

// Insert the input data at the foot of the input linked list
list_t *insert_at_foot(list_t *list, data_t value) {

    // Create and allocate memory to a new node
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    assert(new_node && list);
    
    // Initialize the data to be the input value
    //  make the new node's next node the head of the linked list
    new_node->data = value;
    new_node->next = NULL;

    // Test whether the linked list only have one node
    if (list->head == NULL) {
        list->head = new_node;
    } 
    else {
        list->foot->next = new_node;
    }
    // Make the new node become foot node of the linked list
    list->foot = new_node;
    return list;
}	
    
// Return the value of the head node of the input linked list
data_t get_head(list_t *list) {
    assert(list && list->head);
	return list->head->data;
}

// Remove the head of the input linked list
list_t *get_tail(list_t *list) {
    assert(list && list->head);
    node_t* old_head = list->head;

    // Let the pointer point to head be the second node's pointer
    list->head = list->head->next;
    if (list->head == NULL) {
        list->foot = NULL;
    }
    free(old_head);
    return list;
}



