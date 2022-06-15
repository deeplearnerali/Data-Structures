#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selection_sort(int array[], int array_len);  // Is void because arrays get passed by reference
void print_numbers(int array[], int array_len);

int main(int argc, char **argv){
    
    char* file_name = "RandomNumbers100000.txt";

    read_file(file_name);
    return 0;

    // The array to sort:
    int array[] = {
        12, 3, 1, 4, 7, 3, 2, 1, 3, 4, 5, 2, 1, 12, 24, 10, 19, 21, 28
    };    
    int array_len = sizeof(array)/sizeof(array[0]);

    printf("Sorting list...");

    selection_sort(array, array_len);

    printf("Sorted list: \n");
    print_numbers(array, array_len);
    return 0;
}

void print_numbers(int array[], int array_len){
    printf("\n\n\n");
    for(int i = 0; i < array_len; i++){
        printf("%d\n", array[i]);
    }
    printf("\n\n\n");
}

void selection_sort(int array[], int array_len){
    int temp = 0;
    int min_num = 0;
    int compare_num = 0;
    int smallest_num_index = 0;

    /* can this be turned into a recursive function? */
    for(int i = 0; i < array_len; i++){
        smallest_num_index = i;
        for(int j = i+1; j < array_len; j++){
            min_num = array[smallest_num_index];
            compare_num = array[j];
            if(compare_num <= min_num){
                min_num = compare_num;
                smallest_num_index = j;
            }
        }
        // swap if the smallest_num_index has changed, otherwise, ignore
        if(smallest_num_index != i){
            temp = array[smallest_num_index]; // holds smallest number
            array[smallest_num_index] = array[i]; // swap the smallest with larger
            array[i] = temp; // swap larger with smallest
        }
    }

    return;
}