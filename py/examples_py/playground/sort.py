# quicksort
def quicksort(array):
	# base case (arrays with 0 or 1 elements can be considered sorted)
	if len(array) < 2:
		return array

	# most algorithms choose either first or last element
	pivot = array[0]

	# split array
	less = [i for i in array[1:] if i <= pivot]
	greater = [i for i in array[1:] if i > pivot]

	return quicksort(less) + [pivot] + quicksort(greater)


print(quicksort([2, 10, 5, 3, 30, 1, 4]));