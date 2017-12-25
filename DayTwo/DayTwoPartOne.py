def processLine(line):
    numbers = line.strip("\n").split(" ");

    max = None;
    min = None;

    for number in numbers:
        num = int(number);

        if(min == None):
            min = num;
        elif(min > num):
            min = num;

        if(max == None):
            max = num;
        elif(max < num):
            max = num;

    return max - min;


def main():
    file = open("./DayOne/InputTestOne.txt", "rt");

    sum = 0;

    for line in file:
        sum += processLine(line);

    print(sum);

if __name__ == '__main__':
    main();