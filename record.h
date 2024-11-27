/* record.h
*
* Created by Yihan Li (yihanl13@student.unimelb.edu.au)
15/08/2023
*
* Proeject: dict1
* record.c: Build the data structure and read in data to record
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

#ifndef _RECORD_H_
#define _RECORD_H_

#include<stdio.h>

// define the data structure
typedef struct {
    int census_year;
    int block_id;
    int property_id;
    int base_property_id;
    char* building_address;
    char* clue_small_area;
    char* business_address;
    char* trading_name;
    int industry_code;
    char* industry_description;
    char* seating_type;
    int number_of_seats;  
    double longitude;
    double latitude;
} record_t;

// function prototypes
// Read in data from the line of file and wirte in record
record_t* read_record(char* line);

// Print the data in record to the output file
void print_record(FILE* file, record_t* record);

// Frees the memory of the record
void free_record(record_t* record);

#endif
