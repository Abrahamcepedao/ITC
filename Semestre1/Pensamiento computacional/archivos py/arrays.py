nums = [1,3,6]
array1 = []
for i in range(len(nums)):
    array2 = []
    array2.append(nums[i])
    array3 = []
    array3.append(nums[i])
    for a in range(len(nums)):
        if nums[a] not in array2:
            array2.append(nums[a])
    for b in range(len(nums)-1,-1,-1):
        if nums[b] not in array3:
            array3.append(nums[b])
    array1.append(array2)
    array1.append(array3)
print(array1)
