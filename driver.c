/* driver.c
*
* Created by Yihan Li (yihanl13@student.unimelb.edu.au)
15/08/2023
*
* Proeject: dict1
* driver.c: The main program of the project
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

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "linked_list.h"
#include "driver.h"
#include "dictionary.h"
#include "record.h"

int main(int argc, char *argv[]) {
	
	// Make sure to have 4 tokens in the command line 
	if (argc != 4) {
		fprintf(stderr, "Usage: %s input_file_name output_file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Opens input and output file, making sure that 
	//   the filenames given in the command line are valid
	FILE *inFile  = fopen(argv[2], "r"), *outFile = fopen(argv[3], "w");

	//FILE *stdout_output_file = fopen(stdout_output_filename, "a");
	assert(inFile && outFile);          // Exit if fails to open files

	// Implement the stage1 
	stage1(inFile, outFile);

	// Close all the files when everything is done
	fclose(inFile);
	fclose(outFile);
	return 0;
}



void stage1(FILE* in_file, FILE* out_file){
    list_t* dictionary = create_dictionary(in_file);

	// Create a string and ready to read in query from input
    char* query = malloc(sizeof(char) * (128 + 1));
    assert(query);

	// Create a integer in order to count the number of same resturant
    int count = 0; 
    while (1) {

		// Read in the input and write it in query
        if (scanf(" %[^\n]", query) != 1) {
            break;
        }

        // Implement the search_query function to match and print the record
        search_query(out_file, query, dictionary, &count);  // Pass the address of count
        printf("%d\n", count);
        count = 0;
    }
    free(query);
    free_dictionary(dictionary);
}


