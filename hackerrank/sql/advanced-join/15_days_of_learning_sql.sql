-- URL: https://www.hackerrank.com/challenges/15-days-of-learning-sql/problem

select table2.submission_date, table2.unique_cnt, table1.hacker_id, hackers.name
from hackers,
     (select *
      from (select submission_date,
                   hacker_id,
                   row_number() over (partition by submission_date order by count desc, hacker_id asc) rn
            from (select submission_date, hacker_id, count(*) as count
                  from submissions
                  group by submission_date, hacker_id
                  having count(*) >= 1
                  order by submission_date))
      where rn = 1) table1,
     (select *
      from (select submission_date, count(distinct hacker_id) unique_cnt
            from (select a.submission_date, v.hacker_id, count(distinct v.submission_date) cnt
                  from (select distinct submission_date from submissions order by 1) a,
                       submissions v
                  where v.submission_date <= a.submission_date
                  group by a.submission_date, v.hacker_id)
            where to_char(submission_date, 'DD') = cnt
            group by submission_date
            order by 1)) table2
where hackers.hacker_id = table1.hacker_id
  and table1.submission_date = table2.submission_date
order by table1.submission_date;
