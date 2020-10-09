-- URL: https://www.hackerrank.com/challenges/symmetric-pairs/problem

select distinct f1.x, f1.y
from functions f1
         join functions f2 on (f1.x = f2.y and f1.y = f2.x and f1.rowid != f2.rowid)
where f1.x <= f1.y
order by f1.x;
