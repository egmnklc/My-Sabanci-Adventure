---
Date: Thursday 04-13-2023 | 11:54:33
Updated at: Thursday 04-13-2023 | 11:54:36
---
# Gaussian Bayes Classifier
> The Gaussian Naive Bayes Classifier is a variant of the Naive Bayes Classifier, a popular probabilistic classification algorithm based on Bayes' theorem. The Gaussian Naive Bayes Classifier specifically assumes that the features in the dataset follow a Gaussian (or normal) distribution. This assumption makes it particularly suitable for continuous data.
>
> In the Gaussian Naive Bayes Classifier, the probability distribution of each feature within a class is modeled as a Gaussian distribution with a certain mean and variance. The algorithm calculates the mean and variance for each feature within each class from the training data. Once the parameters are estimated, the classifier uses Bayes' theorem to predict the class of a new, unseen data point.
>
> Despite its simplicity and the strong assumptions it makes about feature independence and distribution, the Gaussian Naive Bayes Classifier often performs surprisingly well in practice. It is especially effective when the dataset has a large number of features or when the training data is limited.
>
> To summarize, the Gaussian Naive Bayes Classifier is a probabilistic classification algorithm that assumes the features follow a Gaussian distribution and calculates class probabilities based on Bayes' theorem. It is simple, fast, and often performs well on datasets with continuous features or limited training data.
>

## Normal (Gaussian) Distribution
> 1D Normal distribution is defined by its mean μ and variance σ² as: 
> $$N(x | \mu, \sigma^2) $$
> - It gives is the probability density at any point x under Normal distribution with the given two parameters.
>   - When we work with multidimensional data, the mean (μ) we have will be multidimensional as well. 

## Mahalanobis Distance
> Distance measure:
> 
> : `The Mahalanobis distance is a statistical measure that quantifies the distance between a point and a distribution, taking into account the correlations between variables.`
>
> It us is particularly useful when dealing with multivariate data and is commonly used in various fields such as pattern recognition, classification, and anomaly detection. 


# Parametric Classification
>