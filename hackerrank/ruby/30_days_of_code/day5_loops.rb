require 'json'
require 'stringio'

n = gets.to_i

(1..10).each do |i|
    puts "#{n} x #{i} = #{n*i}"
end