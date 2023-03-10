Input (test.txt):

	circle(0 0, 1.5)
	circle(5 5 1.2)
	circle(5,       2.1,, 0)
	test
	r
	123f
	helloworld

$./main test.txt

Output:
 
	0.00, 0.00, 1.50
	5.00, 5.00, 1.20
	5.00, 2.10, 0.00
	Incorrect str: 'test'
	Incorrect str: 'r'
	Incorrect str: '123f'
	Incorrect str: 'helloworld'
	
