# SFU ID: 301613547
# Computing ID: dcs7
# Name: Daniel Smith

def replace_digits_recursive(number: int, target: str, replacement: str):
    negative = 0
    
    if number < 0:
        negative = 1 # Raise negative flag
        number = -number # Make number positive temporarily
    
    if (target < '0' or target > '9' or replacement < '0' or replacement > '9'):
        return number # Returns original number when input is invalid.
    
    # Base Case
    if number == 0:
        return 0 # Returns 0 if the number is 0.
    
    # Extracting last digit of the number
    last_digit = number % 10
    if last_digit == int(target):
        last_digit = int(replacement)
    
    # Calling recursive function over the rest of the number
    rest_of_number = replace_digits_recursive(number // 10, target, replacement)
    
    if rest_of_number is None:
        rest_of_number = 0
    
    result = rest_of_number * 10 + last_digit
    
    # Reverting number to negative if flag was raised
    if negative == 1:
        result = -result

    return result

print(replace_digits_recursive(1, '1', '2'))
print(replace_digits_recursive(-232, '3', '0'))
print(replace_digits_recursive(123, '4', '5'))
print(replace_digits_recursive(1223, '!', '?'))