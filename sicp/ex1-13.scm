; Proof: Fib(n) = \frac{(\phi^n - \psi^n)}{\sqrt{5}}
; When n = 1, Fib(1) = 1 = \frac{1+\sqrt{5}}{2} + \frac{1-\sqrt{5}}{2} = 1.
; Assume for all n in {1,2,...,k-1}, Fib(k) = \frac{(\phi^k - \psi^k)}{\sqrt{5}}
; Then Fib(k) = \frac{(\phi^{k-1} - \psi^{k-1})}{\sqrt{5}} + \frac{(\phi^{k-2} - \psi^{k-2})}{\sqrt{5}}
;             = \frac{\frac{\phi^k}{\frac{1}{\phi}+\frac{1}{\phi^2}}+\frac{\psi^k}{\frac{1}{\psi}+\frac{1}{\psi^2}}}{\sqrt{5}}
;             = \frac{(\phi^k - \psi^k)}{\sqrt{5}}
; Therefore, Fib(n) = \frac{(\phi^n - \psi^n)}{\sqrt{5}}.
;
; Since \psi < \frac{1}{2}, Fib(n) is the closest number to \frac{\phi^n}{\sqrt{5}}.
