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
	cr_card_nos = generate_nos(num_testcases, 16)
	bank_codes = generate_strings(num_testcases, 5, True)
	dates = generate_dates(num_testcases)
	first_names = generate_strings(num_testcases, 5, False)
	last_names = generate_strings(num_testcases, 5, False)
	final_list = [str(card_no) + "," + bank_code + "," + date + "," + first_name + "," + last_name for card_no, bank_code, date, first_name, last_name in zip(cr_card_nos, bank_codes, dates, first_names, last_names)]
	# print(final_list)
	filename = str(num_testcases)
	write_to_file(filename, final_list)

if __name__ == '__main__':
	number_of_testcases = [10 ** i for i in range(1, 6)]
	for num_testcases in number_of_testcases:
		main(num_testcases)
