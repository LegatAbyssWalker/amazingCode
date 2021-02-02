import random
from sys import setrecursionlimit

username = input("What is your name?\n")
timesTheLoopWent = 0
whoWillBeFirst = random.randint(0, 1)
symbolAssigner = random.randint(0, 1)
global symbol
symbol = ""
global computerSymbol
computerSymbol = ""
global maxTimesTheLoopWent
maxTimesTheLoopWent = 0
cell = [0, 1, 2,
        3, 4, 5,
        6, 7, 8]
setrecursionlimit(int(999999999))


def whoWillGoFirst() -> str:
    global maxTimesTheLoopWent
    if whoWillBeFirst == 0:
        maxTimesTheLoopWent = 4
        return f"{username} will go first"
    elif whoWillBeFirst == 1:
        maxTimesTheLoopWent = 5
        return "I am first"


def computerMoves():
    for i in range(4):
        try:
            computerMove = random.randint(0, 8)
            if int(cell[computerMove]):
                    cell[computerMove] = computerSymbol
        except ValueError:
            computerMoves()

def assignSymbol():
    global symbol
    global computerSymbol
    if symbolAssigner == 0:
        print("Your symbol is X")
        symbol = "X"
        computerSymbol = "O"
    else:
        print("Your symbol is O")
        symbol = "O"
        computerSymbol = "X"


print(f"Let's play some Tic Tac Toe, {username}")
whoWillGoFirst()
assignSymbol()
print(f"{symbol} selected")
while not timesTheLoopWent == maxTimesTheLoopWent:
    if maxTimesTheLoopWent == 4:
        computerMoves()

    else:
        coordinate = int(input("Enter the coordinate of your symbol:\n"))
        cell[coordinate - 1] = symbol
        computerMoves()
    cell_str = str(cell[0]) + " " + str(cell[1]) + " " + str(cell[2]) + "\n" + \
               str(cell[3]) + " " + str(cell[4]) + " " + str(cell[5]) + "\n" + \
               str(cell[6]) + " " + str(cell[7]) + " " + str(cell[8]) + "\n"
    print(cell_str)
    timesTheLoopWent += 1
