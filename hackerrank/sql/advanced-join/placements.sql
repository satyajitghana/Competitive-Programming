-- URL: https://www.hackerrank.com/challenges/placements/problem

select name
from students s
         join packages p on s.id = p.id
         join friends f on p.id = f.id
         join packages pp on pp.id = f.friend_id
where p.salary < pp.salary
order by pp.salary;
