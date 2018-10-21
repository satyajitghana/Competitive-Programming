require 'json'
require 'stringio'

# Complete the factorial function below.
def factorial(n)
  n == 1 ? 1 : n * factorial(n-1)
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

result = factorial n

fptr.write result
fptr.write "\n"

fptr.close()
