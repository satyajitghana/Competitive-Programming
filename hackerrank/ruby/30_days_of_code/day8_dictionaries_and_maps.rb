book = {}
gets.chomp.to_i.times do
  name_phone = gets.to_s.strip
  name, phone = name_phone.split(' ')
  book[name] = phone
end

while (line = gets)
  name = line.chomp
  puts book[name] ? "#{name}=#{book[name]}" : 'Not found'
end
