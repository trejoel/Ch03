def factorial (n):
	fac=1
	for y in range(1,n+1):
		fac=fac*y
	print ("El factorial de",n," es ", fac)

def main():
	factorial(5)


if __name__ == "__main__":main()
