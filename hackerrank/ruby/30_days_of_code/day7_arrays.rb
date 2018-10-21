require 'json'
require 'stringio'

n = gets.to_i

arr = gets.rstrip.split(' ').map(&:to_i)
arr.reverse.each {|e| print e.to_s + ' '}
