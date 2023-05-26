import subprocess
import random

# Ask user for number of generated numbers
num_of_numbers = int(input("Enter the number of generated numbers: "))

# Ask user for range of generated numbers
range_start = int(input("Enter the start of the range: "))
range_end = int(input("Enter the end of the range: "))

# Ask user for number of runs
num_of_runs = int(input("Enter the number of runs: "))

# Write the title to the output file
title = "#" * 50 + "\nTest Runs ({} numbers, range {}-{})\n".format(num_of_numbers, range_start, range_end) + "#" * 50
with open('test_runs.txt', 'a') as f:
    f.write(title + "\n")

# List to store the line count outputs for each run
line_counts = []

# List to store test run numbers with wc -l output count of 1
test_runs_with_count_of_1 = []

# Loop for each run
for run in range(1, num_of_runs + 1):
    # Generate a list of unique random numbers within the specified range
    random_numbers = random.sample(range(range_start, range_end + 1), num_of_numbers)

    # Convert the list of numbers to a string with space-separated values
    numbers_string = ' '.join(str(num) for num in random_numbers)

    # Call the push_swap C program with the random numbers as arguments
    process = subprocess.Popen(['./push_swap'] + list(map(str, random_numbers)), stdout=subprocess.PIPE)

    # Pipe the output of push_swap to wc -l for line count
    wc_process = subprocess.Popen(['wc', '-l'], stdin=process.stdout, stdout=subprocess.PIPE)

    # Redirect the output of wc -l to the file with the description
    with open('test_runs.txt', 'a') as f:
        f.write("Test Run {}:\n".format(run))
        f.write("Generated numbers: {}\n".format(numbers_string) + "\n")  # Write the list of generated numbers to the file with a newline
        f.write("Output of wc -l:\n")
        wc_output = wc_process.communicate()[0].decode()  # Get the output of wc -l as a string
        f.write(wc_output + "\n")  # Write the output of wc -l to the file with a newline
        line_count = int(wc_output.strip())  # Get the line count as an integer
        line_counts.append(line_count)  # Add the line count to the list for later calculation

        # Check if line count is 1 and add test run number to the list if so
        if line_count == 1:
            test_runs_with_count_of_1.append(run)

    # Wait for the processes to complete
    process.wait()
    wc_process.wait()

# Calculate the average of all line counts
average_line_count = sum(line_counts) / num_of_runs

# Append the average line count to the output file
with open('test_runs.txt', 'a') as f:
    f.write("Average Line Count: {}\n".format(average_line_count))

print("\nAverage Line Count: {}".format(average_line_count))
# Print test run numbers with wc -l output count of 1
if len(test_runs_with_count_of_1) > 0:
    print("Test runs with wc -l output count of 1: {}".format(test_runs_with_count_of_1))
else:
    print("No test runs with wc -l 1 output count of 1 \n")