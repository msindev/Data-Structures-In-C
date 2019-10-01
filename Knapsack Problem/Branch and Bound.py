from collections import deque

class SimpleQueue(object):
    def __init__(self):
        self.buffer = deque()

    def push(self, value):
        self.buffer.appendleft(value)

    def pop(self):
        return self.buffer.pop()

    def __len__(self):
        return len(self.buffer)

class Node(object):
    def __init__(self, level, selected_items, cost, weight, bound):
        self.level = level
        self.selected_items = selected_items
        self.cost = cost
        self.weight = weight
        self.bound = bound

def branch_and_bounds(number, capacity, weight_cost):
    priority_queue = SimpleQueue()

    #sort items in non-increasing order by profit/weight
    ratios = [(index, item[1] / float(item[0])) for index, item in enumerate(weight_cost)]
    ratios = sorted(ratios, key=lambda x: x[1], reverse=True)

    best_so_far = Node(0, [], 0.0, 0.0, 0.0)
    a_node = Node(0, [], 0.0, 0.0, calculate_bound(best_so_far, number, capacity, weight_cost, ratios))
    priority_queue.push(a_node)

    while len(priority_queue) > 0:
        curr_node = priority_queue.pop()
        if curr_node.bound > best_so_far.cost:
            curr_node_index = ratios[curr_node.level][0]
            next_item_cost = weight_cost[curr_node_index][1]
            next_item_weight = weight_cost[curr_node_index][0]
            next_added = Node(
                curr_node.level + 1,
                curr_node.selected_items + [curr_node_index],
                curr_node.cost + next_item_cost,
                curr_node.weight + next_item_weight,
                curr_node.bound
            )

            if next_added.weight <= capacity:
                if next_added.cost > best_so_far.cost: #If its cost is greater we add it.
                    best_so_far = next_added

                if next_added.bound > best_so_far.cost: #If bound is greater add to the tree
                    priority_queue.push(next_added)

            next_not_added = Node(curr_node.level + 1, curr_node.selected_items, curr_node.cost,
                                  curr_node.weight, curr_node.bound)
            next_not_added.bound = calculate_bound(next_not_added, number, capacity, weight_cost, ratios)
            if next_not_added.bound > best_so_far.cost:
                priority_queue.push(next_not_added)

    best_combination = [0] * number
    for wc in best_so_far.selected_items:
        best_combination[wc] = 1
    return int(best_so_far.cost), best_combination


def calculate_bound(node, number, capacity, weight_cost, ratios):
    if node.weight >= capacity: #Not feasible don't calculate
        return 0
    else:
        upper_bound = node.cost
        total_weight = node.weight
        current_level = node.level

        while current_level < number: #Less than total items
            current_index = ratios[current_level][0] #weight of the item

            if total_weight + weight_cost[current_index][0] > capacity:
                cost = weight_cost[current_index][1] #value
                weight = weight_cost[current_index][0] #weight of the item
                upper_bound += (capacity - total_weight) * cost/weight
                break

            upper_bound += weight_cost[current_index][1]
            total_weight += weight_cost[current_index][0]
            current_level += 1

        return upper_bound


n = int(input('Enter number of elements in KnapSack: '))
capacity = int(input('Enter capacity of KnapSack: '))

weight_cost = []

for i in range(n):
    weight = int(input('Enter weight of element {}: '.format(i+1)))
    cost = int(input('Enter cost of element {}: '.format(i+1)))
    weight_cost.append((weight, cost))

bestvalue, result = branch_and_bounds(n, capacity, weight_cost)

print('The best cost obtained is: {}'.format(bestvalue))

print('The corresponding combination is: ')
print(result)
element_list = []
for i in range(len(result)):
    if result[i] == 1:
        element_list.append(i+1)

print('The selected elements are: ')
print(element_list)
