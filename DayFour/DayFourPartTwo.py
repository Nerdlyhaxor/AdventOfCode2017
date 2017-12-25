def processLine(line):
    words = line.strip("\n").split(" ");

    passPhrases = dict();

    for word in words:
        newWord = "".join(sorted(list(word)));        
        if word in passPhrases:
            passPhrases[newWord] += 1;
        else:
            passPhrases[newWord] = 0;

    isValid = True;

    for key, value in passPhrases.items():
        if value > 0:
            isValid = False;
    
    return isValid;
    

def main():
    file = open("./DayFour/DayFourPartTwoTest.txt");

    validPassPhrases = 0;

    for line in file:
        if(processLine(line)):
            print(line, " - Valid!");
        else:
            print(line, " - Not Valid!");
            # validPassPhrases += 1;

    # print(validPassPhrases);

if __name__ == '__main__':
    main();