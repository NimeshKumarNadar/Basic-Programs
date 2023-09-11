l = []
n = int(input("Enter no. of elements in list : "))
for i in range(0,n) :
    value = eval(input("Enter value in the list : "))
    l.append(value)
#Traversing
print(" ")
print("List = ",l)


# Reversing
l = l[::-1]
print(" ")
print("Reverse of given list is : ",l)


# Bubble Sorting
for i in range(0,n-1) :
    for j in range(0,n-1) :
        if(l[j]>l[j+1]) :
            temp = l[j]
            l[j] = l[j+1]
            l[j+1] = temp
print(" ")
print("Sorted list is : ",l)
print(" ")


# Maximum element
max = -1
for i in range(n):
    if(max < l[i]) :
        max = l[i]
print("Maximum element = ",max)
print(" ")


# Minimum element
min = 99999999
for i in range(n):
    if(min > l[i]) :
        min = l[i]
print("Minimum Element = ",min)

# Remove duplicates
l1 = []
size = 1
temp = 0
l1.append(l[0])
for i in range(n):
    for j in range(size):
        if(l[i]==l1[j]):
            temp = 1
        else:
            temp = 0
    if(temp == 0):
        l1.append(l[i])
        size = size + 1
print("\nList after removal of duplicate element : ",l1



l1 = []
l2 = []
n1 = int(input("Enter no. of element in list 1 : "))
print("Enter elements : ")
for i in range (n1):
    value = eval(input(""))
    l1.append(value)
n2 = int(input("Enter no. of element in list 1 : "))
print("Enter elements : ")
for i in range (n2):
    value = eval(input(""))
    l2.append(value)
print("First List : ",l1)
print("Second List : ",l2)
l = l1 + l2
print("\nAddition of both lists : ",l)