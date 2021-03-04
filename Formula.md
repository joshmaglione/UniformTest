# Coarse fHP of uniform matroid

Suppose $m\geq n$. Then
$$
\begin{aligned}
    \mathsf{cfHP}_{\mathcal{U}_{n, m}}(Y, T) &= \dfrac{1+Y}{1-T} \sum_{k=0}^{n-1}\binom{m-1}{k}Y^k \\
    &\quad + \sum_{\ell=1}^{n-1}\sum_{k=0}^{n-\ell-1} \binom{m-\ell-1}{k} \binom{m}{\ell} \dfrac{(1+Y)^{\ell+1}Y^k T \cdot E_{\ell}(T)}{(1-T)^{\ell+1}}.
\end{aligned} 
$$

To get the numerator, we get everything onto a common denominator:
$$
\begin{aligned}
    \mathcal{N}_{\mathcal{U}_{n,m}}(Y, T) &= (1-T)^{n-1}(1+Y) \sum_{k=0}^{n-1}\binom{m-1}{k}Y^k \\
    &\quad + \sum_{\ell=1}^{n-1}\sum_{k=0}^{n-\ell-1} \binom{m-\ell-1}{k} \binom{m}{\ell} (1+Y)^{\ell+1}Y^k T (1-T)^{n-\ell-1} E_{\ell}(T).
\end{aligned} 
$$

For $\ell\geq 1$, let $E_\ell(T) = \sum_{s=0}^{\ell-1}a_{\ell,s}T^s$. We evaluate at $Y=1$ and simplify:
$$
\begin{aligned}
    \mathcal{N}_{\mathcal{U}_{n,m}}(1, T) &= \left(2\sum_{k=0}^{n-1}\binom{m-1}{k}\right)\left(\sum_{r=0}^{n-1}(-1)^r\binom{n-1}{r}T^r\right) \\
    &\quad + \sum_{\ell=1}^{n-1}2^{\ell+1}\binom{m}{\ell}\left(\sum_{k=0}^{n-\ell-1} \binom{m-\ell-1}{k}\right)\left( \sum_{r=0}^{n-\ell-1}(-1)^r \binom{n-\ell-1}{r}T^{r+1}E_{\ell}(T)\right) \\
    &= \left(2\sum_{k=0}^{n-1}\binom{m-1}{k}\right)\left(\sum_{r=0}^{n-1}(-1)^r\binom{n-1}{r}T^r\right) \\
    &\quad + \sum_{\ell=1}^{n-1}2^{\ell+1}\binom{m}{\ell}\left(\sum_{k=0}^{n-\ell-1} \binom{m-\ell-1}{k}\right)\left( \sum_{r=0}^{n-\ell-1}(-1)^r \binom{n-\ell-1}{r} \sum_{s=0}^{\ell-1} a_{\ell,s} T^{r+s+1}\right)
\end{aligned} 
$$
