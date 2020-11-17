import random
import string
import csv
from random import randint

def generate_nos(num_testcases, size):
	ret_list = [int(''.join(["%s" % randint(0, 9) for _ in range(0, size)])) for _ in range(num_testcases)]
	return ret_list

def generate_strings(num_testcases, size, flag):
	if flag:
		ret_list = [''.join(random.choice(string.ascii_uppercase) for _ in range(size)) for _ in range(num_testcases)]
	else:
		ret_list = [''.join(random.choice(string.ascii_lowercase) for _ in range(size)) for _ in range(num_testcases)]
	return ret_list

def generate_dates(num_testcases):
	ret_list = []
	for _ in range(num_testcases):
		mm = str(generate_nos(1, 2)[0]%12 + 1)
		if len(mm) == 1:
			mm = "0" + mm
		yyyy = str(generate_nos(1, 4)[0]%25 + 2017)
		ret_list.append(mm + "/" + yyyy)
	return ret_list

def write_to_file(filename, final_list):
	with open(filename, "w") as output:
		writer = csv.writer(output, lineterminator = "\n")
		for val in final_list:
			writer.writerow([val])

def main(num_testcases):
	first_name = generate_strings(num_testcases, 10, False)
	cgpa = generate_nos(num_testcases, 6)
	final_list = [first_name + " " + str(cgpa) for first_name, cgpa in zip(first_name,cgpa)]
	# print(final_list)
	filename = str(num_testcases)
	write_to_file(filename, final_list)

if __name__ == '__main__':
	num_testcases = 10
	main(num_testcases)
