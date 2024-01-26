---
Date: Tuesday 03-28-2023 | 08:44:26
Updated at: Thursday 03-30-2023 | 14:45:29
---

![](2023-03-28-08-45-03.png)
# QUIZ QUESTION
> ![](2023-03-28-08-47-39.png)

![](2023-03-28-08-52-52.png)
![](2023-03-28-08-54-22.png)
![](2023-03-28-08-58-21.png)

Validation and test can be fixed because they are both telling about generalization

> Here, N is the # of data points.
![](2023-03-28-09-06-23.png)


![](2023-03-28-09-08-13.png)

![](2023-03-28-09-14-16.png)

![](2023-03-28-09-31-21.png)
FLEXIBILITY IS IMPORTANT

# Bias - Variancein  Regression 
> If we had 100 seperate training sets, each with 25 data point from the sinusoidal h(x)=sin(2px), **to which we fit the models,w e would see a `variance` in the resulting models.
>
> The concepts of `bias` and `variance` are very important in discussing the model complexity.

## What is variance?
> `Variance` measures how much the preductions for individual datasets vary around the **average**.

## What is bias?
> `Bias` measures how much the prediction **(averaged pver all data sets)** differs from the desired regression function
![](2023-03-30-14-53-07.png)

> Higher order polynomials will have higher variance. 
> 
> Higher order polynomials will have smaller bias. {: #important}

> : _Smaller bias:_ Difference between average fitted line and actual underlying function.

### We can do 2 thing to prevent overfitting
> 1. Use regularization
> 2. Obtain more data

![](2023-03-30-14-57-52.png)

![](2023-03-30-15-07-44.png)

### How can we avoid over-fiting? There are 2 approaches.
> 1. __Early Stopping:__ Stop growing the tree before it perfectly classifies the training data.
> 2. __Pruning:__ Grow full tree, then prune. Cut some and see how it affects our validaton set. _Pruning approach is found more useful in practice._

### ⟶ What if we don't have enough data? We use Cross-Validation. 
![](2023-03-30-15-17-21.png)

![](2023-03-30-15-55-21.png)

![](2023-03-30-16-19-40.png)
![](2023-03-30-16-20-19.png)
![](2023-03-30-16-22-19.png)
![](2023-03-30-16-24-41.png)
<style>
    #important{
        color:red;
        font-weight: 500;
    }
</style>