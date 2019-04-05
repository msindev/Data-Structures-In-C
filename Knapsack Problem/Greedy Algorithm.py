
def greedy_programming(number, capacity, weight_cost):

	ratios = []
	for index, item in enumerate(weight_cost):
		ratios.append((index, item[1]/float(item[0])))
	ratios = sorted(ratios, key = lambda x: x[1], reverse = True)
	best_combination = [0] * number
	best_cost = 0
	weight = 0
	for index, ratio in ratios:
		if weight_cost[index][0] + weight <= capacity:
			weight += weight_cost[index][0]
			best_cost += weight_cost[index][1]
			best_combination[index] = 1

	return best_cost, best_combination

n = int(input('Enter number of elements in KnapSack: '))
capacity = int(input('Enter capacity of KnapSack: '))

weight_cost = []

for i in range(n):
	weight = int(input('Enter weight of element {}: '.format(i+1)))
	cost = int(input('Enter cost of element {}: '.format(i+1)))
	weight_cost.append((weight, cost))

best_cost, best_combination = greedy_programming(n, capacity, weight_cost)

print('The best cost obtained is: {}'.format(best_cost))

print('The corresponding combination is: ')
print(best_combination)
element_list = []
for i in range(len(best_combination)):
	if best_combination[i] == 1:
		element_list.append(i+1)

print('The selected elements are: ')
print(element_list)
