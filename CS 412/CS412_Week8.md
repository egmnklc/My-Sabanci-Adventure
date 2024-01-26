---
Updated at: Tuesday 04-18-2023 | 08:46:57
Date: Tuesday 04-18-2023 | 08:46:59
---


# Introduction To Neural Networks
> One way to achieve artificial intelligence is to mimic human brain.
>
> **`Plasticity`**
> : It means being able to change. Brain changes as we grow and keep on learning.
>
> `100-Step Rule`
> : Operations require at most 100 serial connections.
>
> `A neuron using a threshold activation function will be active if the weighted input it receives (including the bias) is positive.`
> : After it passes the activation level, we also say the neuron is fired.
>
> Assume the neuron takes x₁ and x₂, and outputs y = 2x₁ + 3x₂ + 10.
> : ⟶ bias=10, w₁=2, w₂=3
>

# Artifical Neural Networks
> Computational models that are inspired by the human brain.
>
> 1. They are massively parallel, distributed system, made up of simple processing units (called artifical neurons).
> 2. Synaptic connection strengths among neurons are used to store the acquired knowledge.
> 3. Knowledge is acquired by the network from its environment through a learning process.
>

## When Would You Use Neural Networks (ANNs)?
> `Learning from examples`
> : Labeled or unlabeled
>
> `Adaptivity`
> : Changing the connection strenths to learn things
>
> `Non-linerity`
> : The non-linear activation functions are essential
>
> `Fault tolerance`
> : If one of the neurons or connections is damaged, the whole network still works quite well.
>
> - Thus, there might be better alternatives than classicial solutions that are characterized by:
>   - High dimensionality, `noisy, imprecise or imperfect data`, and
>   a lack of a clearly stated mathametical solution or algorithm.
---
# Artificial Neural Networks (Perceptron)
## Activation Functions
> Also called the squashing function as it `limits the amplitude of the output` of the neuron.
>
> Many types of activation functions are used (**n here means _net input space_**):
> - `Linear` 
>   - a = f(n) = n
> - `Threshold (hardlimiting)`
>   - $$ f(x) = \begin{cases} 1 \quad \text {if n≥ 1}\\ 0 \quad\text {if n < 0} \end{cases} $$
> - `Sigmoid`
>   - a = 1/(1+e⁻ⁿ)
>
## Perceptron (Çok Katmanlı)
> One of the two artificial neuron models.
>
> Uses a hardlimiting (threshold) activation function.
>
> It effectively `seperates the input space into two categories by the hyperplane: `
> $$ w^Tx + b = 0$$

_Note_: The line (bölgeleri birbirinden ayıran çizgimsi şey, bi çizgi de olabilir) that seperates the regions is called `decision hyperplane`. 
: Decision 
---