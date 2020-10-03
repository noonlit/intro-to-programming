# Read n nrs from keyboard and return them.
def getInput():
	print('How many numbers?');
	count = input(); 
	count = int(count);

	numbers = [];
	i = 0;
	while i < count:
		print('Enter a number!');
		number = input();
		number = int(number);
		numbers.append(number);
		i += 1;

	return numbers;

# Take a bunch of numbers. Sum up the even and odd ones separately. Print result.
def printEvenAndOddSums(numbers):
	oddSum = 0;
	evenSum = 0;
	for i in numbers:
		if (i%2 == 0):
			evenSum += i;
			continue;
		oddSum += i;

	print('Odd sum is: ' + str(oddSum));
	print('Even sum is: ' + str(evenSum));

#input = getInput();
#printEvenAndOddSums(input);