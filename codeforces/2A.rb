# Codeforces 2A
# TAG: Easy
# STATUS: AC/3404122/1364215336/Ruby/46ms/100KB

input = []
gets.to_i.times { input << gets }

s = Hash.new(0)
input.each do |i|
  name, score = i.split
  s[name] += score.to_i
end

max = s.values.max

ss = Hash.new(0)
input.each do |i|
  name, score = i.split
  ss[name] += score.to_i
  if ss[name] >= max && s[name] == max
    puts name
    break
  end
end
