from sys import argv, exit
import cs50
import csv


def main():
    # Ensure 2 command line arguments are entered
    if len(argv) == 2:

        # Create an empty database
        open(f"students.db", "w").close()
        db = cs50.SQL("sqlite:///students.db")
        
        # Specify database header titles
        db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")
        
        # Open CSV file specified in command line
        with open(argv[1], "r") as students:
            
            # Create a dictReader
            reader = csv.DictReader(students)
            
            for row in reader:
                
                # Parsing names
                nameElements = row["name"].split()
                if len(nameElements) == 3:
                    # INSERT INTO DB
                    first = nameElements[0]
                    middle = nameElements[1]
                    last = nameElements[2]
                else:
                    first = nameElements[0]
                    middle = None
                    last = nameElements[1]
                
                # Parsing other fields
                house = row["house"]
                birth = row["birth"]
                
                # Insert parsed values into DB
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", 
                           first, middle, last, house, birth)

    else:
        print("Usage: python import.py file.csv")
        exit(1)
        
        
main()