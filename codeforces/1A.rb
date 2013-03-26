# Codeforces 1A
# TAG: Math
# NOTE: In programming language with `floored division`(Python, Ruby), `a/b = floor(a/b)`.
#       Therefore `ceiling(a/b) = -(-a/b)`.
# REF: https://en.wikipedia.org/wiki/Modulo_operation
# STATUS: AC/2226629/1348229339/Ruby/108ms/5500KB

n, m, a = gets.split.map(&:to_i)
puts (-n/a)*(-m/a)
