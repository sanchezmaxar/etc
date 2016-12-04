n=raw_input("n: ")
k=raw_input("k: ")

i=0
tot=1
while i <(n-k):
	tot*=n-k+1
	i+=1
print(tot)
