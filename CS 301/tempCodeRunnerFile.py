degree = 2
coeffs = np.polyfit(x, y, degree)
poly = np.poly1d(coeffs)

# Generate x values for the fitted polynomial
x_fit = np.linspace(x.min(), x.max(), 100)
y_fit = poly(x_fit)

# Create a line graph
plt.plot(x, y, 'o-', label='Data')
plt.plot(x_fit, y_fit, label='Fitted Polynomial')

# Add labels and title
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Polynomial Fitting')

# Add legend
plt.legend()

# Display the graph
plt.show()