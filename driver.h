/* driver.h
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

#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <stdio.h>

//define constant
#define MAX_LINE_LENGTH 512

//function prototype
void stage1(FILE* in_file, FILE* out_file);

#endif
