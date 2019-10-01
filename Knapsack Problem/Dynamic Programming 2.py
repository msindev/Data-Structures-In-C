
def dynamic_programming(number, capacity, weight_cost):
	value = [[0 for i in range(capacity+1)] for i in range(number+1)]

	for i in range(number+1):
		for w in range(capacity+1):
			if i==0 or w==0:
				value[i][w] = 0
			elif weight_cost[i-1][0] <= w:
				value[i][w] = max(weight_cost[i-1][1] + value[i-1][w-weight_cost[i-1][0]], value[i-1][w])
			else:
				value[i][w] = value[i-1][w]

	print('Knapsack Table:')
	for k in value:
		print(*k)

	return value[number][capacity]

def dynamic_matrix(number, capacity, weight_cost):

	def bestvalue(i,j):
		if i == 0:
			return 0
		weight, cost = weight_cost[i-1]
		if(weight > j):
			return bestvalue(i-1,j)
		else:
			return max(bestvalue(i-1,j), bestvalue(i-1, j-weight) + cost)

	j = capacity
	result = [0]*number
	for i in range(len(weight_cost), 0, -1):
		if bestvalue(i,j) != bestvalue(i-1,j):
			result[i-1] = 1
			j -=  weight_cost[i-1][0]
	return result


n = int(input('Enter number of elements in KnapSack: '))
capacity = int(input('Enter capacity of KnapSack: '))

weight_cost = []

for i in range(n):
	weight = int(input('Enter weight of element {}: '.format(i+1)))
	cost = int(input('Enter cost of element {}: '.format(i+1)))
	weight_cost.append((weight, cost))

best_cost = dynamic_programming(n, capacity, weight_cost)

print('The best cost obtained is: {}'.format(best_cost))

print('The corresponding combination is: ')
result = dynamic_matrix(n, capacity, weight_cost)
print(result)
element_list = []
for i in range(len(result)):
	if result[i] == 1:
		element_list.append(i+1)

print('The selected elements are: ')
print(element_list)
