def initialize(title, author, price)
  @title = title
  @author = author
  @price = price
end

def display
  puts "Title: #{@title}"
  puts "Author: #{@author}"
  puts "Price: #{@price}"
end