# Black Jack 2020 // Josh Cunningham 
import random
import time
from colored import fg, bg, attr


# Randomly selects a "card from the deck" and checks that the card still exists in the deck (it hasn't been pulled 4 times already)
def drawCard(cardCount, deck, recipient): 
    cardNumber = random.randint(2,14)
    # Make sure the card is still in the deck
    while cardDeck[str(cardNumber)] == 0:
        cardNumber = random.randint(2,14)
    
    if (cardNumber <= 10):
        print(recipient + "'s " + str(cardCount) + " card is " + str(cardNumber) + ".")
        cardDeck[str(cardNumber)] -= 1
        return cardNumber
    else:
        if (cardNumber == 11 and recipient == "Player"):
            aceChoice = int(input("You got an Ace. Do you want it to be a 1 or an 11: "))
            print()
            while (aceChoice != 1 and aceChoice != 11):
                aceChoice = int(input("Please enter either 1 or 11: "))
            cardDeck[str(cardNumber)] -= 1
            return int(aceChoice)
        elif (cardNumber == 11 and recipient == "Dealer"):
            print(recipient + "'s " + str(cardCount) + " card is a Ace.")
            cardDeck[str(cardNumber)] -= 1
            cardNumber = 11
            return int(cardNumber)
        elif (cardNumber == 12):
            print(recipient + "'s " + str(cardCount) + " card is a Jack.")
            cardDeck[str(cardNumber)] -= 1
            cardNumber = 10
            return int(cardNumber)
        elif (cardNumber == 13):
            print(recipient + "'s " + (cardCount) + " card is a Queen.")
            cardDeck[str(cardNumber)] -= 1
            cardNumber = 10
            return int(cardNumber)
        elif (cardNumber == 14):
            print(recipient + "'s " + (cardCount) + " card is a King.")
            cardDeck[str(cardNumber)] -= 1
            cardNumber = 10
            return int(cardNumber)
    print()

# Checks if the player has busted yet and, if not, asks for whether they want to hit or stand
def playerHitorStand(playerScore):
    if (playerScore <= 21):
        playerChoice = input("Hit or Stand: ")
        while (playerChoice != "Hit" and playerChoice != "hit" and playerChoice != "HIT" and playerChoice != "Stand" and playerChoice != "STAND" and playerChoice != "stand"):
            playerChoice = input("Please enter either Hit or Stand: ")
        print()
        playerChoice = playerChoice.upper()
    else:
        playerChoice = "BUST"
    return playerChoice

# Start of Game
totCards = 52
red = fg('red') + bg('black')
green = fg('green') + bg('black')
blue = fg('blue') + bg('black')
reset = attr('reset')
global cardDeck
cardDeck = {"1": 4, "2": 4, "3": 4, "4": 4, "5": 4, "6": 4, "7": 4, "8": 4, "9": 4, "10": 4, "11": 4, "12": 4, "13": 4, "14": 4} # Where 11 = Ace, 12 = Jack, 13 = Queen, and 14 = King
cardCount = ['First', 'Second', 'Third', 'Fourth', 'Fifth']
balance = 1000
game = ""
profit = 0
# A Game
while(balance > 1 and game != "DONE"):
    # A Hand
    print()
    handOver = False  
    playerBust = False
    bet = int(input("You have " + str(balance) + " chips. How much would you like to bet: "))
    while(bet > balance):
        bet = int(input("You don't have enough chips for that bet. Enter another bet: "))
    while(type(bet) != int):
        bet = int(input("Please enter a whole number: "))
    playerFirstCard = drawCard(cardCount[0], cardDeck, "Player")
    playerSecondCard = drawCard(cardCount[1], cardDeck, "Player")
    playerScore = int(playerFirstCard) + int(playerSecondCard)   
    print("Player's Score: " + str(playerScore) + "\n")
    if (playerScore == 21):
        print(green + "BLACKJACK!" + reset)
        handOver = True
        balance += (1.5 * bet)
    dealerFirstCard = drawCard(cardCount[0], cardDeck, "Dealer")
    double = input("Would you like to double (Yes or No): ")
    double = double.upper()
    while (double != "YES" and double != "NO"):
        double = input("Please enter either Yes or No: ")
        double = double.upper()
    if (double == "YES"):
        bet = bet * 2
    
    print()
    
    # Loops for player's second, third, fourth, etc card until they stand or bust
    while (handOver == False):
        counter = 2
        if (double == "YES"):
                nextCard = drawCard(cardCount[counter], cardDeck, "Player")
                playerScore = int(playerScore) + int(nextCard)
                print("Player's Score: " + str(playerScore))
                handOver = True
        else:
            playerChoice = playerHitorStand(playerScore)
            if (playerChoice == "HIT" and counter != 5 and playerScore < 21):
                nextCard = drawCard(cardCount[counter], cardDeck, "Player")
                playerScore = int(playerScore) + int(nextCard)
                print("Player's Score: " + str(playerScore))
                
            elif (playerChoice == "STAND" or counter == 5 or playerScore == 21):
                handOver = True
            
            elif (playerChoice == "BUST"):
                print(red + "Player Busts.\n" + reset)
                handOver = True
                playerBust = True
            
        counter = counter + 1
    print("Player's Final Score: " + str(playerScore) + "\n")
    
    # Determine results of hand by comparing scores
    if (playerBust == True):
        print(red + "House wins the hand. \n" + reset)
        balance -= bet
    elif (playerBust == False):
        dealerSecondCard = drawCard(cardCount[1], cardDeck, "Dealer")
        dealerScore = dealerFirstCard + dealerSecondCard
        dealerCounter = 2
        while (dealerScore < 16 and dealerCounter < 5):
            dealerNextCard = drawCard(cardCount[dealerCounter], cardDeck, "Dealer")
            dealerScore = dealerScore + dealerNextCard
            dealerCounter = dealerCounter + 1
        print("Dealer's Final Score: " + str(dealerScore) + "\n")
        if (dealerScore > 21 or playerScore > dealerScore):
            print(green + "Player wins the hand.\n" + reset)
            balance += bet
        elif (dealerScore > playerScore):
            print(red + "House wins the hand.\n" + reset)
            balance -= bet
        else:
            print(blue + "Push.\n" + reset)   
    time.sleep(3)
    print("Balance: " + str(balance) + "\n")
    if (balance == 0):
        game = "DONE"
    else:
        game = input("Would you like to keep playing? (Yes or No): ")
        game = game.upper()
        if (game != "YES" and game != "NO"):
            game = input("Please enter either Yes or No: ")
        game = game.upper()
        if game == "NO":
            game = "DONE"

print()
# End of Game Results
if (balance > 1000):
    profit = balance - 1000
    print(green + "Congrats, you made " + str(profit) + " chips!" + reset)
elif (balance < 1000):
    profit = 1000 - balance
    print(red + "Sorry, the House wins again. You lost " + str(profit) + " chips." + reset)
else:
    print(blue + "You broke even... not bad." + reset)