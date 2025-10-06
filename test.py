def yieldAllCombos(items):
    """
      Generates all combinations of N items into two bags, whereby each 
      item is in one or zero bags.

      Yields a tuple, (bag1, bag2), where each bag is represented as 
      a list of which item(s) are in each bag.
    """

    n = len(items)
    
    for i in range(3**n):
        bag1 = []
        bag2 = []
        j = i
        bit = 0
        while j > 0:
            if j % 3 == 1:
                bag1.append(items[bit])
            elif j % 3 == 2:
                bag2.append(items[bit])
            j //= 3
            bit += 1
            
        yield (bag1, bag2)

print(list(yieldAllCombos([1,2,3])))
print(len(list(yieldAllCombos([1,2,3]))))