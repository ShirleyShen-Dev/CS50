#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;


int main(int argc, char *argv[])
{

    // Check that only 1 argument is entered in command line
    if (argc != 2)
    {
        printf("Usage: ./recover sourcefile \n");
        return 1;
    }
    
    
    // Open source file to read and ensure it can be opened
    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL)
    {
        return 1;
    }
    
    // Declared a buffer BYTE array that will have 512 bytes
    BYTE block[512];
    
    // Declare a counter for number of JPEGs
    int jpeg_counter = 0;
    
    
    // Create a string for file name and allocate memory (including null). Ensure memory allocated is not NULL

    
    // Declare file pointer for output
    FILE *output;
    
    // Declare filename pointer
    char *filename = malloc(8 * sizeof(char));
        
    if (filename == NULL)
    {
        return 1;
    }
    
    while (fread(block, sizeof(BYTE), 512, source_file) == 512)
    {

    

        // JPEG header is found
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            // Increment jpeg counter if JPEG header is found
            jpeg_counter++;
            
            // If first jpeg found, do the following
            if (jpeg_counter == 1)
            {
                // Create filename based on jpeg # found
                sprintf(filename, "%03i.jpg", jpeg_counter - 1);
                
                // Open new file for writing
                output = fopen(filename, "w");
                
                // Write to output file
                fwrite(block, sizeof(BYTE), 512, output);
                
            }
            // If not first jpeg found
            else 
            {
                fclose(output);
                
                // Create filename that is dynamically naming the jpeg # found
                sprintf(filename, "%03i.jpg", jpeg_counter - 1);
    
                // Open new file
                output = fopen(filename, "w");
                    
                // Write to new file
                fwrite(block, sizeof(BYTE), 512, output);
            }

        }
        
        // If block doesn't have jpeg header...
        else
        {
            if (jpeg_counter > 0)
            {
                // Write to existing file next 512 bytes
                fwrite(block, sizeof(BYTE), 512, output);
            }
        }

     
    }
    free(filename);
    fclose(output);
    fclose(source_file);

}
