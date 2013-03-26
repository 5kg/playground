# Codeforces 1B
# TAG: Math
# STATUS: AC/2878623/1357483514/Ruby/1765ms/92KB

def rc2xls(r, c)
  a = []
  while c>0
    t = ((c-1)%26+1)
    a << t
    c = (c-t)/26
  end
  "#{a.reverse.reduce("") {|s,i| s += (i+64).chr }}#{r}"
end

def xls2rc(s)
  /(?<c>\D+)(?<r>\d+)/ =~ s
  "R#{r}C#{c.split(//).map(&:ord).reduce(0) {|s, i| s = s*26+i-64 }}"
end

gets.to_i.times do
  puts /R(?<r>\d+)C(?<c>\d+)/ =~ (s = gets) ? rc2xls(r, c.to_i) : xls2rc(s)
end
