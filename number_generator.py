import random

def number_generator():
	"""Generates a sequence of numbers."""
	numbers = random.sample(range(0, 500), 100)
	print(' '.join(map(str, numbers)))

if __name__ == '__main__':
	number_generator()
