import random

def number_generator():
	"""Generates a sequence of numbers."""
	numbers = random.sample(range(-10, 11), 10)
	print(' '.join(map(str, numbers)))

if __name__ == '__main__':
	number_generator()