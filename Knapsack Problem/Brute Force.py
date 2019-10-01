from itertools import combinations

def brute_force(number, capacity, weight_cost):
	best_cost = None
	best_combination = []

	for i in range(1,number+1):
		for comb in combinations(weight_cost, i): #generate combinations of length from 1 to n 
			temp = list(combinations(weight_cost, i))
			weight = sum(wc[0] for wc in comb) #Sum of all weights in combination
			cost = sum(wc[1] for wc in comb) #Sum of all costs in combination
			temp_index = []
			for item in comb:
					temp_index.append(weight_cost.index(item)+1)
			print('Combination: {}   Weight = {}  Cost = {}'.format(temp_index, weight, cost))
			if(best_cost is None or best_cost < cost) and weight <= capacity: #If best_cost is less, reinitialize the Knapsack
				best_cost = cost
				best_combination = [0]* number #Assign 0 to full array
				for wc in comb:
					best_combination[weight_cost.index(wc)] = 1 #Set the value to 1 which we want in KnapSack.
	return best_cost, best_combination

n = int(input('Enter number of elements in KnapSack: '))
capacity = int(input('Enter capacity of KnapSack: '))

weight_cost = []

for i in range(n):
	weight = int(input('Enter weight of element {}: '.format(i+1)))
	cost = int(input('Enter cost of element {}: '.format(i+1)))
	weight_cost.append((weight, cost))

best_cost, best_combination = brute_force(n, capacity, weight_cost)

print('The best cost obtained is: {}'.format(best_cost))

print('The corresponding combination is: ')
print(best_combination)
element_list = []
for i in range(len(best_combination)):
	if best_combination[i] == 1:
		element_list.append(i+1)

print('The selected elements are: ')
print(element_list)
