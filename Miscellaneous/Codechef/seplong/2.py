
def main():    
    t = int(input(""))
    for i in range(t) :
        arr=list(map(int,input().split()))
        n = 0
        r = 0
        array=list(map(int,input().split(' ')))
        mergeSort(array)
        for i in range(0,arr[0]):
            if array[i] == array[arr[1] - 1]:
                n += 1
                if i > arr[1] - 1:
                    r += 1
        print(int(nCr(n, n - r)))

def nCr(n, r):
    return fact(n)/(fact(r) * fact(n - r))

def fact(n):
    fact = 1
    for i in range(1,n + 1):
        fact *= i
    return fact


def mergeSort(arr): 
    if len(arr) >1: 
        mid = len(arr)//2 #Finding the mid of the array 
        L = arr[:mid] # Dividing the array elements  
        R = arr[mid:] # into 2 halves 
  
        mergeSort(L) # Sorting the first half 
        mergeSort(R) # Sorting the second half 
  
        i = j = k = 0
          
        # Copy data to temp arrays L[] and R[] 
        while i < len(L) and j < len(R): 
            if L[i] < R[j]: 
                arr[k] = L[i] 
                i+=1
            else: 
                arr[k] = R[j] 
                j+=1
            k+=1
          
        # Checking if any element was left 
        while i < len(L): 
            arr[k] = L[i] 
            i+=1
            k+=1
          
        while j < len(R): 
            arr[k] = R[j] 
            j+=1
            k+=1
  
# Code to print the list 
def printList(arr): 
    for i in range(len(arr)):         
        print(arr[i],end=" ") 
    print() 


main()
