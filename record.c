/* record.c
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

#include "record.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

// Read in data from the line of file and wirte in record
record_t* read_record(char* line){

    // Create a pointer point to a record and allocate memory
    record_t* record = malloc(sizeof(record_t));
    assert(record);
	char** fields = malloc(sizeof(char*) * 14);
    assert(fields);
    char* buffer_field = malloc(sizeof(char) * (128 + 1));
    assert(buffer_field);

    // Create counter for the loops
    int field_index = 0;
    int field_length = 0;
    int in_quote = 0;
    char *p = line;
	
    // Test is the p is a string
    while(*p != '\0' && *p != EOF && *p != '\n'){
        // When detect a comma seperate the string
        if (*p == ',' && in_quote == 0){
            buffer_field[field_length] = '\0';
            fields[field_index] = malloc(sizeof(char)*(field_length + 1));
            assert(fields[field_index]);
            strcpy(fields[field_index],buffer_field);
            field_index++;
            field_length = 0;
        }
        else if(*p == '"'){
            if (in_quote == 0){
                in_quote = 1;
            }else{
                in_quote = 0;
            }
        }
        else{
            buffer_field[field_length] = *p;
            field_length++;
        }
        p++;
    }

    // Copy the last field since no ','
    buffer_field[field_length] = '\0';
    fields[field_index] = malloc(sizeof(char)*(field_length + 1));
    assert(fields[field_index]);
    strcpy(fields[field_index],buffer_field);

    // Store each field into struct
    char* end_pointer;
    record->census_year = atoi(fields[0]);
    record->block_id = atoi(fields[1]);
    record->property_id = atoi(fields[2]);
    record->base_property_id = atoi(fields[3]);
    record->building_address = strdup(fields[4]);
    record->clue_small_area = strdup(fields[5]);
    record->business_address = strdup(fields[6]);
    record->trading_name = strdup(fields[7]);
    record->industry_code = atoi(fields[8]);
    record->industry_description = strdup(fields[9]);
    record->seating_type = strdup(fields[10]);
    record->number_of_seats = atoi(fields[11]);
    record->longitude = strtod(fields[12], &end_pointer);
    record->latitude = strtod(fields[13], &end_pointer);

    // Free memory
    for (int i = 0; i < 14; i++){
        free(fields[i]);
    }
    free(fields);
    free(buffer_field);
    return record;

}

// Print the data in record to the output file
void print_record(FILE* file, record_t* record){
    fprintf(file, "-->census_year: %d || ",record->census_year);
    fprintf(file, "block_id: %d || ",record->block_id);
    fprintf(file, "property_id: %d || ",record->property_id);
    fprintf(file, "base_property_id: %d || ",record->base_property_id);
    fprintf(file, "building_address: %s || ",record->building_address);
    fprintf(file, "clue_small_area: %s || ",record->clue_small_area);
    fprintf(file, "business_address: %s || ",record->business_address);
    fprintf(file, "trading_name: %s || ",record->trading_name);
    fprintf(file, "industry_code: %d || ",record->industry_code);
    fprintf(file, "industry_description: %s || ",record->industry_description);
    fprintf(file, "seating_type: %s || ",record->seating_type);
    fprintf(file, "number_of_seats: %d || ",record->number_of_seats);
    fprintf(file, "longitude: %.5lf || ",record->longitude);
    fprintf(file, "latitude: %.5lf ||\n",record->latitude);
}

// Free the 6 strings and then the record 
void free_record(record_t* record){
    free(record->building_address);
    free(record->clue_small_area);
    free(record->business_address);
    free(record->trading_name);
    free(record->industry_description);
    free(record->seating_type);
    free(record);
}
