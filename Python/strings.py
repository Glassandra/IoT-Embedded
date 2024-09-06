#
#   UPPGIFT 1
#
def rakna_vokaler(text):
    vokaler = "aeiouåäöAEIOUÅÄÖ"  # Lista på vokaler både små och stora
    count = 0    
    for letter in text:
        if letter in vokaler:
            count += 1
    return count

# Exempel:
text = "Hej världen"
print(rakna_vokaler(text))
# Output: 3

#
#   UPPGIFT 1.2
#
def ta_bort_vokaler(text):
    vokaler = "aeiouåäöAEIOUÅÄÖ"  # Lista på vokaler både små och stora
    for vokal in vokaler:
        text = text.replace(vokal, "")
    return text

# Exempel:
text = "Hej världen"
print(ta_bort_vokaler(text))
# Output: "Hj vrldn"


#
#   Uppgift 2
# 
def till_titel_case(text):
    temp = ""
    for word in text.split(" "):
        temp += word.capitalize() + " "
    return temp

# Exempel:
text = "hej världen"
print(till_titel_case(text))

# Output: "Hej Världen" 



#
#   UPPGIFT 3
#
def rakna_ord(text):
    return len(text.split(" "))
    

# Exempel:
# Input: "Detta är en mening"
# Output: 4
text = "Detta är en mening"
print(rakna_ord(text))