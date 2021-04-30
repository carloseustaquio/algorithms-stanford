def main():
  numbers = load_numbers()
  counter = [0]
  quick_sort(numbers, 0, len(numbers) - 1, counter)
  print("number of comparisons = " + str(counter))

def quick_sort(numbers, left, right, counter):
  if right - left < 1: return

  counter[0] += right - left

  # choosing the most left element of the subarray to be the index
  pivot = choose_pivot(numbers, left) 
  partition(numbers, pivot, left, right)

  mid = numbers.index(pivot)
  quick_sort(numbers, left, mid - 1, counter)
  quick_sort(numbers, mid + 1, right, counter)
  
def partition(numbers, pivot, left, right):
  i = j = left + 1

  while (j <= right):
    if numbers[j] < pivot:
      swap(numbers, i, j)
      i += 1
    j += 1

  swap(numbers, numbers.index(pivot), i - 1)

def swap(list, i, j):
  tmp = list[i]
  list[i] = list[j]
  list[j] = tmp

def choose_pivot(numbers, position):
  return numbers[position]

def load_numbers():
  file = open("numbers.txt", "r")
  numbers = map(lambda x: int(x), file.read().split("\n"))
  return list(numbers)

main()

# number of comparisons = [162085]