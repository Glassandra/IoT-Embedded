import random

allowed_words = ["rock", "scissor", "paper"]

rules = { 
    "rock": "scissor",
    "scissor": "paper",
    "paper": "rock"
}

computer_word = allowed_words[random.randrange(0,3)]
while(True):    
    text = input('Choose rock, paper or scissors: ').lower()
    if text in allowed_words:
        break
print(f"Player: {text}")
print(f"Computer choice: {computer_word}")

if text == computer_word:
    print("It's a tie")
elif rules[text] == computer_word:
    print("Player wins!")
else:
    print("Computer wins!")
print("Game Over!")