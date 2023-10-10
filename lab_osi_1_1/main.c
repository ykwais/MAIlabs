#include <stdio.h>
#include "enums.h"
#include "funcs.c"

int main(int argc, char** argv) {

    FILE *file_name = NULL;
    char *name_txt = NULL;

    switch (analysis(argc, argv)) {
        case isc_bad:
            printf("Too little/many arguments");
            break;
        case isc_correct:
            name_txt = argv[1];
            //char byte_sequence[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
            if (task(name_txt)) {
                return 0;
            }
            printf("Error! Troubles with opening or reading the file");
            break;

    }















//    if (argc != 2) {
//        printf("Too little/many arguments");
//        return 0;
//    }
//
//    char byte_sequence[] = { 3,1,4,1,5,9,2,6,5,3,5 };
//
//    FILE *output_file = NULL;
//    if (!(output_file = fopen(argv[1], "w"))) {
//        printf("Error! Troubles with opening the file.");
//        return 0;
//    }
//
//    fwrite(byte_sequence, sizeof(char), sizeof(byte_sequence), output_file);
//
//    fclose(output_file);
//
//
//    FILE *input_file = NULL;
//    if (!(input_file = fopen(argv[1], "r"))) {
//        printf("Error! Troubles with opening the file.");
//        return 0;
//    }
//
//    char one_byte = 0;
//
//    while (fread(&one_byte, sizeof(char), 1, input_file)) {
//        printf_s("%d\n", one_byte);
//        printf("Position of reading pointer: %d\n", ftell(input_file));
//        printf("Reading error: %d\n", ferror(input_file));
//        printf("End of file: %d\n", feof(input_file));
//        printf("Pointer to the beginning of the buffer: 0x%x\n", input_file->_base);
//        printf("The number of remaining bytes in the buffer: %d\n", input_file->_cnt);
//        printf("Buffer Size: %d\n", input_file->_bufsiz);
//        printf("Pointer to the current position in the buffer: 0x%x\n", input_file->_ptr);
//        printf("File descriptor: %d\n", input_file->_file);
//        printf("File status flags: %d\n", input_file->_flag);
//        printf("buffer: %d\n", input_file->_charbuf);
//        printf("temporary file name: %s\n\n", input_file->_tmpfname);
//    }
//
//    fclose(input_file);
//    input_file = NULL;
//
//
//    if (!(input_file = fopen(argv[1], "r"))) {
//        printf("Error! Troubles with opening the file.");
//        return 0;
//    }
//
//    if (fseek(input_file, 3, SEEK_SET)) {
//        printf("error fseek");
//        fclose(input_file);
//        return 0;
//    }
//
//
//    char byte_buffer[4];
//
//    if (4 != fread(byte_buffer, sizeof(char), 4, input_file)) {
//        printf("error freed");
//        fclose(input_file);
//        return 0;
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        printf("%d ", byte_buffer[i]);
//    }
//
//    fclose(input_file);


}
