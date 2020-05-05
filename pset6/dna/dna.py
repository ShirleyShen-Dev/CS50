from sys import argv, exit
import csv
import re
import pandas


def main():
    # Ensure 3 command line arguments are entered
    if len(argv) == 3:

        # Open text file of unknown's DNA sequence
        with open(argv[2], "r") as sequenceFile:
            mysterySequence = csv.reader(sequenceFile)
            mysteryDNA = str(next(mysterySequence))

        matchRow = {}
        same = 0
        outputID = "No Match"
        
        # Open DNA database as a dictionary reader
        with open(argv[1], "r") as dataFile:
            dnaDatabase = csv.DictReader(dataFile)
            
            # For each column in each row not equal to "name"
            for row in dnaDatabase:
                same = 0
                for col in row:
                    if not col in ["name"]:
                        # Compare STR database value against max repeat of same STR in Unkown's DNA sequence
                        if int(row[col]) == int(maxRepeat(col, mysteryDNA)):
                            same += 1
                
                # Find ID of person with all matching max repeat of STRs
                if same == int(len(row) - 1):
                    matchRow = row
                    outputID = matchRow["name"]
                    break
        
        print(outputID)

    # Check for number of command line arguments
    else:
        print("Usage: python dna.py database.csv sequence.txt")
        exit(1)
        

def maxRepeat(STR, unknownSequence):

    pattern = STR

    # List index of first character of pattern for every instance the pattern appears in mysteryDNA
    indices = [m.start() for m in re.finditer(rf"{pattern}", unknownSequence)]

    # Counter for number of consecutive repeats
    counter = 1

    # Variable storing max consecutive repeats
    max = 1 

    # No matching STR found
    if len(indices) == 0: 
        max = 0
        return max

    # One matching STR found
    elif len(indices) == 1: 
        max = 1
        return max

    # Multiple matching STR found
    else: 
        for i in range(len(indices)-1):
            # Increment counter if a consecutive repeat is found
            if indices[i+1] - indices[i] == len(pattern):
                counter += 1
                if counter > max:
                    max = counter
                else:
                    max = max
             # Reset counter if consecutive repeat ends
            else:
                counter = 1
                if counter > max:
                    max = counter
                else:
                    max = max

        return max


main()