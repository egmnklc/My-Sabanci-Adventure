import numpy as np
import matplotlib.pyplot as plt

# Define the 8 indexes
x1 = np.array([5, 6, 7, 8, 9, 10, 11, 12])
y1 = np.array([0.001000, 0.001000, 0.004001, 0.174034, 0.688000, 6.994029, 41.957264, 1122.891128])

# Calculate the slope and y-intercept of the best fitting line
plt.plot(x1, y1, 'o-', label='Randomized p value')

# Generate example data
x2 = np.array([5, 6, 7, 8, 9, 10, 11, 12])
y2 = np.array([0.000000, 0.001994, 0.027001, 0.179032, 1.646999, 16.297032, 244.668612, 3269.944757])

# Create a line graph
plt.plot(x2, y2, 'o-', label='p = 1')


x1 = np.array([5, 6, 7, 8, 9, 10, 11, 12])
y1 = np.array([0.001000, 0.001000, 0.004001, 0.174034, 0.688000, 6.994029, 41.957264, 1122.891128])

# Calculate the slope and y-intercept of the best fitting line
plt.plot(x1, y1, 'o-', label='Randomized p value')

# Add labels and title
plt.xlabel('Number of nodes in graph (n)')
plt.ylabel('Running time in seconds(s)')
plt.title('Comparison of Randomized p value and p = 1')

# Add legend
plt.legend()

# Display the plot
plt.show()

1
16
162
1536
15000
155520
1728720
20643840