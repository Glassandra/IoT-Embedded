#
#   Uppgift 1
#
def fizzbuzz(x = 100):
    for i in range(1,x+1):
        text = str(i) + " "
        if i%3 == 0:
            text += "Fizz"
        if i%5 == 0:
            text += "Buzz"
        print(text)

fizzbuzz(1003)

#
#   Uppgift 2
#
def skott_ar(year):
    return (year%4 == 0 and year%100 != 0) or year%400 == 0

print("Är det skottår" + skott_ar(1996))