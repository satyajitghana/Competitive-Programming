-- URL: https://www.hackerrank.com/challenges/sql-projects/problem

select min(start_date), max(end_date)
from (select start_date,
             end_date,
             start_date - row_number() OVER (order by start_date) rn
      from projects)
group by rn
order by count(*), min(start_date);
