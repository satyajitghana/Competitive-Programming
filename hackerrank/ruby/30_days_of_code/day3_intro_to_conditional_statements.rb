require 'json'
require 'stringio'

n = gets.to_i

if n.odd? 
  puts "Weird"
else
  case n
  when 2..5 
    puts "Not Weird"
  when 6..20
    puts "Weird"
  else
    puts "Not Weird"
  end        
end 
