from cs50 import get_float
import math

# Initialize variables
dollarCents = 100
quarterCents = 25
dimeCents = 10
nickleCents = 5
pennyCents = 1
outstanding = 0
coins = 0


while True:
    dollars = get_float("How much change is owed:\n")
    
    if dollars < 0:
        continue
    
    else:
        outstanding = dollars * dollarCents
        
        # Calculate quarters
        quarters = math.floor(outstanding / quarterCents)
        outstanding -= quarters * quarterCents
        
        # Calculate dimes
        dimes = math.floor(outstanding / dimeCents)
        outstanding -= dimes * dimeCents
        
        # Calculate nickles
        nickles = math.floor(outstanding / nickleCents)
        outstanding -= nickles * nickleCents
        
        # Calculate pennies
        pennies = math.floor(outstanding / pennyCents)
        outstanding -= pennies * pennyCents
        
        print(quarters + dimes + nickles + pennies)
        
        break