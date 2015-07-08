def h(s, m)
  p "h: #{s}, #{m}"
  res = s.split("").map do |c|
    [c, (c.ord - 64) % m]
  end
  p res
end

def h2(s, m)
  p "h2, #{s}, #{m}"
  res = s.split("").map do |c|
    [c, 8 - (c.ord - 64) % 8]
  end
  p res
end

h "CHOCOLATE", 5

h "W H I T E C H O C O L A T E".split(" ").join, 11

h "CHOCOLATE", 11
h "PUDDING", 9

h "CHOCOLATE", 11
h2 "CHOCOLATE", 11

h "PUDDING", 9
h2 "PUDDING", 9
