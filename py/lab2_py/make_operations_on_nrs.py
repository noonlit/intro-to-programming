# Adds up numbers from input until zero is received. Prints sum.
def printSumUntilZeroIsRead():
	sum = 0;
	nr = None;

	while nr != 0:
		print("Enter a number: ");
		nr = input();
		nr = int(nr);
		sum += nr;

	print("Sum is: " + str(sum));

# printSumUntilZeroIsRead();

# Prints divisors of number read fom input.
def printDivisorsAndSumOfDivisors():
		print("Enter a number:");
		nr = input();
		nr = int(nr);

		sum = 0;
		i = 1;

		# freaking python for loops.
		# for i in [0..nr]:
		# use while so you don't just make a list for no reason at all.
		while i <= nr:
			if nr % i == 0:
				print("Divisor was found: " + str(i));
				sum += i;
			i += 1;

		print("The sum of divisors is: " + str(sum));

# printDivisorsAndSumOfDivisors();

# Prints a count of the prime numbers given as input.
def printPrimeCount():
	print("How many numbers?");
	n = input();
	n = int(n);

	primeCount = 0;
	i = 0;

	while i < n:
		print("Enter a number:");
		nr = input();
		nr = int(nr);
		
		if isPrime(nr):
			primeCount += 1; 
			i += 1;
	
	print(primeCount);

# Naive implementation for checking if a number is prime
def isPrime(nr):
	if nr <= 1:
		return false;

	i = 2;

	while (i < nr):
		# TODO condition and check

		i += 1;

	return true;