def processLine(line):
    numbers = line.strip("\n").split("\t");

    result = None;

    for number in numbers:
        currentNumber = number;

        for num in numbers:
            if currentNumber != num:
               if int(currentNumber) % int(num) == 0:
                   result = int(currentNumber) / int(num);
    
    return result;

def main():
    file = open("./DayOne/InputTwo.txt", "rt");

    sum = 0;
    
    for line in file:
        sum += processLine(line);

    print("Result: ", sum);

if __name__ == '__main__':
    main();