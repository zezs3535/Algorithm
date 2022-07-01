/* Write your PL/SQL query statement below */
select distinct user_id, max(to_char(time_stamp)) last_stamp
from Logins
where to_char(time_stamp, 'YYYY') = '2020'
group by user_id;