def processLine(line):
    words = line.strip("\n").split(" ");

    passPhrases = dict();

    for word in words:
        if word in passPhrases:
            passPhrases[word] += 1;
        else:
            passPhrases[word] = 0;

    isValid = True;

    for key, value in passPhrases.items():
        if value > 0:
            isValid = False;
    
    return isValid;
    

def main():
    # file = open("./DayFour/DayFourPartOneTest.txt", "rt");
    file = open("./DayFour/DayFourPartOneInput.txt", "rt");

    validPassPhrases = 0;

    for line in file:
        if(processLine(line)):
            validPassPhrases += 1;

    print(validPassPhrases);

if __name__ == '__main__':
    main();