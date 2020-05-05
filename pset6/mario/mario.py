from cs50 import get_int

# Initiate height variable from user input
while True:
    height = get_int("Height: ")
    
    # If not in range of 0 to 8, continue prompt for input
    if not 0 < height <= 8:
        continue
    
    # If in range, print mario hill
    else:
        for i in range(0, height):
            # Printing void
            for j in range(height - 1 - 1, i - 1, -1):
                print(" ", end="")
            
            # Printing left hill
            for k in range(0, i + 1):
                print("#", end="")
            
            # Printing gap
            if i >= 0: 
                print("  ", end="")
            else:
                continue
                
            # Printing right hill
            for l in range(0, i + 1):
                print("#", end="")
                
            if i >= 0:
                print("")
            else: 
                continue
        break
