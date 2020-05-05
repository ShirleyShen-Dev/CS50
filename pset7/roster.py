from sys import argv, exit
import cs50


def main():
    if len(argv) == 2:
        house = argv[1]

        # Open student DB for reading
        open(f"students.db", "r")
        db = cs50.SQL("sqlite:///students.db")
        
        roster = db.execute("SELECT first, middle, last, birth FROM students WHERE house =? ORDER BY last, first", house)
        
        for row in roster:
            first = row["first"]
            middle = row["middle"]
            last = row["last"]
            birth = row["birth"]
        
            if middle != None:
                print(f"{first} {middle} {last}, born {birth}")
            else:
                print(f"{first} {last}, born {birth}")
    else:
        print("Usage: python roster.py house")
        exit(1)
   
        
main()