n = int(input("Enter your number:"))
g=1
while n>0:
    a = n % 10
    g += a
    a = n//10

print("The number you entered:",n)
print("Product:",g)

