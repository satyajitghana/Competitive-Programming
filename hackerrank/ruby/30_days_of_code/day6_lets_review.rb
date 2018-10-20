def print_weird(term)
  (1..2).each do |step|
    term.chars.each_with_index do |c, i|
      print c if i.even? && step == 1
      print c if i.odd?  && step == 2
    end

    print ' ' if step == 1
  end
end

qtd_of_terms = gets.to_i
terms = []

(1..qtd_of_terms).each do
  terms << gets.strip
end

terms.each do |term|
  print_weird term
  puts ''
end
