require 'json'
require 'stringio'

arr = []
6.times do
  arr.push gets.strip.split.map(&:to_i)
end

sums = []
4.times do |line|
  4.times do |column|
    soma = arr[line    ][column] + arr[line    ][column + 1] + arr[line    ][column + 2] +
                                   arr[line + 1][column + 1] +
           arr[line + 2][column] + arr[line + 2][column + 1] + arr[line + 2][column + 2]
    sums << soma
  end
end

puts sums.max
