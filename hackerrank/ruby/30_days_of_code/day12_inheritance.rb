class Student <Person
  def initialize(firstName, lastName, id, scores)
    super(firstName, lastName, id)
    @scores = scores
  end

  def calculate
    avg = @scores.sum / @scores.size
    case avg
      when 90..100
        'O'
      when 80..89
        'E'
      when 70..79
        'A'
      when 55..69
        'P'
      when 40..54
        'D'
      when 0..39
        'T'
    end
  end
end
