/* Write your PL/SQL query statement below */
select a.name, nvl(sum(b.distance),0) travelled_distance
from Users a left join Rides b
on a.id = b.user_id
group by a.name, b.user_id
order by 2 desc, a.name asc;