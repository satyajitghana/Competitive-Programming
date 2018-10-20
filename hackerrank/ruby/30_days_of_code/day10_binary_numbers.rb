require 'json'
require 'stringio'

n = gets.to_i
puts n.to_s(2).scan(/1*/).max.size
